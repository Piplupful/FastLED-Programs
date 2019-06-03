// Code by Leonardo Martinez
// For inquries, Leos32111@gmail.com

#include <FastLED.h>

#define NUM_LEDS 20
#define DATA_PIN 4

CRGB leds[NUM_LEDS];
CRGB holdLEDS[NUM_LEDS];

int delayTime = 150;

// INITIAL VALUES AND THEIR CLAMPING MIN AND MAXES.
int sR = 55;
int hR = sR;
int minR = 55;
int maxR = 100;
int devR = 30;

int sG = 198;
int hG = sG;
int minG = 175;
int maxG = 255;
int devG = 55;

int sB = 229;
int hB = sB;
int minB = 140;
int maxB = 255;
int devB = 30;
// TO CHANGE COLOR SETTINGS, USE ABOVE VALUES.
// DEV(R/G/B) is the deviation range of each addition or subtraction from the original value.
// Clamp ensures that the changes stay within a good range.

// VARIATION RANGE FOR PRIOR INDEXES
// USED TO SLIGHTLY VARY INDEXES THAT HAVE BEEN ALTERED BEFORE AS TO SIMULATE SMALL CHANGES IN LIQUID LIGHT REFRACTION.
int priorVarR = 10;
int priorVarG = 10;
int priorVarB = 0;
//

CRGB start = CRGB(sR,sG,sB);
CRGB hold = start;

int coin = 0;

void setup() { 
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

int itFlag;

void loop() { 
  for(int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = hold;
    itFlag = i;
    delay(delayTime);
    FastLED.show();

    if(holdLEDS[i] == CRGB(0,0,0))
    {
      holdLEDS[i] = leds[i];
    }

    //R
    coin = coinflip();
    if(coin == 0)
    {
      hR = hR + random(0,devR);
    }
    else
    {
      hR = hR - random(0,devR);
    }

    hR = clamp(hR, minR, maxR);

    //G
    coin = coinflip();
    if(coin == 0)
    {
      hG = hG + random(0,devG);
    }
    else
    {
      hG = hG - random(0,devG);
    }

    hG = clamp(hG, minG, maxG);

    //B
    coin = coinflip();
    if(coin == 0)
    {
      hB = hB + random(0,devB);
    }
    else
    {
      hB = hB - random(0,devB);
    }

    hB = clamp(hB, minB, maxB);

    //HOLD
    hold = CRGB(hR,hG,hB);

    for(int i = 0; i < NUM_LEDS; i++)
    {
      if((i != itFlag) && (leds[i] != CRGB(0,0,0)))
      {
        // R G B OF PRIOR ITERATIONS TO BE SLIGHTLY CHANGED;
        holdLEDS[i] = randSmallRGB(holdLEDS[i], priorVarR, priorVarG, priorVarB);
        leds[i] = holdLEDS[i];
        FastLED.show();
      }
    }
  }
}

//CLAMP by Leonardo Martinez
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

CRGB randSmallRGB(CRGB org, int r, int g, int b)
{
  int currentRGB;
  
  if(coinflip() == 0)
  {
    currentRGB = org.r + r;
  }
  else
  {
    currentRGB = org.r - r;
  }
  currentRGB = clamp(currentRGB, minR, maxR);
  org.r = currentRGB;
  
  if(coinflip() == 0)
  {
    currentRGB = org.g + g;
  }
  else
  {
    currentRGB = org.g - g;
  }
  currentRGB = clamp(currentRGB, minG, maxG);
  org.g = currentRGB;
  
  if(coinflip() == 0)
  {
    currentRGB = org.b + b;
  }
  else
  {
    currentRGB = org.b - b;
  }
  currentRGB = clamp(currentRGB, minB, maxB);
  org.b = currentRGB;

  return org;
}

// Leonardo Martinez
