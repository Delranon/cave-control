/*********************************** INFO **************************************\
| 16 Button TTP229-LSF TouchPanel schaltet 12 Relais (10A 240V)für die          |
| Beleuchtung. Taste 1 - 12 die einzelnen Relais, 13 alles ein - mit 2 Sekunden |
| Last Verzögerung - Taste 16 alles aus - auch mit 2 Sekunden Last-Verzögerung  |
| MFRC522 RFID Modul                                                            |
\******************************************************************************/
/*********************************** CIRCUIT **********************************\
| TouchPanel:                                                                   |
| VCC           5V                                                              |
| SCL           Pin 3                                                           |
| SDO           Pin 2                                                           |
|                                                                               |
| Relais:                                                                       |
| VCC           5V                                                              |
| Relais        Pin Pin 22 - Pin 45                                             |
|                                                                               |
| RFID                                                                          |
| VCC          3.3 V 
| RST/Reset    Pin 5
| SPI SS       Pin 53     
| SPI MOSI     Pin 51       
| SPI MISO     Pin 50      
| SPI SCK      Pin 52  
\******************************************************************************/

#include <TTP229.h>

const int SCL_PIN = 3;  // The pin number of the clock pin.
const int SDO_PIN = 2;  // The pin number of the data pin.

TTP229 ttp229(SCL_PIN, SDO_PIN); // TTP229(sclPin, sdoPin)


int Relais1 = 22;
int Relais2 = 24;
int Relais3 = 26;
int Relais4 = 28;
int Relais5 = 45;
int Relais6 = 32;
int Relais7 = 34;
int Relais8 = 36;
int Relais9 = 38;
int Relais10 = 40;
int Relais11 = 42;
int Relais12 = 44;

int Relais1State = 0;
int Relais2State = 0;
int Relais3State = 0;
int Relais4State = 0;
int Relais5State = 0;
int Relais6State = 0;
int Relais7State = 0;
int Relais8State = 0;
int Relais9State = 0;
int Relais10State = 0;
int Relais11State = 0;
int Relais12State = 0;


void setup() {

  Serial.begin(115200);

pinMode(Relais1, OUTPUT);
pinMode(Relais2, OUTPUT);
pinMode(Relais3, OUTPUT);
pinMode(Relais4, OUTPUT);

pinMode(Relais5, OUTPUT);
pinMode(Relais6, OUTPUT);
pinMode(Relais7, OUTPUT);
pinMode(Relais8, OUTPUT);

pinMode(Relais9, OUTPUT);
pinMode(Relais10, OUTPUT);
pinMode(Relais11, OUTPUT);
pinMode(Relais12, OUTPUT);

digitalWrite(Relais1, HIGH);
digitalWrite(Relais2, HIGH);
digitalWrite(Relais3, HIGH);
digitalWrite(Relais4, HIGH);

digitalWrite(Relais5, HIGH);
digitalWrite(Relais6, HIGH);
digitalWrite(Relais7, HIGH);
digitalWrite(Relais8, HIGH);

digitalWrite(Relais9, HIGH);
digitalWrite(Relais10, HIGH);
digitalWrite(Relais11, HIGH);
digitalWrite(Relais12, HIGH);


}

void loop() 
{

  uint8_t key = ttp229.ReadKey16();
  if (key) 
  {
   //Serial.println(key);
   if (key == 1) 
      { if (Relais1State == 0)
        { digitalWrite(Relais1, LOW); 
          Relais1State = 1;
        } else
        { digitalWrite(Relais1, HIGH); 
          Relais1State = 0;
        }
      }
   if (key == 2) 
      { if (Relais2State == 0)
        { digitalWrite(Relais2, LOW); 
          Relais2State = 1;
        } else
        { digitalWrite(Relais2, HIGH); 
          Relais2State = 0;
        }
      }
   if (key == 3) 
      { if (Relais3State == 0)
        { digitalWrite(Relais3, LOW); 
          Relais3State = 1;
        } else
        { digitalWrite(Relais3, HIGH); 
          Relais3State = 0;
        }
      }
   if (key == 4) 
      { if (Relais4State == 0)
        { digitalWrite(Relais4, LOW); 
          Relais4State = 1;
        } else
        { digitalWrite(Relais4, HIGH); 
          Relais4State = 0;
        }
      }
   if (key == 5) 
      { if (Relais5State == 0)
        { digitalWrite(Relais5, LOW); 
          Relais5State = 1;
        } else
        { digitalWrite(Relais5, HIGH); 
          Relais5State = 0;
        }
      }
   if (key == 6) 
      { if (Relais6State == 0)
        { digitalWrite(Relais6, LOW); 
          Relais6State = 1;
        } else
        { digitalWrite(Relais6, HIGH); 
          Relais6State = 0;
        }
      }
   if (key == 7) 
      { if (Relais7State == 0)
        { digitalWrite(Relais7, LOW); 
          Relais7State = 1;
        } else
        { digitalWrite(Relais7, HIGH); 
          Relais7State = 0;
        }
      }
   if (key == 8) 
      { if (Relais8State == 0)
        { digitalWrite(Relais8, LOW); 
          Relais8State = 1;
        } else
        { digitalWrite(Relais8, HIGH); 
          Relais8State = 0;
        }
      }
   if (key == 9) 
      { if (Relais9State == 0)
        { digitalWrite(Relais9, LOW); 
          Relais9State = 1;
        } else
        { digitalWrite(Relais9, HIGH); 
          Relais9State = 0;
        }
      }
   if (key == 10) 
      { if (Relais10State == 0)
        { digitalWrite(Relais10, LOW); 
          Relais10State = 1;
        } else
        { digitalWrite(Relais10, HIGH); 
          Relais10State = 0;
        }
      }
   if (key == 11) 
      { if (Relais11State == 0)
        { digitalWrite(Relais11, LOW); 
          Relais11State = 1;
        } else
        { digitalWrite(Relais11, HIGH); 
          Relais11State = 0;
        }
      }
   if (key == 12) 
      { if (Relais12State == 0)
        { digitalWrite(Relais12, LOW); 
          Relais12State = 1;
        } else
        { digitalWrite(Relais12, HIGH); 
          Relais12State = 0;
        }
      }
    if (key == 13) 
      { allon();    }
  if (key == 16) 
       { alloff();    }
  }


}

void allon()
{
  digitalWrite(Relais1, LOW); 
  Relais1State = 1;
  delay(2000);
  digitalWrite(Relais2, LOW); 
  Relais2State = 1;
  delay(2000);
  digitalWrite(Relais3, LOW); 
  Relais3State = 1;
  delay(2000);
  digitalWrite(Relais4, LOW); 
  Relais4State = 1;
  delay(2000);
  digitalWrite(Relais5, LOW); 
  Relais5State = 1;
  delay(2000);
  digitalWrite(Relais6, LOW); 
  Relais6State = 1;
  delay(2000);
  digitalWrite(Relais7, LOW); 
  Relais7State = 1;
  delay(2000);
  digitalWrite(Relais8, LOW); 
  Relais8State = 1;
  delay(2000);
  digitalWrite(Relais9, LOW); 
  Relais9State = 1;
  delay(2000);
  digitalWrite(Relais10, LOW); 
  Relais10State = 1;
  delay(2000);
  digitalWrite(Relais11, LOW); 
  Relais11State = 1;
  delay(2000);
  digitalWrite(Relais12, LOW); 
  Relais12State = 1;
}

void alloff()
{ 
  digitalWrite(Relais1, HIGH); 
  Relais1State = 0;
  delay(2000);
  digitalWrite(Relais2, HIGH); 
  Relais2State = 0;
  delay(2000);
  digitalWrite(Relais3, HIGH); 
  Relais3State = 0;
  delay(2000);
  digitalWrite(Relais4, HIGH); 
  Relais4State = 0;
  delay(2000);
  digitalWrite(Relais5, HIGH); 
  Relais5State = 0;
  delay(2000);
  digitalWrite(Relais6, HIGH); 
  Relais6State = 0;
  delay(2000);
  digitalWrite(Relais7, HIGH); 
  Relais7State = 0;
  delay(2000);
  digitalWrite(Relais8, HIGH); 
  Relais8State = 0;
  delay(2000);
  digitalWrite(Relais9, HIGH); 
  Relais9State = 0;
  delay(2000);
  digitalWrite(Relais10, HIGH); 
  Relais10State = 0;
  delay(2000);
  digitalWrite(Relais11, HIGH); 
  Relais11State = 0;
  delay(2000);
  digitalWrite(Relais12, HIGH); 
  Relais12State = 0;
}
