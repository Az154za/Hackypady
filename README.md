
# Hackypady

Hackypady is a 9 key keyboard with one 0.91" OLED dispaly , 1 rotatory encoder , 3 multicolor LEDs (RGB) it does contain the XIAO seeed RP 2040 its objectif is to make u have fast access to ur favourite apps , shortcuts ....


##PCB
Here is my PCB with the schematic .it's made in Kicad .in This case I did the simple rotatory encoder because I have no pins digital pins  

<img width="698" height="619" alt="image" src="https://github.com/user-attachments/assets/fcdff6e4-3bd0-4e0e-9db7-c8977333857f" />
<img width="1168" height="565" alt="image" src="https://github.com/user-attachments/assets/a54b6f1d-69b7-4c6c-9a87-2f4edc9ed65b" />



## Assembly
1. Mount the OLED and encoder where visible/easy to reach.
2. Arrange the 9 switches in your preferred layout (3×3 grid is common).
3. Wire the switches into a diode matrix (each switch in series with a diode) to allow scanning with fewer pins.
4. Connect the encoder and OLED to the RP2040 according to the pinout you plan to use.
5. Double-check power (3.3V) and ground connections before powering.

<img width="1110" height="689" alt="image" src="https://github.com/user-attachments/assets/f3de322c-5382-45b3-9de3-15e9c377ea70" />



## Firmware / Software
The firmware is made with KMK python to set up the initiation of buttons and the encoder up and down volume 

## About this project
This project is highly scalable and depends on what micro controller you want to use or what's ur idea 

## Bill of Materials 
- 1 × Seeed XIAO RP2040 (or compatible RP2040 board)
- 1 × 0.91" OLED (I2C, 128×32 or 128×64)
- 1 × Rotary encoder switch or not ( it's an option)
- 9 × push buttons
- 9 × diodes (1N4148) for matrix design
