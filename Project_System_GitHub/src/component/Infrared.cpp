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

int Infrared::middle() const
{
	int mp = digitalRead(mid_pin_);
	return mp;
}

int Infrared::direction(const int slight, const int far) const
{
	int llp = digitalRead(lleft_pin_);
	int lp = digitalRead(left_pin_);
	int rp = digitalRead(right_pin_);
	int rrp = digitalRead(rright_pin_);
	return rrp * (-1) * far +
		rp * (-1) * slight +
		lp * slight +
		llp * far;
}

bool Infrared::all_on() const
{
	int llp = digitalRead(lleft_pin_);
	int lp = digitalRead(left_pin_);
	int rp = digitalRead(right_pin_);
	int rrp = digitalRead(rright_pin_);
	return llp + lp + rp + rrp == 4;
}
