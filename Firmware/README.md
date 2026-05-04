Firmware for GameBoy prototype
==============================

This folder contains a starter Teensy/Arduino sketch that demonstrates basic display init, backlight PWM, and placeholders for I2S audio output. It is a minimal, easy-to-edit template — not a finished game.

What it does
---
- Initializes Serial for debugging
- Initializes a SPI display (example code uses Adafruit-style drivers; change to match your module)
- Controls the backlight on PWM pin 12 (as used in the journal)
- Shows a simple title screen
- Includes commented example code for using Teensy's Audio/I2S output to a PCM5102 (placeholders)

Requirements
---
- Teensy 4.1 and Teensyduino (Arduino IDE + Teensy add-on) installed
- Install the following Arduino libraries (via Library Manager):
  - Adafruit GFX
  - Adafruit ST7735 or Adafruit ILI9341 (choose the one matching your TFT controller)
  - (Optional) Teensy Audio library (included with Teensyduino) for I2S output

How to use
---
1. Open `GameBoy.ino` in the Arduino IDE.
2. Select the board `Teensy 4.1` and set USB type and CPU speed as desired.
3. Install the libraries listed above if you plan to use the display code.
4. Edit the display driver choice near the top of the sketch to match your screen (`ST7735` or `ILI9341`).
5. Upload to the Teensy. Use the Serial Monitor at 115200 for logs.

Notes / TODO
---
- Replace the placeholder display driver with the exact driver for your Waveshare TFT if needed.
- Add your game loop, input handling, and actual audio file playback.
- Once firmware is finalized, add build scripts or PlatformIO config if desired.
