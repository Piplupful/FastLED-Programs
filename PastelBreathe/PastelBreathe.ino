// Code by Leonardo Martinez
// For inquries, Leos32111@gmail.com

//      PROTOTYPE FOR PERSONAL BREATHING FASTLED PROGRAM      //

#include <FastLED.h>

#define NUM_LEDS 20
#define DATA_PIN 4

CRGB leds[NUM_LEDS];

// CHANGE NUM PASTELS FOR NUMBER OF PASTELS WITHIN THE ARRAY, ADD OR SUBTRACT AS MANY AS NEED
#define NUM_PASTELS 6
CRGB pastels[NUM_PASTELS] = {CRGB(253,154,162), CRGB(253,183,178), CRGB(254,218,193), CRGB(226,240,204), CRGB(181,235,215), CRGB(199,206,234)};

int delayTime = 10;
int c = 0;

void setup() { 
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

  fill_solid( leds, NUM_LEDS, pastels[c]);
  FastLED.show();
}

void loop() { 
  for(int i = 255; i >= 0; i--)
  {
    FastLED.setBrightness(i);
    FastLED.delay(delayTime);
  }

  c++;

  if(c > NUM_PASTELS)
  {
    c = 0;
  }

  fill_solid( leds, NUM_LEDS, pastels[c]);

  for(int i = 0; i <= 255; i++)
  {
    FastLED.setBrightness(i);
    FastLED.delay(delayTime);
  }
  
}

// Leonardo Martinez
