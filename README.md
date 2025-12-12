<img width="1110" height="689" alt="image" src="https://github.com/user-attachments/assets/f3de322c-5382-45b3-9de3-15e9c377ea70" /># Hackypady
# Hackypady

Hackypady is a compact, highly-customizable macro keyboard built around the Seeed XIAO RP2040.  
It combines a 0.91" OLED display, a rotary encoder, and a 9-button matrix (3×3) using only 6 GPIO pins.  
Designed for hobbyists and makers who want a small, programmable input device for shortcuts, media control, macros or external automation.


<img width="1110" height="689" alt="image" src="https://github.com/user-attachments/assets/12ce3998-4f8a-4970-81af-b563bc2312a9" />



## Key features
- 3×3 button matrix (9 buttons) using 6 pins (diode matrix)
- Rotary encoder with push switch
- 0.91" OLED (I2C) for status / layers / indicators
- Seeed XIAO RP2040 (tiny RP2040 form factor) — low-power and fast
- Fully customizable firmware and keymaps
- Lightweight and easy to scale (add more keys/layers)

## Bill of Materials (suggested)
- 1 × Seeed XIAO RP2040 (or compatible RP2040 board)
- 1 × 0.91" OLED (I2C, 128×32 or 128×64)
- 1 × Rotary encoder (with push)
- 9 × push buttons (mechanical or tactile)
- 9 × diodes (e.g., 1N4148) if using matrix scanning
- Prototyping PCB / perfboard or custom PCB
- Wires, headers, enclosure as desired

## Suggested wiring / pinout (example)
Adjust pins to match your board layout and firmware pin definitions. This is only an example:
- OLED (I2C): SDA -> SDA pin, SCL -> SCL pin (e.g., SDA, SCL on your XIAO)
- Rotary encoder: CLK, DT -> two digital GPIOs, SW -> another GPIO
- Matrix rows/columns: 6 GPIOs for the 3×3 matrix (3 pins for rows, 3 for columns)
- GND and VCC: common power rails (3.3V)

Tip: identify your XIAO RP2040 pin labels on the silk/board and change the firmware pin definitions to match.


<img width="1168" height="565" alt="image" src="https://github.com/user-attachments/assets/a54b6f1d-69b7-4c6c-9a87-2f4edc9ed65b" />

## Assembly
1. Mount the OLED and encoder where visible/easy to reach.
2. Arrange the 9 switches in your preferred layout (3×3 grid is common).
3. Wire the switches into a diode matrix (each switch in series with a diode) to allow scanning with fewer pins.
4. Connect the encoder and OLED to the RP2040 according to the pinout you plan to use.
5. Double-check power (3.3V) and ground connections before powering.



<img width="1302" height="695" alt="image" src="https://github.com/user-attachments/assets/2aff2f6d-4d35-4c09-a52f-2ba0c0e41045" />

## Firmware / Software
This project is firmware-agnostic — you can implement the key scanning and HID behaviour using:
- CircuitPython (learn quick prototyping and fast iteration)
- Arduino / RP2040 Arduino cores (C++ with libraries)
- PlatformIO projects or custom C/C++ firmware

Basic steps:
1. Clone this repository locally.
2. Choose your firmware platform (e.g., CircuitPython or PlatformIO).
3. Set the pin definitions and keymap in the firmware source (look for pin/keymap variables).
4. Build/flash to the Seeed XIAO RP2040:
   - For Arduino/PlatformIO: select the Seeed XIAO RP2040 board and upload.
   - For CircuitPython: copy the .py files to the CIRCUITPY drive and edit code.py.
5. Test keys, encoder rotation, and OLED output.

Example behavior ideas:
- Single key actions (short press)
- Hold or layer keys (modifier + key on hold)
- Encoder rotation = volume up/down, encoder press = mute or layer toggle
- OLED shows current layer or active macro

## Customization
- Add layers to expand functionality (Fn layer for media, emojis, macros, etc.)
- Increase the matrix size and add diodes if you want more keys
- Replace OLED with a larger display or RGB indicators
- Add macros to call external scripts (via serial / USB HID) for automation

## Troubleshooting
- OLED not showing:
  - Verify SDA/SCL wiring and I2C address; try an I2C scanner sketch.
- Some keys read incorrectly:
  - Check diode orientation and matrix wiring; make sure rows/columns are defined correctly in firmware.
- Encoder noisy or double-steps:
  - Add debouncing in software or a small capacitor if needed.

## Contributing
Contributions are welcome! Please:
1. Open an issue to discuss major changes or new features.
2. Fork the repo and submit a pull request with a clear description and screenshots or diagrams where applicable.
3. Include code comments and update this README if you add new wiring, firmware examples or parts lists.

## Roadmap / Ideas
- Add example firmware: CircuitPython and PlatformIO/C++ templates
- Provide a PCB layout and printable enclosure design
- Add pre-configured keymaps and OLED UI examples
- Add automated build/CI for firmware

## License
Choose a license for the project (e.g., MIT, Apache-2.0) and add a LICENSE file. If you want, I can add an MIT license file for you.

## Credits
Built with RP2040 community support and open-source libraries. Thanks to everyone who shares code and hardware designs.

feel free to adapt, extend and share your improvements!
```
