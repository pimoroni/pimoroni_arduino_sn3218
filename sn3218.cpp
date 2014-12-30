/*
  si7021 - A library for the sn3218 18 channel LED driver
  2014/10/06 - Pimoroni Ltd.  http://www.pimoroni.com

  Usage:
    Make sure to include <Wire.h> or <USI_TWI_Master.h> and <TinyWireM.h> as appropriate.

	sn3218.begin();

	sn3218.enable_leds(SN3218_CH_00 + SN3218_CH_01); // Enable channel 0 and 1

	sn3218.set(0, 50); // Set channel 0 to 50/255

	sn3218.update();   // Signal the sn3218 to update outputs from its input registers

  This library is free software; you can redistribute it and/or modify it under the
  terms of the GNU General Public License as published by the Free Software
  Foundation; either version 2.1 of the License, or any later version.
  This program is distributed in the hope that it will be useful, but WITHOUT ANY
  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
  PARTICULAR PURPOSE.  See the GNU General Public License for more details.
*/
  
#include "sn3218.h"
#include <Arduino.h>

#ifdef __AVR_ATtiny85__
#include <TinyWireM.h>
#include <USI_TWI_Master.h>
#else
#include <Wire.h>
#endif

void _sn3218::begin(){
#ifdef __AVR_ATtiny85__
  TinyWireM.begin();
#else
  Wire.begin();
#endif
  this->enable();
}

void _sn3218::update(){
  this->writeReg(SN3218_CMD_UPDATE, 0x00); 
}

void _sn3218::reset(){
  this->writeReg(SN3218_CMD_RESET, 0x00);
  this->enable(); 
}

void _sn3218::enable(){
  this->writeReg(SN3218_CMD_ENABLE_OUTPUT, 0x01); 
}

void _sn3218::disable(){
  this->writeReg(SN3218_CMD_ENABLE_OUTPUT, 0x00); 
}

void _sn3218::enable_leds( unsigned long enable_mask ){
  this->writeReg(SN3218_CMD_ENABLE_LEDS, enable_mask & 0x3F);
  this->writeReg(SN3218_CMD_ENABLE_LEDS + 1, (enable_mask >> 6) & 0x3F);
  this->writeReg(SN3218_CMD_ENABLE_LEDS + 2, (enable_mask >> 12) & 0x3F);
  
  this->update();
}

void _sn3218::set( unsigned char chan, unsigned char val ){
  this->writeReg( SN3218_CMD_SET_PWM_VALUES + chan, val );
}

void _sn3218::writeReg( unsigned char reg, unsigned char val ){
#ifdef __AVR_ATtiny85__
  TinyWireM.beginTransmission(SN3218_ADDR);
  TinyWireM.send(reg);
  TinyWireM.send(val);
  TinyWireM.endTransmission();
#else
  Wire.beginTransmission(SN3218_ADDR);
  Wire.write(reg);
  Wire.write(val);
  Wire.endTransmission();
#endif
}
