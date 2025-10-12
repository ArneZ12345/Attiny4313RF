## Quick orientation

This repository is a small embedded transmitter for ATtiny/Arduino that reads a DHT sensor and a pair of DIP/voltage inputs and transmits a formatted message over a simple 433MHz-style RF link.

Files of interest:
- `Transmitter.ino` / `TinyRF_TX.cpp` — main setup/loop and transmit logic.
- `TinyDHT.*` — DHT sensor reader (integer-based Adafruit port).
- `Settings.h` — single source of feature flags, pin assignments, and protocol settings (bitrate, CRC vs checksum, sequencer, etc.).
- `TinyRF.h` — transmit/CRC constants and data-rate presets (magic timing numbers live here).
- `TinyRF_TX.h/.cpp` — payload framing (preamble, start pulse, len, error-check, seq), byte-level pulse emission.
- `Main.cpp`, `Transmit.cpp` — high-level glue: collecting sensor values, building `message[]` and calling `send()`.

## Big picture architecture (what to know quickly)
- Single MCU transmitter: read sensors -> build CSV message -> call `send((byte*)message, strlen(message)+1)`.
- TinyRF encoding is implemented purely with timed digital writes (`transmitByte`, delayMicroseconds). Timing parameters are set via macros in `Settings.h` and constants in `TinyRF.h`.
- Error checking and sequencing are configurable in `Settings.h` (CRC vs checksum vs none, and `TRF_SEQ_DISABLED`). These affect `TinyRF_TX.cpp` behavior.
- The code targets ATtiny/Arduino class MCUs; a number of compile-time guards and comments assume constrained flash/RAM.

## Project-specific conventions and gotchas
- Single header `Settings.h` is authoritative for all hardware pinouts and protocol features. Change it to affect behavior across the codebase.
- Only enable one option when multiple alternatives are provided in `Settings.h` (the file warns to comment/uncomment options, don't define multiple presets at once).
- Message framing: messages are sent as C-style strings (`char message[32]`) and the code uses `strlen(message)+1` to include the terminating \0. Keep messages short (recommended <32 bytes).
- Timing magic: do not change the numeric constants inside `TinyRF.h` unless you know the MCU oscillator calibration and RF module tolerances.

## Useful examples (do this when editing code)
- To add a new sensor value to the transmitted CSV: add the variable to `TRANSMIT_BUFFER[]` in `Settings.h`/`Main` area, populate it in `CHECK_DIPSW()` or a new helper, then ensure `message` formatting in `CHECK_DIPSW()` includes it.
- To change pins: update `DHTPIN`, `DIPPIN_*`, `READ_VOLTAGE_PIN_*`, and `TRF_TX_PIN` in `Settings.h` and rebuild.
- To switch error checking: toggle `TRF_ERROR_CHECKING_CRC` / `TRF_ERROR_CHECKING_CHECKSUM` / `TRF_ERROR_CHECKING_NONE` in `Settings.h`. CRC increases flash usage but is preferred for reliability.

## Build & debug workflows
- This is an Arduino/AVR project. Use the Arduino IDE or a CLI tool such as `arduino-cli` or `platformio` targeting ATtiny or the specific board used. Example (arduino-cli):

```powershell
arduino-cli compile --fqbn <board_fqbn> Transmitter
arduino-cli upload -p COMx --fqbn <board_fqbn> Transmitter
```

- The repo itself contains only source files; there is no Makefile or platformio.ini. If you add one, keep `Settings.h` as the central config.
- For local debugging on non-ATtiny boards, the code enables serial debug macros if `__AVR_ATtiny13__` is not defined; define `DEBUG` in `TinyRF.h` to enable Serial prints on a larger Arduino.

## Testing assumptions and constraints
- Timing uses `delayMicroseconds()` and digitalWrite; the comments note this yields ~4–50us timing errors depending on platform and interrupts. Expect the receiver to tolerate these errors; don't reduce pulse periods without testing both TX and RX.
- Message size and repetition: `TRF_RX_BUFFER_SIZE` and `TRF_MAX_MSG_LEN` govern safe message lengths. `sendMulti()` stores all repetitions in receiver buffer; make sure `TRF_RX_BUFFER_SIZE` is large enough when changing repetition counts.

## When editing: safety checklist for AI agents
- Always reference `Settings.h` when changing pins/protocol flags.
- Preserve the existing message formation: code uses CSV in `CHECK_DIPSW()` and calls `send((byte*)message, strlen(message)+1)` in `DHT_TRANSMIT_VALUES()` (`Transmit.cpp`).
- Don't change timing constants in `TinyRF.h` lightly. If required, annotate why and run live integration tests with the receiver.
- If you add heap/large arrays, be careful: target MCUs have very limited RAM. Prefer small statically sized buffers (`message[32]`) and avoid dynamic allocation.

## Where to look for examples / follow-ups
- `Transmitter.ino` and `TinyRF_TX.cpp` for transmit flow.
- `TinyDHT.*` for sensor read patterns (blocking, with 2s minimum interval logic).
- `Settings.h` for all feature flags. Reference comments there for bitrate and EOT choices.

If anything above is unclear or you want me to include more examples (e.g., exact Arduino CLI fqbn for your board or a `platformio.ini` template), tell me what board you're targeting and I'll iterate.
