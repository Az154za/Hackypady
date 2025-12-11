# Frequently Asked Questions (FAQ)

## General Questions

### What is Hackypady?
Hackypady is an open-source, DIY macro keyboard project built around the Seeed XIAO RP2040 microcontroller. It features a 3×3 button matrix, rotary encoder, OLED display, and optional RGB LEDs - all in a compact form factor perfect for productivity shortcuts, media control, and custom macros.

### Do I need programming experience to build this?
Basic soldering skills are essential, but programming knowledge is optional. The firmware comes pre-configured with useful defaults, though you can easily customize it by editing simple configuration files. If you can modify a few lines in a text file, you can customize Hackypady!

### How much does it cost to build?
A complete build typically costs **$30-60 USD**, depending on component choices and whether you already have tools. The PCB can be manufactured for under $10 (for 5 boards), and most components are affordable and widely available.

### Where can I buy the components?
Components are available from:
- **AliExpress** - Best prices, longer shipping
- **Amazon** - Faster shipping, slightly higher prices
- **Adafruit/SparkFun** - Premium quality, excellent support
- **Local electronics stores** - Immediate availability

## Hardware Questions

### Can I use a different microcontroller?
The project is designed for the Seeed XIAO RP2040, but the firmware can be adapted for other RP2040 boards or even Arduino-compatible microcontrollers with sufficient I/O pins. You'll need to adjust pin definitions and may need to modify the PCB layout.

### Do I need the custom PCB or can I use a breadboard?
You can absolutely prototype on a breadboard or perfboard! The custom PCB makes assembly cleaner and more permanent, but it's not required to get started. Many people build their first version on a breadboard before committing to a PCB.

### Can I add more buttons?
Yes! The firmware supports expanding the button matrix. You'll need additional diodes and GPIO pins. A 4×4 matrix (16 buttons) is easily achievable with the RP2040's available pins. You can also implement layers to effectively multiply your button count.

### What switches are compatible?
Any Cherry MX-compatible mechanical switch works great. Popular choices include:
- **Cherry MX** - Original, high quality
- **Gateron** - Affordable, smooth
- **Kailh** - Various unique options
- **Tactile buttons** - For a lower-profile build

### Is the OLED display required?
No, it's optional! The keyboard will function without it, though you'll lose visual feedback for volume levels and other status information. The display is highly recommended for the full experience.

### Can I make it wireless?
The current design is USB-only, but a wireless version using BLE is on the roadmap. The RP2040 doesn't have built-in wireless, so you'd need to add a separate BLE module or switch to a board like the XIAO nRF52840.

## Firmware Questions

### What programming language is the firmware written in?
The default firmware is written in C++ for Arduino. However, you can also use:
- **CircuitPython** - Python-based, easier for beginners
- **MicroPython** - Similar to CircuitPython
- **C/C++** - Maximum performance and control
- **QMK Firmware** - Advanced keyboard firmware (planned support)

### How do I customize what each button does?
Open `Hackypady/Firmware.cpp` and find the `handleButtonPress()` function (search for "handleButtonPress" in the file). Each button has a case statement that defines its action. Simply change the function calls or add your own!

Example:
```cpp
case 1:
  openApp("Browser");  // Change to openApp("Spotify") or any app
  break;
```

### Can I program macros (multiple keystrokes)?
Yes! The firmware supports complex macros. You can program sequences of keystrokes with delays. For example:

```cpp
Keyboard.press(KEY_LEFT_CTRL);
Keyboard.press('c');
delay(50);
Keyboard.releaseAll();
```

### How do I update the firmware?
1. Connect your Hackypady via USB
2. Select the board in Arduino IDE
3. Click "Upload"
4. The new firmware is flashed automatically!

The RP2040 also supports drag-and-drop UF2 files - hold the BOOT button while connecting to enter bootloader mode.

### Does it work on Mac/Linux/Windows?
Yes! Hackypady acts as a standard USB HID keyboard, so it works with all major operating systems without drivers. Some application-specific shortcuts may need adjustment for different OSes.

## Assembly Questions

### What soldering iron do I need?
A basic temperature-controlled soldering iron (300-400°C / 570-750°F) is ideal. Recommended features:
- Temperature control
- Fine tip (chisel or conical)
- 20-60W power

Budget options start around $20-30 USD.

### I've never soldered before. Is this too difficult?
This is a great first project! The components are relatively large and easy to solder. Start with:
1. Practice on spare wire/perfboard
2. Solder the larger components first (switches, encoder)
3. Move to smaller parts (diodes, LEDs)
4. Watch soldering tutorial videos

### How long does it take to build?
- **First-time builders**: 4-6 hours
- **Experienced builders**: 2-3 hours
- **With pre-assembled PCB**: 1-2 hours

Take your time and test as you go!

### Can I 3D print the case?
Yes! STEP files are provided in `Hackypady/3D objects/`. Common settings:
- **Layer height**: 0.2mm
- **Infill**: 20-30%
- **Material**: PLA or PETG
- **Supports**: Usually not needed
- **Print time**: 3-6 hours

## Troubleshooting

### My computer doesn't recognize the device
- Try a different USB cable (must support data, not just charging)
- Check if the RP2040 is properly powered (LED should light up)
- Try a different USB port
- Re-flash the firmware
- Check for solder bridges on USB pins

### Some buttons don't work
- Verify diode orientation (cathode/black line toward columns)
- Check for cold solder joints
- Test continuity with a multimeter
- Verify pin definitions in firmware (search for "rowPins" and "colPins" at the top of Firmware.cpp) match your actual wiring
- Check for loose connections

### The OLED shows gibberish or nothing
- Verify I2C address (0x3C or 0x3D - try both)
- Check SDA/SCL wiring
- Ensure OLED has power (3.3V or 5V depending on module)
- Try an I2C scanner sketch to detect the display

See the main [README Troubleshooting section](../README.md#-troubleshooting) for more details.

## Software Compatibility

### What applications can I control?
Hackypady sends standard keyboard and media keys, so it works with virtually any application! Popular uses:
- **Media players** - Spotify, YouTube, VLC
- **Video editors** - Premiere, DaVinci Resolve, Final Cut
- **Photo editors** - Photoshop, Lightroom, GIMP
- **DAWs** - Ableton, FL Studio, Logic Pro
- **Streaming** - OBS, Streamlabs
- **Games** - Custom macros and hotkeys
- **Productivity** - VS Code, browsers, terminal

### Can I use it with game consoles?
No, it requires a computer with USB HID support. Game consoles (PlayStation, Xbox, Switch) don't support standard USB keyboards in games.

## Contributing & Community

### How can I contribute if I'm not a programmer?
Many ways to help:
- **Documentation** - Fix typos, improve instructions, add examples
- **Testing** - Try the build and report issues
- **Sharing** - Show your build and inspire others
- **Helping others** - Answer questions in Discussions
- **Design** - Create alternative 3D models or PCB layouts
- **Creating content** - Write blog posts, make videos

### Where can I share my build?
We'd love to see it! Share in:
- [GitHub Discussions](https://github.com/Az154za/Hackypady/discussions)
- Reddit: r/mechanicalkeyboards, r/arduino
- Social media with #Hackypady
- Hackster.io project showcase

### Can I sell kits or completed builds?
Yes! The MIT license allows commercial use. We only ask that you:
- Give credit to the original project
- Share improvements back to the community (optional but appreciated)
- Include the MIT license with your distribution

### I have an idea for improvement. Should I open an issue or PR?
For major changes, open an issue first to discuss. For small fixes or obvious improvements, feel free to submit a PR directly. Check [CONTRIBUTING.md](../CONTRIBUTING.md) for detailed guidelines.

## Advanced Questions

### Can I add a display for system information (CPU, RAM, etc.)?
Yes! You can use serial communication or libraries like `hwinfo` to send system stats from your computer to the Hackypady. The OLED can then display this information. Community members have created examples for this.

### How do I implement layers (Fn key functionality)?
Layers require tracking a "layer state" variable and checking it in your button handler:

```cpp
int currentLayer = 0;  // 0 = base layer, 1 = Fn layer

void handleButtonPress(int row, int col) {
  if (currentLayer == 0) {
    // Base layer actions
  } else if (currentLayer == 1) {
    // Fn layer actions
  }
}
```

Check the roadmap - full layer support is planned for a future firmware update!

### Can I add analog inputs (potentiometers, joysticks)?
Yes! The XIAO RP2040 has analog inputs (A0-A3). You can read these and map them to various functions. Popular uses include volume sliders, RGB color pickers, or game controller inputs.

### How do I add more RGB LEDs?
The firmware uses the Adafruit NeoPixel library, which supports chains of addressable LEDs. Simply:
1. Change `LED_COUNT` to your total number of LEDs
2. Connect LEDs in series (DOUT of one to DIN of next)
3. Update your animations to use the new LED count

---

## Still Have Questions?

- 📖 Check the [README.md](../README.md)
- 💬 Ask in [GitHub Discussions](https://github.com/Az154za/Hackypady/discussions)
- 🐛 Report issues on [GitHub Issues](https://github.com/Az154za/Hackypady/issues)
- 📚 Browse the [Project Structure](PROJECT_STRUCTURE.md)

---

*Last updated: December 2024*
