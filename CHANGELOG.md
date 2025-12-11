# Changelog

All notable changes to the Hackypady project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Added
- Comprehensive project documentation
- MIT License
- Code of Conduct for community standards
- Contributing guidelines for contributors
- GitHub issue templates (bug report, feature request, hardware help)
- Pull request template
- FAQ document with common questions and answers
- Project structure documentation
- Enhanced README with badges, better formatting, and visual hierarchy
- Detailed Bill of Materials with cost estimates
- Comprehensive pinout reference table
- Step-by-step assembly guide
- Firmware customization guide
- Troubleshooting section with collapsible details
- Customization ideas and use cases
- Roadmap and planned features
- Community section and resources

### Changed
- Reorganized README for better user experience
- Improved documentation structure

## [1.0.0] - Initial Release

### Added
- Arduino firmware for XIAO RP2040
  - 3×3 button matrix support
  - Rotary encoder support for volume control
  - OLED display integration (0.91")
  - SK6812 RGB LED support (3 LEDs)
  - USB HID keyboard and media key support
  - Application launcher macros
- KiCad PCB design files
  - Complete schematic
  - PCB layout for manufacturing
  - Component placement
- 3D printable enclosure files (STEP format)
  - Main enclosure base
  - Upper case/plate
  - Complete assembly model
- Basic README with project overview

### Hardware Specifications
- Seeed XIAO RP2040 microcontroller
- 9-button mechanical keyboard matrix
- Rotary encoder with push button
- I2C OLED display (128×32 or 128×64)
- 3× addressable RGB LEDs
- USB-C connectivity

### Features
- Diode matrix scanning for efficient pin usage
- Debounced button inputs
- Volume control via rotary encoder
- Visual feedback on OLED display
- RGB LED volume indicators
- Customizable application launchers
- Low-latency USB HID operation

---

## Version History

- **[Unreleased]** - Documentation improvements and community features
- **[1.0.0]** - Initial public release with hardware, firmware, and basic docs

---

*For detailed commit history, see [GitHub Commits](https://github.com/Az154za/Hackypady/commits)*
