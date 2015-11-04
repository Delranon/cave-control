/*
 * touchpad16_interrupt.ino
 *
 * Created: 5/27/2015 9:02:08 PM
 * Author: Steve Stover
 *
 * 16 Key Capacitive Touchpad using TTP229B IC
 * http://www.ebay.com/itm/371304274498
 *
 * The Touchpad has a jumper on TP1/SAHL for active high serial out
 *   and a jumper on TP2/KYSEL for 16-keys operation
 *
 * Processing the input via external interrupt INT1
 *   on an Arduino Nano v3.0
*/

#include <util/atomic.h>

#define CLR(x,y) (x&=(~(1<<y)))
#define SET(x,y) (x|=(1<<y))

#define clock_Pin 2
#define sdo_Pin 3

// Touchpad value
volatile uint16_t touchVal;  // var for ISR access
uint16_t touchValc;          // copy var for main loop
volatile int state = LOW;    // chmik

void setup() {
  Serial.begin(9600);
  Serial.print("Start...");
  pinMode(clock_Pin, OUTPUT);
  pinMode(sdo_Pin, INPUT);
  // set up INT1 on digital pin 3
 // EICRA = (1 << ISC11) | (1 << ISC10);  // external INT1 on rising edge
 // EIMSK = (1 << INT1);  // External Interrupt Request 1 Enable
 // sei();
 attachInterrupt(digitalPinToInterrupt(clock_Pin), touchVal, HIGH);
}

void loop() {
  ATOMIC_BLOCK(ATOMIC_FORCEON) {
    touchValc = touchVal;
  }
  if (touchValc) {
    Serial.print(touchValc, DEC);
    for (byte b = 0; b <= 15; b++) {
      if ((touchValc >> b) & 1) {
        Serial.print('\t'); Serial.print("bit "); Serial.print(b);
        Serial.print('\t'); Serial.print("pad "); Serial.print(b + 1);
      }
    }
    Serial.println();
  }
}

ISR(INT1_vect) {
  touchVal = 0;
  delayMicroseconds(100);
  for (byte i = 0; i <= 15; i++) {
    SET(PORTD, clock_Pin);
    delayMicroseconds(50);
    touchVal |= (digitalRead(sdo_Pin) << i);
    CLR(PORTD, clock_Pin);
    delayMicroseconds(50);
  }
}
