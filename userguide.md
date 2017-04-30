## Remote control

* Power: on / off 
* Up: 
* Down: 
* No audio: Reset to default parameters
* Left: slower color change (increase nb colors by 250)
* Right: faster color change (decrease nb colors by 250)
* Auto: Change the color mode (see below) from 0 -> 6

## Parameters

* A: Red intensity (0 -> 255)
* B: Green intensity (0 -> 255)
* C: Blue intensity (0 -> 255)
* D: Pump intensity (0 -> 255) : default 127
* E: Number of color (0 -> 32000), 25 colors per second
* F: Saturation (0 -> 1000) : default 1000
* G: Brightness (0 -> 1000) : default 1000
* H: color mode
  * 0 : changing color
  * 1 : fixed color
  * 2 : red
  * 3 : green
  * 4 : blue
  * 5 : red + blue
  * 6 : black
* P: status : 0 off, 1 pump, 2 light, 3 pump + lignt

## Connect

In order to connect from the terminal you may try to use 
`screen /dev/ACM0` if you are using a linux computer

Using this you are connected to the arduino and you have various options:
* `h` help
* `E123` set 123 colors
* `F1000` full saturation
* `G1000` set intensity to half full power
* `D127` half the power of the pump

## Color in manual mode

* `A0,0,255` Change parameters A, B and C (blue color)
* `E1` We have only one color, we go in manual mode


