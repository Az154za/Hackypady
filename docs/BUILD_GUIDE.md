# Hackypady Build Guide

This guide will walk you through building your own Hackypady mini keyboard from scratch.

## Table of Contents
1. [Parts List](#parts-list)
2. [Tools Required](#tools-required)
3. [Assembly Steps](#assembly-steps)
4. [Firmware Installation](#firmware-installation)
5. [Testing](#testing)
6. [Troubleshooting](#troubleshooting)

## Parts List

### Essential Components
- [ ] 1× Custom PCB or breadboard
- [ ] 12× Mechanical switches (Cherry MX, Gateron, or Kailh)
- [ ] 12× 1N4148 diodes
- [ ] 1× Arduino Pro Micro or compatible microcontroller
- [ ] 12× Keycaps (1u size)
- [ ] 1× USB-C cable or connector
- [ ] Wire (22-24 AWG recommended)

### Optional Components
- [ ] 1× Rotary encoder (EC11 compatible)
- [ ] 1× Encoder knob
- [ ] 1× 0.96" OLED display (SSD1306)
- [ ] 12× WS2812B RGB LEDs
- [ ] 1× 3D printed or acrylic case
- [ ] 4× Rubber feet
- [ ] M2 screws and standoffs

## Tools Required

### Must Have
- Soldering iron (temperature controlled, 320-350°C)
- Solder (lead-free or 63/37 leaded)
- Wire cutters
- Wire strippers
- Multimeter

### Nice to Have
- Helping hands or PCB holder
- Flux
- Desoldering pump or wick
- Isopropyl alcohol (for cleaning)
- Tweezers

## Assembly Steps

### Step 1: Prepare the PCB
1. Clean the PCB with isopropyl alcohol
2. Check for any manufacturing defects
3. Identify all component positions

### Step 2: Solder Diodes
1. Bend diode leads at 90 degrees
2. Insert diodes into PCB (black band towards the square pad)
3. Solder one pad, check alignment
4. Solder second pad
5. Trim excess leads
6. Repeat for all 12 diodes

**Tip**: Test each diode with a multimeter in diode mode

### Step 3: Install Key Switches
1. Place switches into the PCB
2. Ensure all pins are straight
3. Push switches firmly until they click
4. Solder both pins on each switch
5. Check for cold joints or bridges

### Step 4: Install Microcontroller
1. Place pin headers into breadboard
2. Position Pro Micro face down
3. Solder all pins
4. Remove from breadboard
5. Socket the Pro Micro to PCB (optional but recommended)

### Step 5: Optional - RGB LEDs
1. Identify DIN, DOUT, VCC, and GND on LEDs
2. Chain LEDs in sequence
3. Connect DIN to microcontroller data pin
4. Solder VCC and GND
5. Test with a simple RGB pattern

### Step 6: Optional - OLED Display
1. Connect VCC to 5V
2. Connect GND to ground
3. Connect SDA to pin 2
4. Connect SCL to pin 3
5. Secure with double-sided tape

### Step 7: Optional - Rotary Encoder
1. Insert encoder into designated position
2. Solder all 5 pins
3. Connect A and B pins to microcontroller
4. Connect ground pin
5. Add encoder knob

### Step 8: Final Assembly
1. Install keycaps on all switches
2. Connect USB cable
3. Test all keys before closing case
4. Install in case if available
5. Add rubber feet

## Firmware Installation

### Option 1: Pre-compiled Firmware
1. Download the latest `.hex` file from releases
2. Open QMK Toolbox
3. Select the `.hex` file
4. Reset your keyboard (short RST to GND twice)
5. Click "Flash" when prompted

### Option 2: Compile from Source
```bash
# Clone QMK firmware
git clone https://github.com/qmk/qmk_firmware.git
cd qmk_firmware

# Copy Hackypady files
cp -r path/to/Hackypady/firmware keyboards/hackypady

# Compile and flash
qmk compile -kb hackypady -km default
qmk flash -kb hackypady -km default
```

## Testing

### Basic Key Test
1. Open a text editor
2. Press each key in sequence
3. Verify correct character output
4. Test all layers (hold function key)

### RGB Test (if installed)
1. Press RGB mode key (usually on function layer)
2. Cycle through different effects
3. Adjust brightness
4. Test color changes

### Encoder Test (if installed)
1. Rotate encoder clockwise
2. Rotate encoder counter-clockwise
3. Press encoder button
4. Test encoder on different layers

### OLED Test (if installed)
1. Power on keyboard
2. Check display shows correct layer
3. Test layer switching updates display
4. Verify LED status indicators

## Troubleshooting

### Key Not Working
**Problem**: Single key doesn't register
**Solutions**:
- Check switch pins are soldered properly
- Verify diode is oriented correctly
- Test with multimeter in continuity mode
- Try reflashing firmware

### Multiple Keys Not Working
**Problem**: Entire row or column not working
**Solutions**:
- Check matrix wiring connections
- Verify microcontroller pin connections
- Test diodes in the affected row/column
- Check for shorts between traces

### USB Not Recognized
**Problem**: Computer doesn't detect keyboard
**Solutions**:
- Try a different USB cable
- Test on a different USB port
- Check microcontroller power LED
- Verify bootloader is working (reset test)
- Check for shorts on USB lines

### RGB LEDs Not Working
**Problem**: LEDs don't light up or show wrong colors
**Solutions**:
- Verify power connections (VCC and GND)
- Check data line connection
- Test first LED in chain
- Verify LED count in config.h
- Check for reversed LED orientation

### OLED Display Blank
**Problem**: Display shows nothing
**Solutions**:
- Check I2C connections (SDA, SCL)
- Verify power supply (VCC and GND)
- Try different I2C address in config
- Test with example OLED code
- Check contrast settings

## Advanced Modifications

### Custom Case Design
- Use Fusion 360 or similar CAD software
- Design around your PCB dimensions
- Add cable routing channel
- Include mounting posts for PCB
- Export as STL for 3D printing

### Wireless Conversion
- Replace Pro Micro with Nice!Nano
- Add battery connector
- Modify case for battery compartment
- Flash ZMK firmware instead of QMK
- Add power switch

### Hot-Swap Sockets
- Use Kailh hot-swap sockets
- Solder sockets instead of switches
- Allows tool-free switch changes
- Easier maintenance
- Test different switches easily

## Resources

- [QMK Documentation](https://docs.qmk.fm/)
- [Keyboard Building Tutorial](https://www.keyboard-university.com/)
- [Soldering Guide](https://learn.adafruit.com/adafruit-guide-excellent-soldering)
- [Switch Comparison](https://switchandclick.com/mechanical-switch-guide/)

## Support

If you encounter issues not covered in this guide:
1. Check the [GitHub Issues](https://github.com/Az154za/Hackypady/issues)
2. Join the discussion forum
3. Contact the maintainer

Happy building! 🎉
