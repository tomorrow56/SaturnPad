/*
* SaturnPad - Arduino library for interfacing with SEGA Saturn Controller
*
* Reference information: https://kaele.com/~kashima/games/saturn.html
*
* Serial print example
* Copyright(c) tomorrow56 all rights reserved
*/

#include <SaturnPad.h>

// Key Scan Format (D0-3: ON=LOW)
// |S0|S1||D3|D2|D1|D0|
// | 0| 0||R0| X| Y| Z|
// | 0| 1||St| A| C| B|
// | 1| 0|| R| L| D| U|
// | 1| 1||L0| 0| 1| 1|

// Key Name macros
// SEGA_Z      B0000000000000001
// SEGA_Y      B0000000000000010
// SEGA_X      B0000000000000100
// SEGA_R0     B0000000000001000
// SEGA_B      B0000000000010000
// SEGA_C      B0000000000100000
// SEGA_A      B0000000001000000
// SEGA_St     B0000000010000000
// SEGA_U      B0000000100000000
// SEGA_D      B0000001000000000
// SEGA_L      B0000010000000000
// SEGA_R      B0000100000000000
// SEGA_L0     B1000000000000000

#define S0 38
#define S1 39
#define D0 5
#define D1 6
#define D2 7
#define D3 8

SaturnPad SEGA = SaturnPad(S0, S1, D0, D1, D2, D3);
uint16_t state = 0;
uint16_t oldstate = 0;

void setup()
{
    Serial.begin(115200);
    SEGA.begin();
}

void loop()
{
  state = SEGA.buttons();

  if(state != oldstate){
    //Serial.println(state);
    if(state & SEGA_St){
      Serial.println("Start");
    }
    if(state & SEGA_Z){
      Serial.println("Z");
    }
    if(state & SEGA_Y){
      Serial.println("Y");
    }
    if(state & SEGA_X){
      Serial.println("X");
    }
    if(state & SEGA_A){
      Serial.println("A");
    }
    if(state & SEGA_B){
      Serial.println("B");
    }
    if(state & SEGA_C){
      Serial.println("C");
    }
    if(state & SEGA_R0){
      Serial.println("R_BTN");
    }
    if(state & SEGA_L0){
      Serial.println("L_BTN");
    }
    if(state & SEGA_U){
      Serial.println("UP");
    }
    if(state & SEGA_D){
      Serial.println("DOWN");
    }
    if(state & SEGA_L){
      Serial.println("LEFT");
    }
    if(state & SEGA_R){
      Serial.println("RIGHT");
    }
  }
  oldstate = state;

  delay(100);
}
