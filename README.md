# 🎮 Hackypady - The Ultimate Mini Keyboard

<div align="center">

[![Build Status](https://img.shields.io/badge/build-passing-brightgreen.svg)](https://github.com/Az154za/Hackypady)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
[![Made with Love](https://img.shields.io/badge/Made%20with-❤️-red.svg)](https://github.com/Az154za/Hackypady)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)](https://github.com/Az154za/Hackypady/pulls)

**A powerful, customizable mini keyboard designed for productivity enthusiasts, gamers, and makers.**

[Features](#-features) • [Specifications](#-technical-specifications) • [Setup](#-getting-started) • [Usage](#-usage-examples) • [Contributing](#-contributing)

</div>

```
╔═══════════════════════════════════════════════════════════╗
║                                                           ║
║   ┌───┬───┬───┬───┐     ┌───┬───┬───┬───┐               ║
║   │ 1 │ 2 │ 3 │ 4 │     │ A │ B │ C │ D │               ║
║   ├───┼───┼───┼───┤     ├───┼───┼───┼───┤               ║
║   │ 5 │ 6 │ 7 │ 8 │     │ E │ F │ G │ H │               ║
║   ├───┼───┼───┼───┤     ├───┼───┼───┼───┤               ║
║   │ 9 │ 0 │ - │ = │     │ I │ J │ K │ L │               ║
║   └───┴───┴───┴───┘     └───┴───┴───┴───┘               ║
║                                                           ║
║              H A C K Y P A D Y                            ║
║         Your Productivity Companion                       ║
╚═══════════════════════════════════════════════════════════╝
```

---

## ✨ Features

### 🚀 Core Capabilities
- **Compact Design**: 12-24 programmable keys in a minimal footprint
- **Fully Customizable**: Map any key to shortcuts, macros, or complex sequences
- **Multi-Layer Support**: Switch between different key layouts on-the-fly
- **Hot-Swappable**: Easy key switch replacement without soldering
- **RGB Backlighting**: Customizable per-key LED lighting with multiple effects
- **Low Latency**: 1ms response time for gaming and professional use
- **Cross-Platform**: Works seamlessly with Windows, macOS, and Linux

### 🎨 Advanced Features
- **Macro Recording**: Create complex multi-key sequences on the fly
- **Profile Management**: Save and switch between different configurations
- **Rotary Encoder Support**: Optional knob for volume, scrolling, or custom actions
- **OLED Display**: Real-time feedback for active layer and settings
- **USB-C Connectivity**: Modern, reversible connection with firmware updates
- **Open Source Firmware**: Based on QMK/VIA for unlimited customization
- **Wireless Option**: Bluetooth 5.0 support for cable-free operation

---

## 📋 Technical Specifications

| Component | Specification |
|-----------|---------------|
| **Microcontroller** | ATmega32U4 / RP2040 |
| **Switches** | Cherry MX / Gateron / Kailh compatible |
| **Key Count** | 12-24 keys (configurable layouts) |
| **Connection** | USB-C (wired) / Bluetooth 5.0 (wireless) |
| **Polling Rate** | 1000Hz (1ms response time) |
| **Backlighting** | RGB per-key LEDs (WS2812B) |
| **Dimensions** | 120mm × 80mm × 35mm |
| **Weight** | 180g (without cable) |
| **Power** | USB-powered / 500mAh battery (wireless) |
| **Firmware** | QMK/VIA compatible |
| **OS Support** | Windows 7+, macOS 10.12+, Linux (kernel 2.6+) |

---

## 🛠️ Hardware Components

### Required Parts
- 1× PCB (custom design or breadboard)
- 12-24× Mechanical key switches
- 12-24× Keycaps
- 1× Microcontroller board (Arduino Pro Micro, Elite-C, or similar)
- 12-24× 1N4148 diodes
- 1× USB-C connector or cable
- Optional: WS2812B RGB LED strip
- Optional: Rotary encoder
- Optional: 0.96" OLED display (SSD1306)

### Tools Needed
- Soldering iron and solder
- Wire cutters
- Multimeter (for testing)
- USB cable for programming
- Keycap puller (optional)

---

## 🚦 Getting Started

### Prerequisites
- Python 3.7+ (for QMK setup)
- Git
- Make and GCC compiler tools
- QMK Toolbox or AVRDUDE for flashing

### Installation

#### 1. Clone the Repository
```bash
git clone https://github.com/Az154za/Hackypady.git
cd Hackypady
```

#### 2. Set Up QMK Environment
```bash
# Install QMK CLI
pip3 install qmk

# Set up QMK firmware
qmk setup

# Clone QMK if not already installed
git clone https://github.com/qmk/qmk_firmware.git
cd qmk_firmware
```

#### 3. Configure Your Layout
```bash
# Copy the default keymap
cp -r keyboards/hackypady/keymaps/default keyboards/hackypady/keymaps/my_layout

# Edit your keymap
vim keyboards/hackypady/keymaps/my_layout/keymap.c
```

#### 4. Compile the Firmware
```bash
# Compile the firmware
qmk compile -kb hackypady -km my_layout

# Flash to your keyboard
qmk flash -kb hackypady -km my_layout
```

### Quick Start Guide
1. **Connect** the mini keyboard to your computer via USB
2. **Install** VIA configurator from [caniusevia.com](https://caniusevia.com)
3. **Open** VIA and it will automatically detect your Hackypady
4. **Customize** your keys by dragging and dropping functions
5. **Save** your configuration and start being productive!

---

## 💡 Usage Examples

### For Programmers
```c
// Layer 0: Code Navigation
[0] = LAYOUT(
    KC_F5,    KC_F9,    KC_F10,   KC_F11,     // Debug controls
    KC_LCTL,  KC_C,     KC_V,     KC_Z,       // Copy, Paste, Undo
    KC_FIND,  KC_HOME,  KC_END,   KC_ENTER    // Navigation
)
```

### For Video Editors
```c
// Layer 1: Video Editing
[1] = LAYOUT(
    KC_SPACE, KC_J,     KC_K,     KC_L,       // Play, Rewind, Fast Forward
    KC_C,     KC_V,     KC_B,     KC_N,       // Cut, Select, Blade tool
    KC_LCTL_Z, KC_LCTL_S, KC_DEL, KC_ENTER    // Undo, Save, Delete
)
```

### For Gamers
```c
// Layer 2: Gaming Macros
[2] = LAYOUT(
    KC_1,     KC_2,     KC_3,     KC_4,       // Abilities 1-4
    KC_Q,     KC_E,     KC_R,     KC_F,       // Item slots
    KC_LCTL,  KC_LSHIFT, KC_SPACE, KC_TAB     // Sprint, Crouch, Jump
)
```

### For Streamers
- **Scene Switching**: Instant transition between streaming scenes
- **Mute/Unmute**: Quick audio control without fumbling
- **Start/Stop Recording**: One-touch recording control
- **Quick Messages**: Send chat messages with a single keypress

---

## 🎨 Customization

### RGB Lighting Modes
- **Static**: Solid color illumination
- **Breathing**: Smooth pulsing effect
- **Rainbow**: Cycling through color spectrum
- **Reactive**: Light up on keypress
- **Wave**: Color wave animation
- **Custom**: Program your own effects

### Layer Indicators
Use different LED colors to indicate which layer is active:
- Layer 0 (Default): White
- Layer 1 (Function): Blue
- Layer 2 (Gaming): Red
- Layer 3 (Media): Green

---

## 📚 Documentation

### Configuration Files
- `config.h` - Hardware configuration and feature flags
- `rules.mk` - Build options and firmware features
- `keymap.c` - Key layout and layer definitions
- `README.md` - This file

### Key Resources
- [QMK Documentation](https://docs.qmk.fm/)
- [VIA Documentation](https://www.caniusevia.com/docs)
- [Keyboard Layout Editor](http://www.keyboard-layout-editor.com/)
- [Switch Selection Guide](https://www.keyboard-university.com/mechanical-switches)

---

## 🐛 Troubleshooting

### Keyboard Not Detected
1. Check USB cable connection
2. Try a different USB port
3. Verify drivers are installed
4. Reset the keyboard by pressing the reset button

### Keys Not Working
1. Check switch connections
2. Verify diode orientation
3. Test with a multimeter
4. Reflash the firmware

### LED Issues
1. Check LED strip connection
2. Verify power supply
3. Check `config.h` for LED count
4. Test with simple effects first

---

## 🤝 Contributing

We love contributions! Here's how you can help:

1. **Fork** the repository
2. **Create** a feature branch (`git checkout -b feature/amazing-feature`)
3. **Commit** your changes (`git commit -m 'Add some amazing feature'`)
4. **Push** to the branch (`git push origin feature/amazing-feature`)
5. **Open** a Pull Request

### Contribution Ideas
- 🎨 New RGB lighting effects
- ⌨️ Additional keymap layouts
- 📝 Documentation improvements
- 🐛 Bug fixes
- 🎮 Game-specific profiles
- 💼 Professional workflow templates

---

## 📜 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## 🌟 Acknowledgments

- **QMK Firmware Team** - For the incredible firmware framework
- **VIA Team** - For the intuitive configuration tool
- **Mechanical Keyboard Community** - For inspiration and support
- **All Contributors** - For making this project better

---

## 📞 Contact & Support

- **Issues**: [GitHub Issues](https://github.com/Az154za/Hackypady/issues)
- **Discussions**: [GitHub Discussions](https://github.com/Az154za/Hackypady/discussions)
- **Email**: ahmedaziz.benhassen@gmail.com

---

<div align="center">

**Made with ❤️ by the Hackypady Community**

⭐ Star this repo if you find it useful! ⭐

[Back to Top](#-hackypady---the-ultimate-mini-keyboard)

</div>