# Hackypady

Hackypady is a compact, highly-customizable macro keyboard built around the Seeed XIAO RP2040.  
It combines a 0.91" OLED display, a rotary encoder, 3× RGB LEDs, and a 9-button matrix (3×3).  
Designed for hobbyists and makers who want a small, programmable input device for shortcuts, media control, macros or external automation.

## Key features
- 3×3 button matrix (9 buttons) using 6 pins (diode matrix)
- Rotary encoder for volume/pitch control
- 3× SK6812 Mini RGB LEDs for visual feedback and volume indicators
- 0.91" OLED (I2C) for status / layers / indicators
- Seeed XIAO RP2040 (tiny RP2040 form factor) — low-power and fast
- Fully customizable firmware and keymaps
- Lightweight and easy to scale (add more keys/layers)

## Bill of Materials (suggested)
- 1 × Seeed XIAO RP2040 (or compatible RP2040 board)
- 1 × 0.91" OLED (I2C, 128×32 or 128×64)
- 1 × Rotary encoder (with push)
- 9 × push buttons (mechanical or tactile)
- 9 × diodes (e.g., 1N4148) if using matrix scanning
- 3 × SK6812 Mini RGB LEDs (or compatible addressable LEDs)
- Prototyping PCB / perfboard or custom PCB (see [PCB design](Hackypady/PCB%20design/))
- Wires, headers, enclosure as desired (see [3D objects](Hackypady/3D%20objects/) for enclosure designs)

## Suggested wiring / pinout (example)
Adjust pins to match your board layout and firmware pin definitions. The current [Firmware.cpp](Hackypady/Firmware.cpp) uses:
- OLED (I2C): SDA -> SDA pin, SCL -> SCL pin (I2C address 0x3C)
- Rotary encoder: CLK -> GPIO 10, DT -> GPIO 8
- RGB LEDs: Data -> GPIO A3 (3× SK6812 Mini LEDs)
- Matrix rows: GPIO 11, 6, 9
- Matrix columns: GPIO A0, A1, A2
- GND and VCC: common power rails (3.3V)

Tip: identify your XIAO RP2040 pin labels on the silk/board and change the firmware pin definitions to match.

## Assembly
1. Mount the OLED and encoder where visible/easy to reach.
2. Arrange the 9 switches in your preferred layout (3×3 grid is common).
3. Wire the switches into a diode matrix (each switch in series with a diode) to allow scanning with fewer pins.
4. Connect the RGB LEDs in series (data out of one LED to data in of the next).
5. Connect the encoder, OLED, and LEDs to the RP2040 according to the pinout you plan to use.
6. Double-check power (3.3V) and ground connections before powering.

3D printable enclosure designs are available in the [3D objects](Hackypady/3D%20objects/) directory, and custom PCB designs are available in [PCB design](Hackypady/PCB%20design/).

## Firmware / Software
This repository includes a working Arduino firmware implementation in [Firmware.cpp](Hackypady/Firmware.cpp) that demonstrates:
- 3×3 button matrix scanning with debouncing
- Rotary encoder for volume control (sends media keys)
- RGB LED volume indicators (green/yellow/red based on volume level)
- OLED display showing volume level and app names
- Each button opens a different application (Browser, VSCode, Spotify, Discord, Terminal, File Manager, Email, Calculator, Settings)

### Using the included firmware:
1. Clone this repository locally.
2. Open [Firmware.cpp](Hackypady/Firmware.cpp) in Arduino IDE or PlatformIO.
3. Install required libraries:
   - Adafruit_GFX
   - Adafruit_SSD1306
   - Adafruit_NeoPixel
   - Keyboard (HID)
   - Consumer (for media keys)
4. Select "Seeed XIAO RP2040" as your board.
5. Adjust pin definitions if your wiring differs from the default pinout.
6. Upload to the board and test!

### Customization options:
You can also implement custom firmware using:
- CircuitPython (for quick prototyping and fast iteration)
- Arduino / RP2040 Arduino cores (C++ with libraries) — included firmware uses this
- PlatformIO projects or custom C/C++ firmware

Example behavior ideas:
- Single key actions (short press)
- Hold or layer keys (modifier + key on hold)
- Encoder rotation = volume up/down, encoder press = mute or layer toggle
- OLED shows current layer or active macro
- RGB LEDs as status indicators or animations

## Customization
- Add layers to expand functionality (Fn layer for media, emojis, macros, etc.)
- Increase the matrix size and add diodes if you want more keys
- Replace OLED with a larger display or RGB indicators
- Add macros to call external scripts (via serial / USB HID) for automation

## Troubleshooting
- OLED not showing:
  - Verify SDA/SCL wiring and I2C address; try an I2C scanner sketch.
  - Check that the I2C address in firmware (0x3C) matches your OLED module.
- Some keys read incorrectly:
  - Check diode orientation and matrix wiring; make sure rows/columns are defined correctly in firmware.
- Encoder noisy or double-steps:
  - Add debouncing in software or a small capacitor if needed.
- RGB LEDs not lighting up:
  - Verify data pin connection and power supply (SK6812 LEDs need stable 3.3V or 5V).
  - Check that LED_PIN in firmware matches your wiring.
  - Ensure LEDs are connected in the correct direction (data in -> data out).

## Contributing
Contributions are welcome! Please:
1. Open an issue to discuss major changes or new features.
2. Fork the repo and submit a pull request with a clear description and screenshots or diagrams where applicable.
3. Include code comments and update this README if you add new wiring, firmware examples or parts lists.

## Repository Contents
- **[Firmware.cpp](Hackypady/Firmware.cpp)** - Arduino firmware with volume control and app launcher functionality
- **[3D objects/](Hackypady/3D%20objects/)** - STEP files for 3D printable enclosure designs
- **[PCB design/](Hackypady/PCB%20design/)** - KiCad project files for custom PCB

## Roadmap / Ideas
- ✅ ~~Add example firmware~~ - Arduino C++ firmware included
- ✅ ~~Provide a PCB layout and printable enclosure design~~ - Available in repository
- Add alternative firmware: CircuitPython and PlatformIO templates
- Add pre-configured keymaps and OLED UI examples
- Add automated build/CI for firmware
- Add assembly instructions with photos/diagrams

## License
Choose a license for the project (e.g., MIT, Apache-2.0) and add a LICENSE file. If you want, I can add an MIT license file for you.

## Credits
Built with RP2040 community support and open-source libraries. Thanks to everyone who shares code and hardware designs.

Feel free to adapt, extend and share your improvements!
