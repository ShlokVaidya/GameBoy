
# GameBoy — DIY Retro Handheld

Short blurb
---

I built a handheld Game Boy–style console using a Teensy 4.1, a Waveshare 2.4" 65K TFT, and an Adafruit PCM5102 I2S DAC. It’s a small, pocket-ish prototype meant for playing simple retro games and tunes — designed, soldered-ish, and 3D-modeled by me.

Why this exists
---

I wanted a tiny, fast, and playable handheld that actually sounds good. I sketched a case in Onshape, wired the Teensy to a TFT and DAC, chose a prototype board over a custom PCB to keep things flexible, and hacked everything together until it worked.

Demo / Gallery
---

All images below are from my build journal.

![Case design 1](https://stasis.hackclub-assets.com/images/1777868562101-7r0u8f.png)
![Case design 2](https://stasis.hackclub-assets.com/images/1777868582712-e3kdwr.png)
![Case design 3](https://stasis.hackclub-assets.com/images/1777868611349-eo0pu5.png)
![Display wiring diagram](https://stasis.hackclub-assets.com/images/1776577513190-6c7dji.png)
![DAC wiring diagram](https://stasis.hackclub-assets.com/images/1776628096443-07ndu8.png)
![Power wiring / TP4056 note](https://stasis.hackclub-assets.com/images/1776629412887-zm1dy0.png)
![Prototype board size idea (5x7 cm)](https://stasis.hackclub-assets.com/images/1776576309708-nnumna.png)
![Poster / research art](https://stasis.hackclub-assets.com/images/1776575110378-yzefuc.png)
![Extra photo](https://stasis.hackclub-assets.com/images/1776577302400-er7av3.png)

What I made
---

- A retro-styled handheld prototype using a Teensy 4.1 as the MCU.
- A custom Onshape case (exported as STEP files, linked below).
- Wiring for a Waveshare 2.4" 65K TFT (SPI) and an Adafruit PCM5102 I2S DAC.

Key wiring notes
---

- Display (Waveshare 2.4" 65K TFT, SPI):
	- VCC → 3.3V (Teensy)
	- GND → GND
	- DIN → MOSI
	- CLK → SCK
	- CS → Teensy CS pin
	- RST → GPIO 8
	- BL (backlight) → PWM pin 12

- Audio (Adafruit PCM5102 I2S DAC):
	- VIN → 5V / VIN (Teensy)
	- GND → GND
	- LCK (LRCLK) → pin 20
	- DIN → pin 7
	- BCK → pin 21
	- SCK → GND (not used)

- Power:
	- Use the TP4056 to charge the battery but feed the Teensy at `5V/VIN` (not 3.3V). The Teensy’s regulator expects VIN.

Source files
---

- CAD: [CAD/gameboy_cover.step](CAD/gameboy_cover.step) and [CAD/main_body.step](CAD/main_body.step)
- Firmware: see [Firmware/](Firmware/)

How I built it (short)
---

1. Designed the case in Onshape, iterated corners and fits until it felt right.
2. Prototyped the electronics on a 5x7 cm prototype board to avoid risky PCB errors.
3. Wired the display via SPI and the DAC via I2S following the pinout above.
4. Tested power routing carefully — the TP4056 must charge the battery and feed VIN.

What I learned
---

- Prototype boards are safer than custom PCBs when part footprints aren’t reliable.
- Teensy 4.1 is powerful and handles display + audio well for retro projects.
- Taking time to design the case early saved a lot of fit-and-finish headaches later.
