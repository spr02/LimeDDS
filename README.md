# LimeDDS - A GUI to configure the LimeDDS_GW
This project ist based on the LimeQt project and extends it with an simple configuration interface for the DDS core instantiated on the FPGA.

## Dependencies
This project requires LimeSuite, SoapySDR, QWT and alglib (and of course QT and QtCreator)
Steps listed for arch linux using pacaur:

```sh
pacman -S qwt
pacaur -S limesuite-git
pacaur -S soapysdr-git
pacaur -S alglib
```

## Build
Simply fire up QtCreator, load the LimeDDS.pro, configure project and hit build. Be sure to turn on compiler optimization, otherwise the RingBufferSPSC will not work as expected.

## Run
The application could be run directly or run through QTCreator.

## Code structre/Data flow

## TODO
a lot...
