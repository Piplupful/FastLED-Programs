#include <FastLED.h>

#define NUM_LEDS 20
#define DATA_PIN 4

CRGB leds[NUM_LEDS];
CRGB hold[NUM_LEDS];

//CHANGES RATE OF MOVEMENT
int delayTime = 50;

//SIZE OF FLAG
//BREAK INTO 5 EQUAL SIZED PARTS

//ADD MATH LATER IDIOT
#define flagSize 15

int flagCompSize = 3;

CRGB flag[flagSize];

void setup() { 
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

  //TEMPORARY MATHES FOR PROTOTYPE
  for(int i = 0; i < 3; i++)
  {
    leds[i] = CRGB(88,200,243);
  }
  
  for(int i = 3; i < 6; i++)
  {
    leds[i] = CRGB(242, 138, 158);
  }

  for(int i = 6; i < 9; i++)
  {
    leds[i] = CRGB::White;
  }

  for(int i = 9; i < 12; i++)
  {
    leds[i] = CRGB(242, 138, 158);
  }

  for(int i = 12; i < 15; i++)
  {
    leds[i] = CRGB(88,200,243);
  }

  for(int i = 0; i < NUM_LEDS; i++)
  {
    hold[i] = leds[i];
  }

  FastLED.show();
}

void loop() {
  delay(100);
  
  for(int i = 0; i < NUM_LEDS; i++)
  {
    if(i < NUM_LEDS - 1)
    {
      leds[i+1] = hold[i];
    }
    else
    {
      leds[0] = hold[i];
    }
  }
  
  FastLED.show();

  for(int i = 0; i < NUM_LEDS; i++)
  {
    hold[i] = leds[i];
  }
}
