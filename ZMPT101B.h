
/*
Created on Sat Sep 21 2019
author: ROMDHANA HEDI
email: romdhana@agroparistech.fr
ZMPT101B is an Arduino library that can be used for calibration and AC voltage reading from the ZMPT101B module.
*/

#ifndef ZMPT101B_h
#define ZMPT101B_h
#include <Arduino.h>


class ZMPT101B {
public:
	ZMPT101B(uint8_t _pin, uint16_t _frequency_MHz);
    float get_ac();
    void calibrate(float volt);
    void set_a_b(float a, float b);

private:
    uint16_t f;
	uint8_t pin;
    float a=1.0;
    float b=0.0;
    float mean();
};

#endif