// Code by Leonardo Martinez
// For inquries, Leos32111@gmail.com

#include <FastLED.h>

#define NUM_LEDS 20
#define DATA_PIN 4

CRGB leds[NUM_LEDS];

// CHANGE NUM_COL FOR NUMBER OF PASTELS WITHIN THE ARRAY, ADD OR SUBTRACT AS MANY AS NEED
#define NUM_COL 5
CRGB colors[NUM_COL] = {CRGB(255,0,0), CRGB(255,172,0), CRGB(255,241,0), CRGB(11,255,0), CRGB(0,246,255)};

// delayTime serves as the breathing rate.
int delayTime = 10;

int c = 0;

void setup() { 
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

  fill_solid( leds, NUM_LEDS, colors[c]);
  FastLED.show();
}

void loop() { 
  for(int i = 255; i >= 0; i--)
  {
    FastLED.setBrightness(i);
    FastLED.delay(delayTime);
  }

  c++;

  if(c >= NUM_COL)
  {
    c = 0;
  }

  fill_solid( leds, NUM_LEDS, colors[c]);

  for(int i = 0; i <= 255; i++)
  {
    FastLED.setBrightness(i);
    FastLED.delay(delayTime);
  }
  
}

// Leonardo Martinez
