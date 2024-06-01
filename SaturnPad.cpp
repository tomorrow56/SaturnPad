/*
* SaturnPad - Arduino library for interfacing with SEGA Saturn Controller
*
* Reference information: https://kaele.com/~kashima/games/saturn.html
* Copyright(c) @tomorrow56 all rights reserved
* Version: 1.0 (06/01/2024) - Created (@tomorrow56)
*/

#include "SaturnPad.h"
#include "Arduino.h"

SaturnPad::SaturnPad(int s0, int s1, int d0, int d1, int d2, int d3)
  : m_s0 (s0), m_s1 (s1), m_d0 (d0), m_d1 (d1), m_d2 (d2), m_d3 (d3)
{
  
}

void SaturnPad::begin()
{
  // init page pins  
  pinMode(m_s0, OUTPUT);
  pinMode(m_s1, OUTPUT);
  digitalWrite(m_s0, LOW);
  digitalWrite(m_s1, LOW);
  
  // init data pins
  pinMode(m_d0, INPUT_PULLUP);
  pinMode(m_d1, INPUT_PULLUP);
  pinMode(m_d2, INPUT_PULLUP);
  pinMode(m_d3, INPUT_PULLUP);
}

uint16_t SaturnPad::buttons(void)
{
  uint16_t ret = 0;
  uint8_t btn[4] = {0, 0, 0, 0};

  scanKeys();
  
  for(int j = 0; j < 4; j++){
    btn[0] += BtnData[0][j] << j ;
  }
  
  for(int j = 0; j < 4; j++){
    btn[1] += BtnData[1][j] << j ;
  }
  
  for(int j = 0; j < 4; j++){
    btn[2] += BtnData[2][j] << j ;
  }

  btn[3] = BtnData[3][3]<<3;

  ret = (btn[3]<<12) + (btn[2]<<8) + (btn[1]<<4) + btn[0];
  return ret;
}

void SaturnPad::page(uint8_t i){
  switch(i){
  case 0:
    digitalWrite(m_s0, LOW);
    digitalWrite(m_s1, LOW);
    break;
  case 1:
    digitalWrite(m_s0, HIGH);
    digitalWrite(m_s1, LOW);
    break;
  case 2:
    digitalWrite(m_s0, LOW);
    digitalWrite(m_s1, HIGH);
    break;
  case 3:
    digitalWrite(m_s0, HIGH);
    digitalWrite(m_s1, HIGH);
    break;
  default:
    digitalWrite(m_s0, LOW);
    digitalWrite(m_s1, LOW);
    break;
  }
}

void SaturnPad::scanData(uint8_t i){
  BtnData[i][0] = !digitalRead(m_d0);
  BtnData[i][1] = !digitalRead(m_d1);
  BtnData[i][2] = !digitalRead(m_d2);
  BtnData[i][3] = !digitalRead(m_d3);
}

void SaturnPad::scanKeys(void){
  for(int i = 0; i < 4; i++) {
    page(i);
    scanData(i);
  }
}

