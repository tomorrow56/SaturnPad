/*
* SaturnPad - Arduino library for interfacing with SEGA Saturn Controller
*
* Reference information: https://kaele.com/~kashima/games/saturn.html
* Copyright(c) tomorrow56 all rights reserved
*/

#ifndef SaturnPad_h
#define SaturnPad_h

#include <inttypes.h>
/* Con  - Wire     PCB
* 1 - VCC - blue     4
* 2 - D1  - green    3
* 3 - D0  - black    2
* 4 - S0  - orange   8
* 5 - S1  - red      9
* 6 - VCC - brown    5
* 7 - D3  - yellow   7
* 8 - D2  - gray     6
* 9 - GND - white    1
*/

/* Key Scan Format (D0-3: ON=LOW)
* |S0|S1||D3|D2|D1|D0|
* | 0| 0||R0| X| Y| Z|
* | 0| 1||St| A| C| B|
* | 1| 0|| R| L| D| U|
* | 1| 1||L0| 0| 1| 1|
*/

#define SEGA_Z      1
//0000_0000_0000_0001
#define SEGA_Y      2
//0000_0000_0000_0010
#define SEGA_X      4
//0000_0000_0000_0100
#define SEGA_R0     8
//0000_0000_0000_1000
#define SEGA_B      16
//0000_0000_0001_0000
#define SEGA_C      32
//0000_0000_0010_0000
#define SEGA_A      64
//0000_0000_0100_0000
#define SEGA_St     128
//0000_0000_1000_0000
#define SEGA_U      256
//0000_0001_0000_0000
#define SEGA_D      512
//0000_0010_0000_0000
#define SEGA_L      1024
//0000_0100_0000_0000
#define SEGA_R      2048
//0000_1000_0000_0000
#define SEGA_L0     32768
//1000_0000_0000_0000

class SaturnPad {

  public:
    SaturnPad();
  SaturnPad(int s0, int s1, int d0, int d1, int d2, int d3);
    void begin();
    uint16_t buttons();

  private:
  void page(uint8_t i);
  void scanData(uint8_t i);
  void scanKeys(void);
  int m_s0, m_s1, m_d0, m_d1, m_d2, m_d3;
  // Scan data of each pages
  uint8_t BtnData[4][4];

};

#endif

