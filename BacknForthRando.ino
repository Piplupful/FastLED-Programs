#include <FastLED.h>

#define NUM_LEDS 20
#define DATA_PIN 4

CRGB leds[NUM_LEDS];

int r = 255;
int g = 255;
int b = 255;

CRGB c = CRGB(r,g,b);

//CHANGES RATE OF MOVEMENT UP AND DOWN
int delayTime = 50;

void setup() { 
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() { 

  for(int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = c;
    FastLED.show();
    delay(delayTime);

    r = RGBrand(r);
    g = RGBrand(g);
    b = RGBrand(b);

    c = CRGB(r,g,b);
  }

  for(int i = NUM_LEDS - 1; i > 0; i--)
  {
    leds[i] = c;
    FastLED.show();
    delay(delayTime);

    r = RGBrand(r);
    g = RGBrand(g);
    b = RGBrand(b);

    c = CRGB(r,g,b);
  }
}

//CLAMP
int clamp(int org, int minCap, int maxCap)
{
  if(org > maxCap)
  {
    org = maxCap;
  }
  else if(org < minCap)
  {
    org = minCap;
  }

  return org;
}

//COINFLIP
int coinflip()
{
  int coin;
  
  int flip = random(0, 101);
  if((flip % 2) == 0)
  {
    coin = 0;
  }
  else
  {
    coin = 1;
  }

  return coin;
}

//RGB value randomizer
int RGBrand(int color)
{
  if(coinflip() == 0)
    {
      color += random(256);
    }
    else
    {
      color -= random(256);
    }

    color = clamp(color, 0, 255);

    return color;
}

// Leonardo Martinez
