# Hackypady Hardware Schematic

This document describes the electrical connections and hardware design for the Hackypady mini keyboard.

## Circuit Overview

```
                    ┌─────────────────────────────┐
                    │   ATmega32U4 / RP2040      │
                    │   (Pro Micro / Elite-C)     │
                    └──┬──────────────────────┬──┘
                       │                      │
        ┌──────────────┴───────────┐         │
        │   Key Matrix (3×4)       │         │
        │                          │         │
        │  Row 0: D1  ──┬──┬──┬──┐│         │
        │  Row 1: D0  ──┼──┼──┼──┤│         │
        │  Row 2: D4  ──┼──┼──┼──┤│         │
        │               │  │  │  │ │         │
        │  Col 0: C6 ───┘  │  │  │ │         │
        │  Col 1: D7 ──────┘  │  │ │         │
        │  Col 2: E6 ─────────┘  │ │         │
        │  Col 3: B4 ────────────┘ │         │
        └──────────────────────────┘         │
                                              │
        ┌─────────────────────────────────────┘
        │
        ├──┤ RGB LED Strip (WS2812B) - F4
        │
        ├──┤ Rotary Encoder - F5, F6
        │
        ├──┤ OLED Display (I2C) - SDA: 2, SCL: 3
        │
        └──┤ USB-C - D+ (D2), D- (D3), VCC, GND
```

## Pin Assignment

### Microcontroller Pin Mapping

| Pin | Function | Description |
|-----|----------|-------------|
| D1  | Row 0    | Key matrix row 0 |
| D0  | Row 1    | Key matrix row 1 |
| D4  | Row 2    | Key matrix row 2 |
| C6  | Col 0    | Key matrix column 0 |
| D7  | Col 1    | Key matrix column 1 |
| E6  | Col 2    | Key matrix column 2 |
| B4  | Col 3    | Key matrix column 3 |
| F4  | RGB Data | WS2812B data line |
| F5  | Encoder A| Rotary encoder channel A |
| F6  | Encoder B| Rotary encoder channel B |
| 2   | SDA      | OLED I2C data |
| 3   | SCL      | OLED I2C clock |
| RAW | VCC      | 5V power input |
| GND | Ground   | Common ground |

## Key Matrix

The keyboard uses a standard key matrix with diodes to prevent ghosting.

### Matrix Wiring

```
        COL0    COL1    COL2    COL3
         C6      D7      E6      B4
         │       │       │       │
ROW0─D1──┼───●───┼───●───┼───●───┼───●
         │   │   │   │   │   │   │   │
        ▼│  SW0 ▼│  SW1 ▼│  SW2 ▼│  SW3
         │   │   │   │   │   │   │   │
ROW1─D0──┼───●───┼───●───┼───●───┼───●
         │   │   │   │   │   │   │   │
        ▼│  SW4 ▼│  SW5 ▼│  SW6 ▼│  SW7
         │   │   │   │   │   │   │   │
ROW2─D4──┼───●───┼───●───┼───●───┼───●
         │   │   │   │   │   │   │   │
        ▼│  SW8 ▼│  SW9 ▼│  SW10 ▼│ SW11
         │   │   │   │   │   │   │   │
        ═╧═  │  ═╧═  │  ═╧═  │  ═╧═  │
        1N4148  1N4148  1N4148  1N4148

Legend:
● = Key switch
▼ = Diode (cathode pointing down)
═ = Diode symbol
```

### Diode Orientation
- **Cathode (black band)**: Points toward the ROW pin
- **Anode**: Points toward the switch
- **Purpose**: Prevents ghosting in multi-key combinations

## RGB Lighting

### WS2812B LED Strip Connection

```
┌──────────────────────────────────────────┐
│ Microcontroller                          │
│                                          │
│  F4 (RGB_DI) ───────┐                    │
│  VCC ───────┐       │                    │
│  GND ─────┐ │       │                    │
└───────────┼─┼───────┼────────────────────┘
            │ │       │
        ┌───┴─┴───────┴────┐
        │ LED 1            │
        │ GND VCC DIN DOUT │
        └─────────────┬────┘
                      │
        ┌─────────────┴────┐
        │ LED 2            │
        │ GND VCC DIN DOUT │
        └─────────────┬────┘
                      │
                     ...
                      │
        ┌─────────────┴────┐
        │ LED 12           │
        │ GND VCC DIN DOUT │
        └──────────────────┘
```

### LED Configuration
- **Count**: 12 LEDs (one per key)
- **Type**: WS2812B (5050 RGB)
- **Voltage**: 5V
- **Current**: ~60mA per LED at full brightness
- **Data Rate**: 800kHz

## Rotary Encoder

### Encoder Wiring

```
┌──────────────────┐
│ Rotary Encoder   │
│                  │
│  Common ─── GND  │
│  A ───────── F5  │
│  B ───────── F6  │
│  Switch ──── B5  │ (optional)
└──────────────────┘
```

### Encoder Specifications
- **Type**: EC11 or similar
- **Pulses per revolution**: 20
- **Detents**: 20
- **Switch rating**: 10,000 cycles

## OLED Display

### Display Connection (I2C)

```
┌──────────────────┐
│ OLED Display     │
│ (SSD1306)        │
│                  │
│  VCC ─────── 5V  │
│  GND ─────── GND │
│  SDA ─────── 2   │
│  SCL ─────── 3   │
└──────────────────┘
```

### Display Specifications
- **Size**: 0.96" diagonal
- **Resolution**: 128×64 pixels
- **Interface**: I2C
- **Address**: 0x3C (default)
- **Voltage**: 3.3-5V

## Power Requirements

### Current Draw
| Component | Current (mA) | Notes |
|-----------|--------------|-------|
| Microcontroller | 50-100 | Active operation |
| RGB LEDs (all on) | 720 | 60mA × 12 LEDs |
| OLED Display | 20-30 | Active display |
| Encoder | 1-2 | Negligible |
| **Total Max** | **850** | All features active |
| **Typical** | **150-200** | Normal usage |

### USB Power
- **Standard USB 2.0**: 500mA (sufficient for typical use)
- **USB 3.0**: 900mA (sufficient for all features)
- **Recommendation**: Use LED brightness limiting to stay within USB limits

## PCB Design Considerations

### Board Dimensions
- **Width**: 120mm
- **Height**: 80mm
- **Thickness**: 1.6mm (standard)

### Layer Stack
1. **Top Layer**: Component pads and traces
2. **Ground Plane**: Common ground
3. **Power Plane**: VCC distribution
4. **Bottom Layer**: Return traces

### Trace Width
- **Signal traces**: 0.3mm (10mil)
- **Power traces**: 0.5mm (20mil)
- **USB differential pair**: 0.25mm with 0.25mm spacing

### Design Files
- Gerber files: `hardware/gerbers/`
- Schematic (KiCad): `hardware/schematic.kicad_sch`
- PCB layout (KiCad): `hardware/pcb.kicad_pcb`
- BOM (Bill of Materials): `hardware/BOM.csv`

## Bill of Materials (BOM)

| Qty | Reference | Value | Description | Manufacturer | Part Number |
|-----|-----------|-------|-------------|--------------|-------------|
| 12  | SW1-SW12  | MX | Mechanical Switch | Cherry/Gateron | MX Series |
| 12  | D1-D12    | 1N4148 | Switching Diode | Various | 1N4148 |
| 1   | U1        | ATmega32U4 | Microcontroller | SparkFun | Pro Micro |
| 12  | LED1-12   | WS2812B | RGB LED | WorldSemi | WS2812B |
| 1   | U2        | SSD1306 | OLED Display | Various | 0.96" OLED |
| 1   | ENC1      | EC11 | Rotary Encoder | ALPS | EC11E |
| 1   | J1        | USB-C | USB Connector | Various | USB-C 16P |
| 1   | C1        | 10µF | Capacitor | Various | 0805 |
| 2   | C2,C3     | 100nF | Capacitor | Various | 0805 |
| 2   | R1,R2     | 22Ω | Resistor | Various | 0805 |
| 2   | R3,R4     | 10kΩ | Resistor | Various | 0805 |

## Assembly Notes

### Critical Measurements
1. **Switch spacing**: 19mm center-to-center
2. **Mounting holes**: M2 (2mm) diameter
3. **PCB to case clearance**: 2mm minimum
4. **USB connector height**: 3.5mm from PCB

### ESD Protection
- Add TVS diodes on USB data lines
- Ground plane for EMI shielding
- Proper trace routing for USB differential pair

### Testing Points
- Add test pads for VCC, GND, and each matrix line
- Facilitates debugging and troubleshooting
- 1mm diameter test pads recommended

## Firmware Configuration Reference

The hardware configuration is defined in `firmware/config.h`:

```c
#define MATRIX_ROWS 3
#define MATRIX_COLS 4
#define MATRIX_ROW_PINS { D1, D0, D4 }
#define MATRIX_COL_PINS { C6, D7, E6, B4 }
#define RGB_DI_PIN F4
#define RGBLED_NUM 12
#define ENCODERS_PAD_A { F5 }
#define ENCODERS_PAD_B { F6 }
```

## Resources

- [Pro Micro Pinout](https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide)
- [WS2812B Datasheet](https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf)
- [ATmega32U4 Datasheet](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7766-8-bit-AVR-ATmega16U4-32U4_Datasheet.pdf)
- [QMK Hand Wiring Guide](https://docs.qmk.fm/#/hand_wire)

## Support

For hardware questions:
- Open an issue on GitHub
- Check the discussions forum
- Email: ahmedaziz.benhassen@gmail.com

---

**Safety Notice**: Always disconnect power before making hardware modifications. Use proper ESD precautions when handling electronic components.
