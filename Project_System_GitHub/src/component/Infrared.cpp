#include "component/Infrared.hpp"

#include <Arduino.h>

Infrared::Infrared(
		const int lleft_pin,
		const int left_pin,
		const int mid_pin,
		const int right_pin,
		const int rright_pin) :
	lleft_pin_{lleft_pin},
	left_pin_{left_pin},
	mid_pin_{mid_pin},
	right_pin_{right_pin},
	rright_pin_{rright_pin}
{
	pinMode(lleft_pin_, INPUT);
	pinMode(left_pin_, INPUT);
	pinMode(mid_pin_, INPUT);
	pinMode(right_pin_, INPUT);
	pinMode(rright_pin_, INPUT);
}

int Infrared::direction() const
{
	int llp = digitalRead(lleft_pin_);
	int lp = digitalRead(left_pin_) << 1;
	int mp = digitalRead(mid_pin_) << 2;
	int rp = digitalRead(right_pin_) << 3;
	int rrp = digitalRead(rright_pin_) << 4;
	return rrp | rp | mp | lp | llp;
}

bool Infrared::one_on() const
{
	return direction() != 0b00000;
}

bool Infrared::all_on() const
{
	return direction() == 0b11111;
}
