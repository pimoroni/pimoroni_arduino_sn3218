/*
  SoftwareWire extension for the sn3218 led driver library

  Allows to have more than one sn3218 attached to an Arduino board. This is
  accomplished by using an in software implementation of the i2c protocol. You
  need 2 dedicated pins per sn3218 chip. One for i2c data and one for the clock.

  Requirements:
    Install the SoftwareWire library via the Arduino IDE.

  Usage:
    #include "sn3218_software_wire.h"

    sn3218_SoftwareWire driver_1(2, 3); // Pin 2 as SDA, pin 3 as SCL
    sn3218_SoftwareWire driver_2(10, 11); // Pin 10 as SDA, pin 11 as SCL

    driver_1.reset();
    driver_2.reset();
    driver_1.enable_leds(SN3218_CH_ALL);
    driver_2.enable_leds(SN3218_CH_ALL);
    driver_1.set(0, 20);
    driver_1.set(4, 60);
    driver_2.set(8, 20);
    driver_1.update();
    driver_2.update();

  Thanks to ZmeiGorynych for the base idea and to Koepel for SoftwareWire.

  This library is free software; you can redistribute it and/or modify it under the
  terms of the GNU General Public License as published by the Free Software
  Foundation; either version 2.1 of the License, or any later version.
  This program is distributed in the hope that it will be useful, but WITHOUT ANY
  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
  PARTICULAR PURPOSE. See the GNU General Public License for more details.
*/

#ifndef _SN3218_SOFTWARE_WIRE
#define _SN3218_SOFTWARE_WIRE

#include "SoftwareWire.h"
#include "sn3218.h"

class sn3218_SoftwareWire : public _sn3218
{
  public:
    sn3218_SoftwareWire( uint8_t sda_pin, uint8_t scl_pin );
    void begin();

  private:
    SoftwareWire wire;
    void writeReg( unsigned char reg, unsigned char val );
};

#endif
