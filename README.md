<div align="center">

# 🎹 Hackypady

**A Compact, Highly-Customizable Macro Keyboard for Makers**

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Contributions Welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg)](CONTRIBUTING.md)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)](CONTRIBUTING.md)
[![Made with Love](https://img.shields.io/badge/Made%20with-%E2%9D%A4-red.svg)]()

*Transform your workflow with a DIY programmable macro keyboard built on the powerful Seeed XIAO RP2040*

[Features](#-key-features) • [Getting Started](#-quick-start) • [Build Guide](#-assembly) • [Contributing](CONTRIBUTING.md) • [Community](#-community)

---

</div>

## 📖 About

Hackypady is a compact, highly-customizable macro keyboard built around the Seeed XIAO RP2040.  
It combines a 0.91" OLED display, a rotary encoder, and a 9-button matrix (3×3) using only 6 GPIO pins.  
Designed for hobbyists and makers who want a small, programmable input device for shortcuts, media control, macros or external automation.

### Why Hackypady?

- 🎯 **Perfect for beginners**: Simple design, easy to build, great learning project
- ⚡ **Fast & responsive**: Powered by RP2040 dual-core processor
- 🎨 **Fully customizable**: Change keymaps, add layers, create your own macros
- 💰 **Budget-friendly**: Affordable components, optional 3D-printed case
- 🔧 **Open source**: Hardware, firmware, and designs all available

## ✨ Key Features

| Feature | Description |
|---------|-------------|
| 🎮 **9-Button Matrix** | 3×3 grid using efficient diode matrix scanning (only 6 GPIO pins) |
| 🔄 **Rotary Encoder** | Volume control, scrolling, or custom functions with push button |
| 📺 **OLED Display** | 0.91" I2C display for visual feedback and status indicators |
| 🚀 **RP2040 Powered** | Seeed XIAO RP2040 - dual-core, low-power, blazing fast |
| 🌈 **RGB LEDs** | 3x SK6812 Mini LEDs for visual indicators (optional) |
| 🎨 **Customizable** | Fully programmable keymaps, layers, and macros |
| 🔌 **USB-C** | Modern connectivity with HID support |
| 📦 **Compact** | Tiny form factor perfect for any desk setup |

## 🚀 Quick Start

Ready to build your own Hackypady? Here's what you need to get started:

### Prerequisites
- Basic soldering skills
- USB-C cable
- Arduino IDE or PlatformIO installed
- (Optional) 3D printer for custom enclosure

### Quick Setup
1. **Gather components** - See [Bill of Materials](#-bill-of-materials) below
2. **Assemble hardware** - Follow the [Assembly Guide](#-assembly)
3. **Flash firmware** - Upload the Arduino sketch from `Hackypady/Firmware.cpp`
4. **Customize** - Edit keymaps and create your perfect macro pad!

## 🛠️ Bill of Materials

| Component | Quantity | Notes | Est. Cost |
|-----------|----------|-------|-----------|
| Seeed XIAO RP2040 | 1 | Main microcontroller | $5-7 |
| 0.91" OLED Display | 1 | I2C, 128×32 or 128×64 | $3-5 |
| Rotary Encoder | 1 | With push button (EC11) | $1-2 |
| Mechanical Switches | 9 | Cherry MX or similar | $5-10 |
| Diodes (1N4148) | 9 | For matrix scanning | $1 |
| SK6812 Mini RGB LEDs | 3 | Optional, for indicators | $2-3 |
| PCB / Perfboard | 1 | Custom PCB files included | $5-10 |
| Keycaps | 9 | Your choice of style | $5-15 |
| Enclosure | 1 | 3D print files included | $2-5 |
| Misc. | - | Wires, headers, solder | $3-5 |
| **Total** | | | **~$30-60** |

> 💡 **Tip**: All electronic components are commonly available on AliExpress, Amazon, or electronics hobby stores.

## 📌 Pinout Reference

Default pin configuration (customize in firmware as needed):

| Component | Pin | Notes |
|-----------|-----|-------|
| **Button Matrix** |
| Row 0 | GPIO 11 | Connect via diodes |
| Row 1 | GPIO 6 | Connect via diodes |
| Row 2 | GPIO 9 | Connect via diodes |
| Column 0 | GPIO A0 (26) | Input with pullup |
| Column 1 | GPIO A1 (27) | Input with pullup |
| Column 2 | GPIO A2 (28) | Input with pullup |
| **Rotary Encoder** |
| CLK | GPIO 10 | Encoder A phase |
| DT | GPIO 8 | Encoder B phase |
| SW | (Optional) | Push button |
| **OLED Display** |
| SDA | I2C SDA | Typically GPIO 4 |
| SCL | I2C SCL | Typically GPIO 5 |
| **RGB LEDs** |
| Data | GPIO A3 (29) | SK6812 data line |
| **Power** |
| VCC | 3.3V or 5V | Check component specs |
| GND | GND | Common ground |

> 💡 **Tip**: Verify your XIAO RP2040 pinout diagram and adjust firmware definitions to match your wiring.

## 🔧 Assembly

### Step-by-Step Build Guide

#### 1. **Prepare Your Workspace**
   - Clean, well-lit area
   - Soldering iron (temperature controlled recommended)
   - Wire cutters, strippers
   - Multimeter for testing

#### 2. **PCB Assembly** (if using custom PCB)
   - Solder diodes first (watch polarity! Cathode to columns)
   - Install switches in the 3×3 grid
   - Solder the Seeed XIAO RP2040
   - Add OLED and rotary encoder
   - Optionally add SK6812 LEDs

#### 3. **Wiring** (if using perfboard/breadboard)
   - Create the 3×3 button matrix with diodes
   - Each switch connects to a diode in series
   - Connect rows to GPIO pins 11, 6, 9
   - Connect columns to GPIO pins A0, A1, A2
   - Wire OLED: SDA/SCL to I2C pins
   - Wire encoder: CLK→Pin 10, DT→Pin 8
   - Wire LEDs: Data→Pin A3

#### 4. **Testing**
   - Connect USB-C cable
   - Check for shorts with multimeter
   - Flash test firmware
   - Verify each button and encoder works

#### 5. **Enclosure** (Optional)
   - 3D print the case files from `Hackypady/3D objects/`
   - Install assembled PCB
   - Secure with screws or adhesive
   - Add rubber feet for stability

> 📸 **Show us your build!** Share photos of your completed Hackypady in the [Discussions](https://github.com/Az154za/Hackypady/discussions) section!

## 💻 Firmware & Software

### Firmware Options

Hackypady is firmware-agnostic and supports multiple development platforms:

| Platform | Difficulty | Best For |
|----------|-----------|----------|
| **Arduino** | ⭐ Beginner | Quick setup, great libraries |
| **PlatformIO** | ⭐⭐ Intermediate | Advanced features, better tooling |
| **CircuitPython** | ⭐ Beginner | Rapid prototyping, Python lovers |
| **Custom C/C++** | ⭐⭐⭐ Advanced | Maximum control and optimization |

### Flashing the Firmware

#### Using Arduino IDE (Recommended for beginners)

1. **Install Arduino IDE**
   ```bash
   # Download from: https://www.arduino.cc/en/software
   ```

2. **Add RP2040 Board Support**
   - Go to File → Preferences
   - Add to "Additional Board Manager URLs":
     ```
     https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json
     ```
   - Install "Raspberry Pi Pico/RP2040" boards from Board Manager

3. **Install Required Libraries**
   - Adafruit_GFX
   - Adafruit_SSD1306
   - Adafruit_NeoPixel
   - Keyboard (built-in)

4. **Configure & Upload**
   - Open `Hackypady/Firmware.cpp`
   - Select Board: "Seeed XIAO RP2040"
   - Select Port: Your device's COM port
   - Click Upload! ⚡

### Customizing Keymaps

Edit the `handleButtonPress()` function in the firmware to customize what each button does:

```cpp
case 1:
  openApp("Browser");  // Change to your preferred app
  break;
```

**Example Use Cases:**
- 🎵 Media controls (play, pause, skip, volume)
- 🚀 Application launchers
- 📝 Text macros and snippets
- 🎨 Creative software shortcuts
- 🎮 Gaming macros
- 💬 Discord/Slack emojis and quick replies

## 🎨 Customization Ideas

The sky's the limit! Here are some popular modifications:

### Software Customization
- ⚡ **Add Layers**: Implement Fn key for secondary functions (media, emojis, macros)
- 🎯 **Custom Macros**: Create complex key sequences and delays
- 🌈 **LED Animations**: Program RGB effects for different states
- 📊 **Display Widgets**: Show system stats, time, or custom graphics on OLED

### Hardware Modifications
- 🔢 **More Keys**: Expand to 4×4 or larger matrix
- 🖥️ **Bigger Display**: Upgrade to 1.3" or even color TFT
- 🎨 **RGB Underglow**: Add LED strips for desk lighting
- 🔊 **Haptic Feedback**: Add vibration motor for tactile response
- 🎚️ **Extra Encoders**: Multiple encoders for fine control

### Creative Applications
- 🎬 **Video Editing**: Shortcuts for Premiere, DaVinci Resolve
- 🎨 **Digital Art**: Brush presets for Photoshop, Procreate
- 🎵 **Music Production**: Transport controls for DAWs
- 📹 **Streaming**: Scene switching for OBS, sound effects
- 🎮 **Gaming**: Macro combos, inventory management

## 🔍 Troubleshooting

### Common Issues & Solutions

<details>
<summary><b>OLED display not showing anything</b></summary>

- ✅ Verify SDA/SCL wiring (check I2C pins on your board)
- ✅ Check I2C address (use I2C scanner sketch - usually 0x3C or 0x3D)
- ✅ Ensure power supply is 3.3V or 5V (check OLED specs)
- ✅ Try different I2C pull-up resistors if using long wires
</details>

<details>
<summary><b>Keys not registering or registering incorrectly</b></summary>

- ✅ Check diode orientation (cathode should point to columns)
- ✅ Verify row/column pin definitions in firmware match your wiring
- ✅ Test with multimeter in continuity mode
- ✅ Increase debounce delay in firmware if keys are chattering
</details>

<details>
<summary><b>Rotary encoder skipping or double-stepping</b></summary>

- ✅ Add 0.1µF capacitors across encoder pins to ground
- ✅ Increase debounce delay in interrupt handler
- ✅ Check for loose connections
- ✅ Try different encoder (quality varies by manufacturer)
</details>

<details>
<summary><b>Computer doesn't recognize the device</b></summary>

- ✅ Check USB cable (must support data, not just power)
- ✅ Try different USB port
- ✅ Verify the RP2040 is properly flashed with HID firmware
- ✅ Check Device Manager (Windows) or System Information (Mac)
</details>

<details>
<summary><b>RGB LEDs not lighting up</b></summary>

- ✅ Verify data pin connection and order (DI/DO chain)
- ✅ Check power supply (SK6812 needs 5V, at least 200mA for 3 LEDs)
- ✅ Confirm correct LED type in code (SK6812 vs WS2812B)
- ✅ Test LEDs individually to find faulty ones
</details>

> 💡 **Still stuck?** Open an [issue](https://github.com/Az154za/Hackypady/issues) or check [Discussions](https://github.com/Az154za/Hackypady/discussions) for help!

## 🤝 Contributing

We love contributions! Hackypady is a community-driven project and we welcome improvements from everyone.

### How to Contribute

- 🐛 **Report Bugs**: Use our [bug report template](.github/ISSUE_TEMPLATE/bug_report.md)
- 💡 **Suggest Features**: Use our [feature request template](.github/ISSUE_TEMPLATE/feature_request.md)
- 📖 **Improve Docs**: Fix typos, add examples, clarify instructions
- 🔧 **Submit Code**: Fork, improve, and submit a PR
- 🎨 **Share Your Build**: Show off your custom Hackypady!
- ❓ **Help Others**: Answer questions in Discussions

Read our [Contributing Guide](CONTRIBUTING.md) for detailed information.

### Recognition

Contributors will be listed here! Every contribution matters, no matter how small.

<a href="https://github.com/Az154za/Hackypady/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=Az154za/Hackypady" />
</a>

## 🗺️ Roadmap

### Current Features ✅
- ✅ 3×3 button matrix with diode scanning
- ✅ Rotary encoder support
- ✅ OLED display integration
- ✅ RGB LED indicators
- ✅ Arduino firmware example
- ✅ PCB design files (KiCad)
- ✅ 3D printable enclosure

### Planned Features 🚀
- [ ] CircuitPython firmware example
- [ ] PlatformIO project template
- [ ] Configuration GUI/web interface
- [ ] QMK firmware port
- [ ] Pre-configured keymap profiles
- [ ] Advanced OLED UI animations
- [ ] Wireless version (BLE)
- [ ] Layer switching support
- [ ] Macro recording functionality
- [ ] Integration with popular apps (OBS, Spotify, etc.)

**Want to help?** Pick an item and open an issue to discuss implementation!

## 🌟 Showcase

Built something cool with Hackypady? We'd love to see it! Share your builds in [Discussions](https://github.com/Az154za/Hackypady/discussions) and they might be featured here.

## 📚 Additional Resources

- 📖 [Seeed XIAO RP2040 Documentation](https://wiki.seeedstudio.com/XIAO-RP2040/)
- 🎨 [KiCad PCB Design Tutorial](https://docs.kicad.org/master/en/getting_started_in_kicad/)
- 🔧 [Arduino RP2040 Core](https://github.com/earlephilhower/arduino-pico)
- 💡 [Matrix Keyboard Scanning Guide](https://www.dribin.org/dave/keyboard/one_html/)
- 🎮 [QMK Firmware](https://qmk.fm/) - For advanced keyboard firmware

## 🌐 Community

Join the conversation and get help from the community:

- 💬 [GitHub Discussions](https://github.com/Az154za/Hackypady/discussions) - Ask questions, share ideas
- 🐛 [Issue Tracker](https://github.com/Az154za/Hackypady/issues) - Report bugs, request features
- 📖 [Wiki](https://github.com/Az154za/Hackypady/wiki) - Community guides and tutorials (coming soon)

## 📜 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

**What this means:**
- ✅ Commercial use allowed
- ✅ Modification allowed
- ✅ Distribution allowed
- ✅ Private use allowed
- ℹ️ License and copyright notice required

## 🙏 Credits & Acknowledgments

Built with ❤️ by the open-source community.

**Special thanks to:**
- Seeed Studio for the amazing XIAO RP2040
- Adafruit for excellent Arduino libraries
- The RP2040 community for support and inspiration
- All contributors who help improve this project

## ⭐ Support This Project

If you find Hackypady useful:
- ⭐ **Star this repository** to show your support
- 🔄 **Share it** with fellow makers and hobbyists
- 🐛 **Report issues** to help improve the project
- 🤝 **Contribute** your improvements
- 💬 **Help others** in Discussions

---

<div align="center">

**Made with ❤️ by makers, for makers**

[⬆ Back to Top](#-hackypady)

</div>
