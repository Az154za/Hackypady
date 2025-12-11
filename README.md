# Hackypady

**A compact, programmable macro keyboard with OLED display and RGB lighting**

Hackypady is a DIY macro keyboard built around the Seeed XIAO RP2040 microcontroller. This project combines a 0.91" OLED display, a rotary encoder, 3× SK6812 Mini RGB LEDs, and a 9-button matrix (3×3) in a compact form factor perfect for desktop productivity.

Designed for hobbyists, makers, and power users who want a fully programmable input device for shortcuts, media control, application launching, and custom automation workflows.

## 🎬 Quick Start

1. **Get the hardware** - Order components from the Bill of Materials below
2. **Build it** - Follow the Assembly section to wire everything up
3. **Flash firmware** - Upload the included Arduino firmware to your XIAO RP2040
4. **Customize** - Modify keymaps and RGB effects to match your workflow

## ✨ Key Features

**Hardware:**
- 🔘 **9-button matrix** (3×3 layout) with diode scanning
- 🔄 **Rotary encoder** for volume/pitch control and navigation
- 💡 **3× SK6812 Mini RGB LEDs** for visual feedback and status indicators
- 📺 **0.91" OLED display** (128×32/64, I2C) for real-time status and layer information
- ⚡ **Seeed XIAO RP2040** - Powerful dual-core Cortex-M0+ processor in a tiny form factor

**Software:**
- 🔧 **Fully customizable firmware** with Arduino/C++ implementation included
- 🎯 **Application launcher** - Direct shortcuts to your most-used programs
- 🔊 **Media controls** - Volume adjustment via rotary encoder
- 🎨 **Dynamic RGB feedback** - Color-coded volume levels and button press animations
- 📊 **OLED interface** - Visual feedback for actions and system status
- 🔌 **USB HID** - Works as a standard keyboard device, no drivers needed

## 🛠️ Bill of Materials
- 1 × Seeed XIAO RP2040 (or compatible RP2040 board)
- 1 × 0.91" OLED (I2C, 128×32 or 128×64)
- 1 × Rotary encoder (with push)
- 9 × push buttons (mechanical or tactile)
- 9 × diodes (e.g., 1N4148) if using matrix scanning
- 3 × SK6812 Mini RGB LEDs (or compatible addressable LEDs)
- Prototyping PCB / perfboard or custom PCB (see [PCB design](Hackypady/PCB%20design/))
- Wires, headers, enclosure as desired (see [3D objects](Hackypady/3D%20objects/) for enclosure designs)

## 🔌 Wiring & Pinout
Adjust pins to match your board layout and firmware pin definitions. The current [Firmware.cpp](Hackypady/Firmware.cpp) uses:
- OLED (I2C): SDA -> SDA pin, SCL -> SCL pin (I2C address 0x3C)
- Rotary encoder: CLK -> pin 10, DT -> pin 8
- RGB LEDs: Data -> pin A3 (3× SK6812 Mini LEDs)
- Matrix rows: pins 11, 6, 9
- Matrix columns: pins A0, A1, A2
- GND and VCC: common power rails (3.3V)

Tip: identify your XIAO RP2040 pin labels on the silk/board and change the firmware pin definitions to match.

## 🔨 Assembly
1. Mount the OLED and encoder where visible/easy to reach.
2. Arrange the 9 switches in your preferred layout (3×3 grid is common).
3. Wire the switches into a diode matrix (each switch in series with a diode) to allow scanning with fewer pins.
4. Connect the RGB LEDs in series (data out of one LED to data in of the next).
5. Connect the encoder, OLED, and LEDs to the RP2040 according to the pinout you plan to use.
6. Double-check power (3.3V) and ground connections before powering.

3D printable enclosure designs are available in the [3D objects](Hackypady/3D%20objects/) directory, and custom PCB designs are available in [PCB design](Hackypady/PCB%20design/).

## 💻 Firmware / Software
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
   - Keyboard (from Arduino HID library)
   - Consumer (Consumer Control library for media keys)
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

## 🎨 Customization Ideas
- **Add layers** - Expand functionality with Fn layers for media controls, emojis, macros, etc.
- **Scale up** - Increase the matrix size and add more diodes for additional keys
- **Display upgrade** - Replace OLED with a larger display or add more RGB indicators
- **Automation** - Create macros that call external scripts via serial / USB HID
- **Gaming profiles** - Configure game-specific macros and shortcuts
- **Streaming control** - Add OBS scene switching, mute controls, and more

## 🔧 Troubleshooting
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

## 🤝 Contributing
Contributions are welcome! Please:
1. Open an issue to discuss major changes or new features.
2. Fork the repo and submit a pull request with a clear description and screenshots or diagrams where applicable.
3. Include code comments and update this README if you add new wiring, firmware examples or parts lists.

## 📁 Repository Contents

This repository includes everything you need to build your own Hackypady:

| Component | Description | Location |
|-----------|-------------|----------|
| **Firmware** | Arduino C++ implementation with volume control, RGB animations, and app launcher | [Firmware.cpp](Hackypady/Firmware.cpp) |
| **3D Models** | STEP files for 3D printable enclosure (upper case, lower case, and full assembly) | [3D objects/](Hackypady/3D%20objects/) |
| **PCB Design** | Complete KiCad project files for custom PCB fabrication | [PCB design/](Hackypady/PCB%20design/) |

## 🚀 Roadmap & Future Ideas

**Completed:**
- ✅ Arduino C++ firmware with full functionality
- ✅ PCB layout design (KiCad files)
- ✅ 3D printable enclosure models

**In Progress / Planned:**
- 🔄 Alternative firmware implementations (CircuitPython, QMK-inspired)
- 🔄 Pre-configured keymap templates for different use cases
- 🔄 Advanced OLED UI with animations and menus
- 🔄 Assembly guide with step-by-step photos
- 🔄 BOM with direct purchase links
- 🔄 Automated firmware builds and releases
- 🔄 Web-based configuration tool
- 🔄 Support for additional LED patterns and effects

## 📄 License

This project is open source. Feel free to use, modify, and distribute this project for personal or commercial purposes. 

If you'd like to add a formal license (MIT, Apache-2.0, GPL, etc.), please add a LICENSE file to the repository.

## 💝 Credits & Acknowledgments

Built with love using:
- **Seeed Studio** - XIAO RP2040 board
- **Adafruit** - Amazing display and NeoPixel libraries
- **RP2040 Community** - Support and inspiration
- **Open Source Contributors** - Everyone who shares their designs and code

---

**Made with ❤️ for makers and keyboard enthusiasts**

Feel free to adapt, extend, and share your improvements! If you build one, we'd love to see it! Share your build on social media with #Hackypady.
