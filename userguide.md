## Parameters

* A: Red intensity (0 -> 255)
* B: Green intensity (0 -> 255)
* C: Blue intensity (0 -> 255)
* D: Pump intensity (0 -> 255)
* E: Number of color (0 -> 32000)
* F: Saturation (0 -> 1000)
* G: Brightness (0 -> 1000)

## Connect

In order to connect from the terminal you may try to use 
`screen /dev/ACM0` if you are using a linux computer

Using this you are connected to the arduino and you have various options:
* `h` help
* `E123` set 123 colors
* `F1000` full saturation
* `G1000` set intensity to half full power
* `D127` half the power of the pump


