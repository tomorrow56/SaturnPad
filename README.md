# SaturnPad-Arduino
SEGA Saturn Controller Arduino Library

Copyright(c) tomorrow56 all rights reserved
 twitter(a.k.a X): @tomorrow56

### Reference information:
https://kaele.com/~kashima/games/saturn.html


### Wire Connetion Information
 Sturn Connector - Sig - Wire - PCB connector
 1 - VCC - blue - 4
 2 - D1  - green - 3
 3 - D0  - black - 2
 4 - S0  - orange - 8
 5 - S1  - red - 9
 6 - VCC - brown - 5
 7 - D3  - yellow - 7
 8 - D2  - gray - 6
 9 - GND - white - 1

### Key Scan Format (D0-3: ON=LOW)
|S0|S1|D3|D2|D1|D0|
|--|--|--|--|--|--|
| 0| 0||R0| X| Y| Z|
| 0| 1||St| A| C| B|
| 1| 0|| R| L| D| U|
| 1| 1||L0| 0| 1| 1|
