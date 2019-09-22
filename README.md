# [ZMPT101B](https://github.com/ROMDHANA/ZMPT101B-module)

https://github.com/ROMDHANA/ZMPT101B-module/wiki/ZMPT101B

ZMPT101B is an Arduino library that can be used for:
 - Calibration of ZMPT101B module
 - AC voltage reading
## 1. Calibration of ZMPT101B Module:
#include <ZMPT101B.h>

// ZMPT101B ac_sensor(pin,freq)

// pin: arduino pin connected to ZMPT101B module

// freq: AC Frequency in MHz

ZMPT101B ac_sensor(A0,50);

void setup()

{

  Serial.begin(9600);
  
  ac_sensor.calibrate(220);
  
}

void loop(){}

## 2. Get calibration parameters from Serial:
switch off source

Measure at 0 V => 0.11

switch on source...

Measure at 220.00 V => 81.56

Calibration is done:

a = 2.70, b = -0.30

## 3. Read voltage:
#include <ZMPT101B.h>

// ZMPT101B ac_sensor(pin,freq)

// pin: arduino pin connected to ZMPT101B module

// freq: AC Frequency in MHz

ZMPT101B ac_sensor(A0,50);

void setup()

{

  Serial.begin(9600);
  
  ac_sensor.set(2.70, -0.30);
  
}

void loop(){

 Serial.print(ac_sensor.get_ac();
 
 Serial.println(" Volt"))
 
 Delay(1000);
 }
