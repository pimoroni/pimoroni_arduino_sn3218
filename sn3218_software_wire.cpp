/*
  This library is free software; you can redistribute it and/or modify it under the
  terms of the GNU General Public License as published by the Free Software
  Foundation; either version 2.1 of the License, or any later version.
  This program is distributed in the hope that it will be useful, but WITHOUT ANY
  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
  PARTICULAR PURPOSE. See the GNU General Public License for more details.
*/

#include "sn3218_software_wire.h"

sn3218_SoftwareWire::sn3218_SoftwareWire( uint8_t sda_pin, uint8_t scl_pin )
: wire(sda_pin, scl_pin){}

void sn3218_SoftwareWire::begin(){
  wire.begin();
  enable();
}

void sn3218_SoftwareWire::writeReg( unsigned char reg, unsigned char val )
{
  wire.beginTransmission(SN3218_ADDR);
  wire.write(reg);
  wire.write(val);
  wire.endTransmission();
}

