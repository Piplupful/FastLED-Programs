//Program by Chloe Perez
#include <FastLED.h>

// CHANGE ACCORDING TO YOUR SETUP
#define NUM_LEDS 21
#define DATA_PIN 4
//

CRGB leds[NUM_LEDS];
CRGB hold[NUM_LEDS];

// CHANGES RATE OF MOVEMENT
int delayTime = 50;

// FLAGSIZE AND COMPONENT 

#define flagSegmentTotal 5 // SEGMENTS TO A FLAG, EX/ 5 PARTS TO THE TRANS FLAG.
int flagSize = 15;
int flagCompSize = flagSize / flagSegmentTotal; // FLAG'S COMPONENT SIZE, EX/ 3 INDEXES THAT ARE JUST BLUE, OR WHITE.

// COLORS
CRGB biViolet = CRGB(217,2,113);
CRGB biPurp = CRGB(144, 73, 209);
CRGB biBlue = CRGB(21,57,169);

// ORDER OF COLORS
// !!!  CHANGE THE AMOUNT OF COLORS IN THE ARRAY IF YOU CHANGE THE FLAGSEGMENTTOTAL !!!

CRGB inputArray[flagSegmentTotal] = {biViolet,biViolet,biPurp,biBlue,biBlue};

//

void setup() { 
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

  //COLOR SEGMENTATION
  int itNum = 0;
  int count = 0;
  
  for(int i = 0; i < flagSegmentTotal; i++)
  { 
    int j = count;
    
    do
    {
      leds[j] = inputArray[itNum];
      
      j++;
      count++;
    }   while(j % flagCompSize != 0);

    itNum++;
  }

  //HOLD STORAGE FOR LOOP TO FUNCTION

  for(int i = 0; i < NUM_LEDS; i++)
  {
    hold[i] = leds[i];
  }
  
  FastLED.show();
}

//FLOW MODE LOOP
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
//Program by Chloe Perez
