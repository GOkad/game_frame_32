# C++ Game Frame 32 Changelog

## Version 0.2.0 [28-02-23]
### **`It's my mental ilness and I choose the coping mechanism`**
### Added
- Register/Trigger `Callback event`
### Changed
- ESP32 -> ESP8266
> **Reason**: The `WiFi.h` and `ESPAsyncTCP.h` take less space in `FLASH`. <br>
> **Note**: WiFi will **`NOT`** run on `Core 0` <br>
> **Note**: Less `RAM` storage
- Engine32: Re-design
---
## Version 0.1.0 [26-02-23]
### **`Core & Controller`**
### Added
- `Controller` class
- `JSONBuilder` class
### Changed
- Renamed JavaScript Engine dir: `engine32` -> `m32`
### Deleted
- Pinning `Controller` task to `core 1` because it's redundant. `Engine` runs on `core 1` as `core 0` is used for `Wifi`.
---
## Version 0.0.1 [25-02-23]
### **`Core functionality [WIP]`**
### Added
- `Engine32` class
- `AsyncWebServer` communication
- `Routes`:
 >- `[GET] /` - returns index HTML with `m32.js` engine
 >- TODO: `[GET] /events` - returns the current EventBuffer 
---
## Version 0.0.0 [25-02-23]
### **`Initial Setup`**
