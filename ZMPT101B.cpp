/*
Created on Sat Sep 21 2019
author: ROMDHANA HEDI
email: romdhana@agroparistech.fr
ZMPT101B is an Arduino library that can be used for calibration and AC voltage reading from the ZMPT101B module.
*/
#include "ZMPT101B.h"

ZMPT101B::ZMPT101B(uint8_t _pin, uint16_t _f) {
	pin = _pin;
    f=_f;// frequency in MHz
}

void ZMPT101B::calibrate(float volt){
	Serial.println("switch off source");
	float x1=mean();
	Serial.println("Measure at 0 V => ");
	Serial.println(x1);
	Serial.println("switch on source...");
    delay(20000);
	float x2=mean();
	Serial.println("Measure at ");
	Serial.print(volt);
	Serial.print(" V => ");
	Serial.println(x2);
	a=volt/(x2-x1);
	b=-a*x1;
	Serial.println("Calibration is done:");
	Serial.print("a = ");
	Serial.print(a);
	Serial.print(", b = ");
	Serial.println(b);
}
float ZMPT101B::mean(){
	float s=0.0;
	for(int i=0;i<100;i++){
		delay(100);
		s+=get_ac();
	}
	return s/100;
}

void ZMPT101B::set_a_b(float _a, float _b){
    a=_a;
    b=_b;
}

float ZMPT101B::get_ac(){
	uint32_t dt = 1000000 / f;
	uint32_t t_start = micros();
	uint32_t s = 0, measurements_count = 0;
	int32_t val;
	while (micros() - t_start < dt) {
		val = analogRead(pin) - 510;
		s += val*val;
		measurements_count++;
	}
	return a*sqrt(s / measurements_count)+b;
}
