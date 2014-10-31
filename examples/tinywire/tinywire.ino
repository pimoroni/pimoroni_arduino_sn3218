#include <USI_TWI_Master.h>
#include <TinyWireM.h>
#include "sn3218.h"

void setup()
{
  sn3218.begin();
  sn3218.enable_leds(SN3218_CH_ALL);
}

int brightness = 255;
int direction = 0;

void loop()
{
  int channel;
  for( channel = 0; channel < SN3218_NUM_CHANNELS; channel++ ){
    sn3218.set(channel,brightness);
  }
  sn3218.update();
  delay(5);
  
  if( direction ){
    brightness++;
  }else{
    brightness--;
  }
  
  if(brightness == 0){direction = 1;} 
  if(brightness == 255){direction = 0;}
}