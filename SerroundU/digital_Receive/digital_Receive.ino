#include "FastLED.h"
#define NUM_LEDS 9
#define DATA_PIN 6
int state = 0;
CRGB leds[NUM_LEDS];

   
void setup() {
 
 FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  Serial.begin(115200); // Default communication rate of the Bluetooth module
}

void loop() {


 
  
 if(Serial.available() > 0){ // if data available at serial port
    state = Serial.read(); // assign incoming data to variable state
    Serial.write(state);}
 
 // Controlling the LED
switch(state){
 case '1': {
  for(int i=0; i<=1;i++){
  leds[i] = CRGB::Red;
  }
 }
  break;
 case '2': {
  for(int i=0; i<=1;i++){
  leds[i+2] = CRGB::Blue;
  } 
    }

  break;

   case '3': {
  for(int i=0; i<=1;i++){
  leds[i+4] = CRGB::Green;
  } 
    }

  break;

 default: {
 for(int i=0; i<=5;i++){
  leds[i]= CRGB::Black;
  }
    }
  break;
 }
 
  FastLED.show();
   state = 0;
 
}
