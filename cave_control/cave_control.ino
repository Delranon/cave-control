/*********************************** INFO **************************************\
| 16 Button TTP229-LSF TouchPanel schaltet 9 Relais (10A 240V)für die           |
| Beleuchtung.                                                                  |
\*******************************************************************************/
/*********************************** CIRCUIT ***********************************\
| TouchPanel:                                                                   |
| VCC           5V                                                              |
| SCL           Pin 3                                                           |
| SDO           Pin 2                                                           |
| Library:      https://github.com/arduino12/ttp229-arduino                     |
|                                                                               |
| Relais:                                                                       |
| VCC           5V                                                              |
| Relais        Pin Pin 22 - Pin 45                                             |
|                                                                               |
\*******************************************************************************/
/****************************** Tastenbelegung ********************************\
/ 1 2 3       Licht an (Elektro - Modellbau - 3D Druck)   4 Licht aus          |
/ 5 6         Licht an (Main-PC - Sec-PC)                 8 Licht aus          |
/ 9 10 11 12  Monitor an  (1 - 4)                                              |
/ 13          Alles an (Demo Modus)                                            |
/ 16          Alles aus                                                        |
\******************************************************************************/

#include <TTP229.h>

const int SCL_PIN = 3;  // The pin number of the clock pin.
const int SDO_PIN = 2;  // The pin number of the data pin.

TTP229 ttp229(SCL_PIN, SDO_PIN); // TTP229(sclPin, sdoPin)

int Relais1 = 22;   // Licht Main-PC
int Relais2 = 24;   // Licht Sec-PC
int Relais3 = 26;   // Licht Elektro
int Relais4 = 28;   // Licht Modellbau
int Relais5 = 45;   // Licht 3D Druck
int Relais6 = 32;   // Monitor 1
int Relais7 = 34;   // Monitor 2
int Relais8 = 36;   // Monitor 3
int Relais9 = 38;   // Monitor 4

int Relais1State = 0;
int Relais2State = 0;
int Relais3State = 0;
int Relais4State = 0;
int Relais5State = 0;
int Relais6State = 0;
int Relais7State = 0;
int Relais8State = 0;
int Relais9State = 0;

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

digitalWrite(Relais1, HIGH);
digitalWrite(Relais2, HIGH);
digitalWrite(Relais3, HIGH);
digitalWrite(Relais4, HIGH);

digitalWrite(Relais5, HIGH);
digitalWrite(Relais6, LOW);
digitalWrite(Relais7, LOW);
digitalWrite(Relais8, LOW);

digitalWrite(Relais9, LOW);
}

void loop() 
{

  uint8_t key = ttp229.ReadKey16();
  if (key)
  {
   //Serial.println(key);
   if (key == 1)
      { if (Relais3State == 0)
        { digitalWrite(Relais3, LOW);
          Relais3State = 1;
        } else
        { digitalWrite(Relais3, HIGH);
          Relais3State = 0;
        }
      }
   if (key == 2)
      { if (Relais4State == 0)
        { digitalWrite(Relais4, LOW);
          Relais4State = 1;
        } else
        { digitalWrite(Relais4, HIGH);
          Relais4State = 0;
        }
      }
   if (key == 3)
      { if (Relais5State == 0)
        { digitalWrite(Relais5, LOW);
          Relais5State = 1;
        } else
        { digitalWrite(Relais5, HIGH);
          Relais5State = 0;
        }
      }
   if (key == 4)
        { workshopoff(500);    }
   if (key == 5)
      { if (Relais1State == 0)
        { digitalWrite(Relais1, LOW);
          Relais1State = 1;
        } else
        { digitalWrite(Relais1, HIGH);
          Relais1State = 0;
        }
      }
   if (key == 6)
      { if (Relais2State == 0)
        { digitalWrite(Relais2, LOW);
          Relais2State = 1;
        } else
        { digitalWrite(Relais2, HIGH);
          Relais2State = 0;
        }
      }
     if (key == 8)
        { pclightoff(500);    }
   if (key == 9)
      { if (Relais6State == 0)
        { digitalWrite(Relais6, HIGH);
          Relais6State = 1;
        } else
        { digitalWrite(Relais6, LOW);
          Relais6State = 0;
        }
      }
   if (key == 10)
       { if (Relais7State == 0)
        { digitalWrite(Relais7, HIGH);
          Relais7State = 1;
        } else
        { digitalWrite(Relais7, LOW);
          Relais7State = 0;
        }
       }
   if (key == 11)
       { if (Relais8State == 0)
         { digitalWrite(Relais8, HIGH);
           Relais8State = 1;
         } else
         { digitalWrite(Relais8, LOW);
           Relais8State = 0;
         }
       }
   if (key == 12)
       { if (Relais9State == 0)
        { digitalWrite(Relais9, HIGH);
          Relais9State = 1;
        } else
        { digitalWrite(Relais9, LOW);
          Relais9State = 0;
        }
       }
   if (key == 13)
       { allon(1000);    }
   if (key == 16)
      { alloff(500);    }
  }
}

void workshopoff(int pause)
{
  digitalWrite(Relais3, HIGH);
  Relais3State = 0;
  delay(pause);
  digitalWrite(Relais4, HIGH);
  Relais4State = 0;
  delay(pause);
  digitalWrite(Relais5, HIGH);
  Relais5State = 0;
}

void pclightoff(int pause)
{
  digitalWrite(Relais1, HIGH);
  Relais1State = 0;
  delay(pause);
  digitalWrite(Relais2, HIGH);
  Relais2State = 0;
}

void allon(int pause)
{
  digitalWrite(Relais1, LOW);
  Relais1State = 1;
    delay(pause);
  digitalWrite(Relais2, LOW);
  Relais2State = 1;
    delay(pause);
  digitalWrite(Relais3, LOW);
  Relais3State = 1;
  digitalWrite(Relais6, HIGH);
  Relais6State = 1;
    delay(pause);
  digitalWrite(Relais4, LOW);
  Relais4State = 1;
  digitalWrite(Relais7, HIGH);
  Relais7State = 1;
  delay(pause);
  digitalWrite(Relais5, LOW);
  Relais5State = 1;
  digitalWrite(Relais8, HIGH);
  Relais8State = 1;
    delay(pause);
  digitalWrite(Relais9, HIGH);
  Relais9State = 1;
}

void alloff(int pause)
{
  digitalWrite(Relais1, HIGH);
  Relais1State = 0;
  delay(pause);
  digitalWrite(Relais2, HIGH);
  Relais2State = 0;
  delay(pause);
  digitalWrite(Relais3, HIGH);
  Relais3State = 0;
  delay(pause);
  digitalWrite(Relais4, HIGH);
  Relais4State = 0;
  delay(pause);
  digitalWrite(Relais5, HIGH);
  Relais5State = 0;
  delay(pause);
  digitalWrite(Relais6, LOW);
  Relais6State = 0;
  delay(pause);
  digitalWrite(Relais7, LOW);
  Relais7State = 0;
  delay(pause);
  digitalWrite(Relais8, LOW);
  Relais8State = 0;
  delay(pause);
  digitalWrite(Relais9, LOW);
  Relais9State = 0;
}
