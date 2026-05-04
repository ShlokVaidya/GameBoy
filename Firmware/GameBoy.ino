/*
  GameBoy prototype - starter firmware

  Minimal Teensy/Arduino sketch to initialize a SPI display and
  control backlight. Includes placeholders for I2S audio output to PCM5102.

  Edit the DISPLAY_DRIVER define below to match your display (ST7735 or ILI9341).
  Install Adafruit_GFX + the matching Adafruit driver via Library Manager.

  Pins (from JOURNAL.md):
  - RST = 8
  - BL  = 12 (PWM)
  - SPI : uses hardware SPI (MOSI, SCK)

  Audio (placeholder):
  - I2S pins: LCK -> 20, DIN -> 7, BCK -> 21 (see journal)
*/

#include <Arduino.h>

// Choose your display driver here:
// Uncomment the driver you want and install required libraries.
//#define DISPLAY_ST7735
#define DISPLAY_ILI9341

#ifdef DISPLAY_ST7735
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
// Example pin wiring for ST7735 (change if your module uses different pins)
#define TFT_CS   10
#define TFT_DC   9
#define TFT_RST  8
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
#elif defined(DISPLAY_ILI9341)
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
// Example pin wiring for ILI9341 (change if your module uses different pins)
#define TFT_CS   10
#define TFT_DC   9
#define TFT_RST  8
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);
#else
// If no display driver chosen, compile but skip display init.
#endif

// Backlight pin (PWM)
const int BL_PIN = 12;

// Simple brightness sweep for demo
int brightness = 128;
int step = 5;

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); }
  Serial.println("GameBoy prototype firmware starting...");

  // Backlight PWM setup
  pinMode(BL_PIN, OUTPUT);
  analogWrite(BL_PIN, brightness);

#if defined(DISPLAY_ST7735) || defined(DISPLAY_ILI9341)
  Serial.println("Initializing display...");
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.setCursor(10, 30);
  tft.print("GameBoy Prototype");
  tft.setTextSize(1);
  tft.setCursor(10, 60);
  tft.print("Teensy 4.1 + TFT + I2S DAC");
#else
  Serial.println("No display driver selected. Skipping display init.");
#endif

  Serial.println("Setup done.");

  // AUDIO: placeholder
  // To use I2S/Audio output with Teensy, use the Teensy Audio library
  // and route output to the I2S pins (see journal notes). Example:
  // AudioMemory(8);
  // I2SOutput i2s;
  // i2s.begin();
  // (Actual code depends on how you generate/play audio.)
}

void loop() {
  // Simple demo: breathe backlight
  brightness += step;
  if (brightness <= 20 || brightness >= 235) step = -step;
  analogWrite(BL_PIN, brightness);

  // If display exists, show a changing indicator
#if defined(DISPLAY_ST7735) || defined(DISPLAY_ILI9341)
  static unsigned long last = 0;
  if (millis() - last > 250) {
    last = millis();
    static int dot = 0;
    tft.fillRect(10, 80, 100, 10, ILI9341_BLACK);
    for (int i = 0; i < dot; ++i) tft.fillRect(10 + i*8, 80, 6, 8, ILI9341_WHITE);
    dot = (dot + 1) % 6;
  }
#endif

  delay(30);
}
