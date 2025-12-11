# 🚀 Quick Start Guide

This guide will help you get your Hackypady up and running as quickly as possible!

## ⏱️ Time Estimate
- **Beginner**: 4-6 hours total (including learning)
- **Experienced**: 2-3 hours total

## 📋 What You'll Need

### Essential Tools
- ✅ Soldering iron (temperature controlled recommended)
- ✅ Solder (lead-free or leaded)
- ✅ Wire cutters/strippers
- ✅ USB-C cable (data capable)
- ✅ Computer with Arduino IDE

### Components (see [BOM in README](../README.md#-bill-of-materials))
- ✅ Seeed XIAO RP2040
- ✅ 0.91" OLED Display (I2C)
- ✅ Rotary Encoder
- ✅ 9× Mechanical Switches
- ✅ 9× Diodes (1N4148)
- ✅ PCB or Perfboard
- ✅ (Optional) 3× SK6812 LEDs

## 🎯 Step-by-Step Process

### Phase 1: Preparation (15 minutes)

1. **Gather all components**
   - Lay out everything on your workspace
   - Verify you have all parts from the BOM

2. **Install Arduino IDE**
   - Download from [arduino.cc](https://www.arduino.cc/en/software)
   - Install for your operating system

3. **Add RP2040 Support**
   ```
   File → Preferences → Additional Board Manager URLs
   Add: https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json
   ```
   - Then go to: Tools → Board → Boards Manager
   - Search for "RP2040" and install "Raspberry Pi Pico/RP2040"

4. **Install Libraries**
   - Go to: Tools → Manage Libraries
   - Install these libraries:
     - Adafruit_GFX
     - Adafruit_SSD1306
     - Adafruit_NeoPixel

### Phase 2: Hardware Assembly (2-4 hours)

#### Option A: Using Custom PCB (Easier)

1. **Solder Components in Order**
   ```
   Order matters for ease of assembly:
   1. Diodes (watch polarity! Black line = cathode)
   2. XIAO RP2040 headers/pins
   3. Mechanical switches
   4. Rotary encoder
   5. OLED display headers
   6. SK6812 LEDs (optional)
   ```

2. **Inspect Joints**
   - Check each solder joint for quality
   - Look for shorts or bridges
   - Ensure good connections

#### Option B: Using Perfboard/Breadboard (More Flexible)

1. **Plan Your Layout**
   - Sketch where components will go
   - Leave room for wiring

2. **Create Button Matrix**
   ```
   For each button:
   1. Connect one side to a row
   2. Connect other side to diode
   3. Connect diode cathode to column
   ```

3. **Wire According to Pinout**
   ```
   Rows: GPIO 11, 6, 9
   Columns: GPIO A0, A1, A2
   Encoder CLK: GPIO 10
   Encoder DT: GPIO 8
   OLED SDA: I2C SDA
   OLED SCL: I2C SCL
   LED Data: GPIO A3
   ```

### Phase 3: First Power-On Test (15 minutes)

1. **Visual Inspection**
   - Check for any obvious shorts
   - Verify all connections

2. **Connect USB**
   - Plug into computer
   - XIAO should light up (green/orange LED)

3. **Test Continuity**
   - Use multimeter to verify no shorts
   - Check power is reaching all components

### Phase 4: Flash Firmware (20 minutes)

1. **Open Firmware**
   - Navigate to `Hackypady/Firmware.cpp`
   - Open in Arduino IDE

2. **Select Board**
   ```
   Tools → Board → Raspberry Pi RP2040 Boards → Seeed XIAO RP2040
   Tools → Port → [Your XIAO's port]
   ```

3. **Verify Pin Definitions**
   - Check lines 18-35 match your wiring
   - Modify if you used different pins

4. **Upload**
   - Click the Upload button (→)
   - Wait for "Done uploading"
   - Check for any errors in console

### Phase 5: Testing (30 minutes)

1. **Test OLED Display**
   - Should show "XIAO Keyboard Ready!"
   - Then display volume level
   - If nothing shows: Check I2C wiring and address

2. **Test Each Button**
   - Press each button
   - Should trigger application (or error if app not found)
   - LED should flash on press

3. **Test Rotary Encoder**
   - Rotate encoder
   - Volume display should change
   - System volume should adjust

4. **Test RGB LEDs** (if installed)
   - Should show volume level in color
   - Green (low) → Yellow (mid) → Red (high)

### Phase 6: Customization (30 minutes - ∞)

1. **Customize Button Actions**
   - Edit `handleButtonPress()` function
   - Change app names to your preferences
   - Save and re-upload

2. **Adjust Volume Sensitivity**
   - Modify encoder step size if needed
   - Change debounce values for your encoder

3. **Customize LED Colors**
   - Edit `colorLow`, `colorMid`, `colorHigh` values
   - Change LED patterns

## 🆘 Common Issues

### OLED Not Working
- **Check**: I2C wiring (SDA/SCL)
- **Try**: Different I2C address (change `0x3C` to `0x3D`)
- **Test**: Run I2C scanner sketch

### Buttons Not Working
- **Check**: Diode orientation (stripe to column)
- **Verify**: Pin definitions match your wiring
- **Test**: Each button with multimeter

### Computer Doesn't Recognize Device
- **Try**: Different USB cable
- **Check**: Cable supports data (not just power)
- **Test**: Different USB port

### Encoder Not Smooth
- **Add**: Capacitors (0.1µF) to encoder pins
- **Increase**: Debounce delay
- **Try**: Different encoder (quality varies)

## 🎉 You're Done!

Your Hackypady should now be fully functional!

### Next Steps

1. **Install Enclosure** (if 3D printed)
2. **Create Custom Keymaps**
3. **Share Your Build** in [Discussions](https://github.com/Az154za/Hackypady/discussions)
4. **Help Others** who are building theirs

## 📚 Additional Resources

- [Full README](../README.md) - Complete documentation
- [FAQ](FAQ.md) - Common questions
- [Troubleshooting](../README.md#-troubleshooting) - Detailed fixes
- [Project Structure](PROJECT_STRUCTURE.md) - File organization

## 💡 Pro Tips

1. **Test as you go** - Don't wait until everything is soldered
2. **Label wires** - Saves time troubleshooting
3. **Take photos** - Document your build progress
4. **Use flux** - Makes soldering much easier
5. **Double-check polarity** - Especially for diodes and LEDs
6. **Keep components organized** - Small containers or trays help
7. **Practice first** - Try soldering on scrap before your PCB

## 🤔 Still Stuck?

- 💬 Ask in [GitHub Discussions](https://github.com/Az154za/Hackypady/discussions)
- 🐛 Report issues on [GitHub Issues](https://github.com/Az154za/Hackypady/issues)
- 📖 Check the [FAQ](FAQ.md)

---

**Happy Building! 🎉**

*Remember: Everyone's first build has challenges. Take your time, ask questions, and enjoy the learning process!*
