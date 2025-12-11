# Contributing to Hackypady

First off, thank you for considering contributing to Hackypady! 🎉 It's people like you that make Hackypady such a great project.

## How Can I Contribute?

### Reporting Bugs

Before creating bug reports, please check the existing issues to avoid duplicates. When you create a bug report, include as many details as possible:

- **Use a clear and descriptive title**
- **Describe the exact steps to reproduce the problem**
- **Provide specific examples** (code snippets, screenshots, etc.)
- **Describe the behavior you observed and what you expected**
- **Include details about your configuration:**
  - Hardware version (Seeed XIAO RP2040, etc.)
  - Firmware version or commit hash
  - Operating system (for computer-side software)

### Suggesting Enhancements

Enhancement suggestions are tracked as GitHub issues. When creating an enhancement suggestion, include:

- **Use a clear and descriptive title**
- **Provide a detailed description of the suggested enhancement**
- **Explain why this enhancement would be useful**
- **Include mockups or diagrams if applicable**

### Pull Requests

1. **Fork the repository** and create your branch from `main`
2. **Make your changes:**
   - Follow the existing code style
   - Add comments for complex logic
   - Update documentation if needed
3. **Test your changes:**
   - Verify firmware compiles without errors
   - Test on actual hardware if possible
   - Document any new wiring or setup requirements
4. **Update the README** if you've added new features or changed functionality
5. **Write clear commit messages** describing what changed and why
6. **Submit a pull request** with a comprehensive description

### Code Style Guidelines

#### For C++ Firmware:
- Use 2-space indentation
- Follow existing naming conventions
- Add comments for pin definitions and complex logic
- Keep functions focused and modular

#### For Documentation:
- Use clear, concise language
- Include code examples where helpful
- Add diagrams or images for hardware-related content
- Keep formatting consistent with existing docs

### First-Time Contributors

New to open source? Here are some good first issues to work on:

- Documentation improvements
- Adding code comments
- Testing on different hardware configurations
- Creating example keymaps or configurations
- Fixing typos or broken links

### Community Guidelines

- Be respectful and constructive in discussions
- Help others learn and grow
- Give credit where credit is due
- Follow our [Code of Conduct](CODE_OF_CONDUCT.md)

## Development Setup

1. Clone your fork:
   ```bash
   git clone https://github.com/YOUR-USERNAME/Hackypady.git
   cd Hackypady
   ```

2. For firmware development:
   - Install Arduino IDE or PlatformIO
   - Install required libraries (Adafruit_GFX, Adafruit_SSD1306, etc.)
   - Select "Seeed XIAO RP2040" as your board

3. For hardware design:
   - KiCad for PCB modifications
   - FreeCAD or similar for 3D enclosure changes

## Getting Help

- Check the [README](README.md) for project overview
- Search existing [Issues](https://github.com/Az154za/Hackypady/issues)
- Join discussions in the [Discussions](https://github.com/Az154za/Hackypady/discussions) tab
- Ask questions in your pull request or issue

## Recognition

Contributors will be recognized in the project! We value all contributions, big or small.

Thank you for contributing! 🚀
