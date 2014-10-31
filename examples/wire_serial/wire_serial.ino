#include <Wire.h>
#include "sn3218.h"

void setup()
{
  Serial.begin(9600);
  Serial.println("Hello World");
  //while(!Serial){}; // For Arduino Leonardo
  sn3218.begin();
  sn3218.enable_leds(SN3218_CH_ALL);
}

void loop()
{
  Serial.println("Enter brightness...");

  while(!Serial.available()){};

  unsigned char brightness = Serial.parseInt();

  int i;
  for( i = 0; i < SN3218_NUM_CHANNELS; i++ ){
    sn3218.set(i,brightness);
  }
  sn3218.update();

  Serial.print("Brightness set to: ");
  Serial.println(brightness);
}