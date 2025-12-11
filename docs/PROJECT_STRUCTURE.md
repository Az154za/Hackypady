# Hackypady Project Structure

This document provides an overview of the project organization to help you navigate the repository.

## 📁 Repository Layout

```
Hackypady/
├── 📄 README.md                    # Main project documentation
├── 📄 LICENSE                      # MIT License
├── 📄 CODE_OF_CONDUCT.md          # Community guidelines
├── 📄 CONTRIBUTING.md             # Contribution guidelines
│
├── 📁 Hackypady/                   # Main project directory
│   ├── 📄 Firmware.cpp            # Arduino firmware source code
│   │
│   ├── 📁 PCB design/             # KiCad PCB design files
│   │   ├── Mini_key_capy.kicad_pcb    # PCB layout
│   │   ├── Mini_key_capy.kicad_pro    # KiCad project
│   │   └── Mini_key_capy.kicad_sch    # Schematic
│   │
│   └── 📁 3D objects/             # 3D printable enclosure files
│       ├── Hackpady.step          # Main enclosure
│       ├── Hackpady_upper.step    # Upper case part
│       └── Keyhackpad_product.step # Assembly
│
├── 📁 .github/                     # GitHub configuration
│   ├── 📁 ISSUE_TEMPLATE/         # Issue templates
│   │   ├── bug_report.md
│   │   ├── feature_request.md
│   │   └── hardware_help.md
│   └── PULL_REQUEST_TEMPLATE.md
│
└── 📁 docs/                        # Documentation
    └── PROJECT_STRUCTURE.md       # This file
```

## 🔍 File Descriptions

### Root Level Files

- **README.md**: Complete project overview, setup instructions, and documentation
- **LICENSE**: MIT License terms and conditions
- **CODE_OF_CONDUCT.md**: Community standards and behavior guidelines
- **CONTRIBUTING.md**: How to contribute to the project

### Hackypady/Firmware.cpp

The main Arduino firmware file containing:
- Pin definitions and configuration
- Button matrix scanning logic
- Rotary encoder handling
- OLED display functions
- RGB LED control
- USB HID keyboard/media control

**Key sections:**
- Lines 18-35: Pin definitions (easily customizable)
- Lines 167-215: Button press handlers (modify for custom actions)
- Lines 242-279: Application launcher functions
- Lines 359-390: LED effects and animations

### Hackypady/PCB design/

KiCad 6.0+ project files for the custom PCB:
- **Mini_key_capy.kicad_pcb**: Complete PCB layout with traces and component placement
- **Mini_key_capy.kicad_sch**: Circuit schematic showing connections
- **Mini_key_capy.kicad_pro**: Project settings and metadata

**To modify:**
1. Open in KiCad 6.0 or later
2. Edit schematic or PCB layout
3. Run design rule check (DRC)
4. Export Gerber files for manufacturing

### Hackypady/3D objects/

STEP format 3D models for the enclosure:
- **Hackpady.step**: Main enclosure base
- **Hackpady_upper.step**: Top cover/plate
- **Keyhackpad_product.step**: Complete assembly reference

**To use:**
1. Import into your 3D software (FreeCAD, Fusion 360, etc.)
2. Export as STL for 3D printing
3. Recommended print settings:
   - Layer height: 0.2mm
   - Infill: 20-30%
   - Supports: Usually not needed
   - Material: PLA or PETG

### .github/ Directory

GitHub-specific configuration:
- **ISSUE_TEMPLATE/**: Templates for bug reports, feature requests, and help requests
- **PULL_REQUEST_TEMPLATE.md**: Template for pull requests

## 🔄 Typical Workflow

### For Hardware Builders
1. Start with **README.md** for overview
2. Check **Bill of Materials** section
3. Review **Hackypady/PCB design/** files
4. Print **Hackypady/3D objects/** for enclosure
5. Flash **Hackypady/Firmware.cpp** to your board

### For Contributors
1. Read **CONTRIBUTING.md** for guidelines
2. Browse **CODE_OF_CONDUCT.md**
3. Use templates in **.github/ISSUE_TEMPLATE/**
4. Modify relevant files (firmware, PCB, or docs)
5. Submit PR using the PR template

### For Firmware Customization
1. Open **Hackypady/Firmware.cpp**
2. Modify pin definitions (lines 18-35)
3. Customize button actions (lines 167-215)
4. Adjust debounce/timing as needed
5. Flash to your XIAO RP2040

## 🎯 Quick Links by Task

| Task | Primary Files |
|------|---------------|
| Build hardware | PCB design/, 3D objects/, README.md |
| Customize firmware | Firmware.cpp |
| Design PCB changes | PCB design/*.kicad_* |
| Modify enclosure | 3D objects/*.step |
| Report issues | .github/ISSUE_TEMPLATE/ |
| Contribute code | CONTRIBUTING.md, Firmware.cpp |
| Understand wiring | README.md (Pinout section), Firmware.cpp |

## 📝 Notes

- All hardware files are open source under MIT license
- Firmware uses standard Arduino libraries
- PCB can be ordered from any manufacturer (JLCPCB, PCBWay, etc.)
- 3D models are parameterized for easy modification

## 🤝 Need Help?

- Check the [README.md](../README.md) troubleshooting section
- Browse [existing issues](https://github.com/Az154za/Hackypady/issues)
- Ask in [Discussions](https://github.com/Az154za/Hackypady/discussions)
- Review [CONTRIBUTING.md](../CONTRIBUTING.md) for development setup

---

*Last updated: December 2024*
