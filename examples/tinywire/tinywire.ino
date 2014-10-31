#include <USI_TWI_Master.h>
#include <TinyWireM.h>
#include "sn3218.h"

void setup()
{
  sn3218.begin();
  sn3218.enable_leds(SN3218_CH_ALL);
}

void loop()
{
  int i;
  for( i = 0; i < SN3218_NUM_CHANNELS; i++ ){
    sn3218.set(i,255);
  }
  sn3218.update();
  delay(500);
}
