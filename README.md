#TO52 : SmartHome / Clock
Development project at UTBM school.

Full project and documentation [HERE !](https://github.com/alexgus/SmartHome "Doc")

This project intends to make ring a board (Raspberry Pi, Arduino, ...) with internet access and some free pin (for button and output the ring's melody). For make it ringing you just have to send a MQTT frame !

## MQTT commands
Used MQTT for ringing on the board. Topic is `/clock`. Payload commands are :
 * `RING` : for make ring the clock
 * `SNOOZE` : not used for now
 * `ABORT` : not used for now
 * `DISMISS` : not used for now
 * `CONF_DELAY [integer value]` : for configuring the delay when the user pushs the SNOOZE button

## Configuration
Configurations of the MQTT broker have to be set in the code for the moment. Extern configuration file will be configured later (host, port, subscribed topic). Pin mapped to the board will also be in this file.

## Used library
MQTT library : Paho for linux (c mapping, not c++, for embed it easily in all devices)
https://www.eclipse.org/paho/clients/c/
OpenSSL library : used by MQTT PAHO

## Compilation
For now, just type `make` in the `Debug` folder. It will create the `SmartHome-Clock` executable. If you do not have the paho library installed on your system, this won't work !

For automated installation see scripts [here.](https://github.com/alexgus/SmartHome "Doc installation") Also look for dependencies !
