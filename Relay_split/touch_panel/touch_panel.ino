/**
 * The MySensors Arduino library handles the wireless radio link and protocol
 * between your home built sensors/actuators and HA controller of choice.
 * The sensors forms a self healing radio network with optional repeaters. Each
 * repeater and gateway builds a routing tables in EEPROM which keeps track of the
 * network topology allowing messages to be routed to nodes.
 *
 * Created by Henrik Ekblad <henrik.ekblad@mysensors.org>
 * Copyright (C) 2013-2015 Sensnology AB
 * Full contributor list: https://github.com/mysensors/Arduino/graphs/contributors
 *
 * Documentation: http://www.mysensors.org
 * Support Forum: http://forum.mysensors.org
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 *******************************
 *
 * DESCRIPTION
 *
 * Simple binary switch example 
 * Connect button or door/window reed switch between 
 * digitial I/O pin 3 (BUTTON_PIN below) and GND.
 * http://www.mysensors.org/build/binary
 */


#include <MySensor.h>
#include <SPI.h>
#include <Bounce2.h>
#include <TTP229.h>

#define CHILD_ID 3

const int SCL_PIN = 3;  // The pin number of the clock pin.
const int SDO_PIN = 2;  // The pin number of the data pin.

int oldValue=-1;
int oldValue2=-1;
int oldValue3=-1;
int oldValue4=-1;
int value;

TTP229 ttp229(SCL_PIN, SDO_PIN); // TTP229(sclPin, sdoPin)

MySensor gw;

// Change to V_LIGHT if you use S_LIGHT in presentation below
MyMessage msg(CHILD_ID,V_STATUS);
MyMessage msg2(CHILD_ID,V_STATUS);
MyMessage msg3(CHILD_ID,V_STATUS);
MyMessage msg4(CHILD_ID,V_STATUS);

void setup()  
{  
  gw.begin();
  
  // Register binary input sensor to gw (they will be created as child devices)
  // You can use S_DOOR, S_MOTION or S_LIGHT here depending on your usage. 
  // If S_LIGHT is used, remember to update variable type you send in. See "msg" above.
  gw.present(CHILD_ID, S_LIGHT);  
}


//  Check if digital input has changed and send in new value
void loop() 
{
   uint8_t key = ttp229.ReadKey16();
  if (key) 
  {
  if (key == 1) 
      { 
        gw.send(msg.set(value==HIGH ? 1 : 0));
        oldValue = value;
      }
  if (key == 2) 
      { 
        gw.send(msg2.set(value==HIGH ? 1 : 0));
        oldValue2 = value;
      }
  if (key == 3) 
      { 
        gw.send(msg3.set(value==HIGH ? 1 : 0));
        oldValue3 = value;
      }
  if (key == 4) 
      { 
        gw.send(msg4.set(value==HIGH ? 1 : 0));
        oldValue4 = value;
      }
  
  }
  
} 

