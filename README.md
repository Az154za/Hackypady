# Hackypady

**A compact, programmable macro keyboard with OLED display and RGB lighting**

Hackypady is a DIY macro keyboard built around the Seeed XIAO RP2040 microcontroller. This project combines a 0.91" OLED display, a rotary encoder, 3× SK6812 Mini RGB LEDs, and a 9-button matrix (3×3) in a compact form factor perfect for desktop productivity.

Designed for hobbyists, makers, and power users who want a fully programmable input device for shortcuts, media control, application launching, and custom automation workflows.

## 🎬 Quick Start

1. **Get the hardware** - Order components from the Bill of Materials below
2. **Build it** - Follow the Assembly section to wire everything up
3. **Install CircuitPython & KMK** - Flash CircuitPython and install KMK firmware
4. **Customize** - Edit `code.py` to configure keymaps, layers, and RGB effects

## ✨ Key Features

**Hardware:**
- 🔘 **9-button matrix** (3×3 layout) with diode scanning
- 🔄 **Rotary encoder** for volume/pitch control and navigation
- 💡 **3× SK6812 Mini RGB LEDs** for visual feedback and status indicators
- 📺 **0.91" OLED display** (128×32/64, I2C) for real-time status and layer information
- ⚡ **Seeed XIAO RP2040** - Powerful dual-core Cortex-M0+ processor in a tiny form factor

**Software:**
- 🐍 **KMK Firmware** - Python-based keyboard firmware with CircuitPython
- 🔧 **Fully customizable** - No compilation needed, edit code on the fly
- 🎯 **Application launcher** - Direct shortcuts to your most-used programs
- 🔊 **Media controls** - Volume adjustment via rotary encoder
- 🎨 **Dynamic RGB feedback** - Built-in animations and custom effects
- 📊 **Multi-layer support** - Expand functionality with layer switching
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
Adjust pins to match your board layout and KMK configuration. Example pinout for KMK setup:
- OLED (I2C): SDA -> SDA pin, SCL -> SCL pin (I2C address 0x3C)
- Rotary encoder: CLK -> pin 10, DT -> pin 8
- RGB LEDs: Data -> pin A3 (3× SK6812 Mini LEDs)
- Matrix rows: pins 11, 6, 9
- Matrix columns: pins A0, A1, A2
- GND and VCC: common power rails (3.3V)

**Tip:** In KMK's `code.py`, you'll define these pins using CircuitPython's `board` module (e.g., `board.D10`, `board.A0`). Check your XIAO RP2040 pinout diagram to match the correct pin names.

## 🔨 Assembly
1. Mount the OLED and encoder where visible/easy to reach.
2. Arrange the 9 switches in your preferred layout (3×3 grid is common).
3. Wire the switches into a diode matrix (each switch in series with a diode) to allow scanning with fewer pins.
4. Connect the RGB LEDs in series (data out of one LED to data in of the next).
5. Connect the encoder, OLED, and LEDs to the RP2040 according to the pinout you plan to use.
6. Double-check power (3.3V) and ground connections before powering.

3D printable enclosure designs are available in the [3D objects](Hackypady/3D%20objects/) directory, and custom PCB designs are available in [PCB design](Hackypady/PCB%20design/).

## 💻 Firmware / Software
This project uses **KMK Firmware** - a feature-rich keyboard firmware written in CircuitPython. KMK provides:
- 3×3 button matrix scanning with built-in debouncing
- Rotary encoder support for volume control and navigation
- RGB LED control with animations and effects
- Multiple layers and advanced key behaviors
- Media keys and consumer control
- Easy customization without compiling

### Getting Started with KMK:
1. **Install CircuitPython** on your Seeed XIAO RP2040:
   - Download the latest CircuitPython UF2 for XIAO RP2040 from [circuitpython.org](https://circuitpython.org/board/seeeduino_xiao_rp2040/)
   - Enter bootloader mode (double-press reset button)
   - Copy the UF2 file to the RPI-RP2 drive
   
2. **Install KMK**:
   - Download KMK from [KMK GitHub](https://github.com/KMKfw/kmk_firmware)
   - Copy the `kmk` folder to the CIRCUITPY drive
   - Copy the `boot.py` if needed for advanced features

3. **Configure your keyboard**:
   - Create a `code.py` file on the CIRCUITPY drive
   - Define your pin mappings, matrix, and keymap
   - Customize RGB effects and encoder behavior
   - Save and the keyboard will automatically reload

### Alternative Firmware Options:
You can also use:
- **Arduino / C++** - For custom implementations with Arduino libraries
- **PlatformIO** - For advanced C/C++ development with better tooling
- **QMK** - Popular open-source firmware (requires C knowledge)

### KMK Features You Can Use:
- **Layers** - Multiple key layouts accessible with layer switching
- **Tap/Hold keys** - Different actions for tap vs hold
- **Macros** - Record complex key sequences
- **Encoder actions** - Volume control, scrolling, layer switching
- **RGB animations** - Rainbow, breathing, reactive effects, and custom patterns
- **Leader keys** - Vim-style key sequences
- **Combos** - Activate shortcuts by pressing multiple keys together

## 🎨 Customization Ideas
- **Add layers** - KMK supports unlimited layers for media controls, emojis, macros, etc.
- **Custom macros** - Define complex key sequences with KMK's macro system
- **RGB effects** - Use built-in animations or create your own with Python
- **Encoder modes** - Switch between volume, scrolling, or layer navigation
- **Gaming profiles** - Set up game-specific macros and rapid-fire keys
- **Streaming control** - Configure OBS shortcuts, mute controls, and scene switching
- **OLED integration** - Display current layer, WPM, or custom graphics (requires KMK extensions)
- **Tap dance** - Multiple actions on a single key based on tap count

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
| **3D Models** | STEP files for 3D printable enclosure (upper case, lower case, and full assembly) | [3D objects/](Hackypady/3D%20objects/) |
| **PCB Design** | Complete KiCad project files for custom PCB fabrication | [PCB design/](Hackypady/PCB%20design/) |

**Note:** The firmware uses KMK - download it from the [KMK GitHub repository](https://github.com/KMKfw/kmk_firmware) and configure it for your build.

## 🚀 Roadmap & Future Ideas

**Completed:**
- ✅ KMK/CircuitPython firmware implementation
- ✅ PCB layout design (KiCad files)
- ✅ 3D printable enclosure models

**In Progress / Planned:**
- 🔄 Pre-configured KMK keymap examples for different use cases
- 🔄 Sample `code.py` configurations with comments
- 🔄 OLED display integration examples
- 🔄 Assembly guide with step-by-step photos
- 🔄 BOM with direct purchase links
- 🔄 Custom RGB animation examples
- 🔄 Web-based configuration tool (via KMK's web UI)
- 🔄 Alternative QMK firmware port

## 📄 License

This project is open source. Feel free to use, modify, and distribute this project for personal or commercial purposes. 

If you'd like to add a formal license (MIT, Apache-2.0, GPL, etc.), please add a LICENSE file to the repository.

## 💝 Credits & Acknowledgments

Built with love using:
- **KMK Firmware Team** - Amazing Python-based keyboard firmware
- **CircuitPython / Adafruit** - Making hardware programming accessible
- **Seeed Studio** - XIAO RP2040 board
- **RP2040 Community** - Support and inspiration
- **Open Source Contributors** - Everyone who shares their designs and code

---

**Made with ❤️ for makers and keyboard enthusiasts**

Feel free to adapt, extend, and share your improvements! If you build one, we'd love to see it! Share your build on social media with #Hackypady.
