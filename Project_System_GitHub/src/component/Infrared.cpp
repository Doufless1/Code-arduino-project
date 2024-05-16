#incldude "component/Infrared.hpp"

#include <Arduino.h>

Infrared::Infrared(const int far_left_pin,
		const int left_pin,
		const int mid_pin,
		const int right_pin,
		const int far_right_pin) :
	far_left_pin_{far_left_pin},
	left_pin_{left_pin},
	mid_pin_{mid_pin},
	right_pin_{right_pin},
	far_right_pin_{far_right_pin}
{
	pinMode(far_left_pin_, INPUT);
	pinMode(left_pin_, INPUT);
	pinMode(mid_pin_, INPUT);
	pinMode(right_pin_, INPUT);
	pinMode(far_right_pin_, INPUT);
}

int Infrared::direction()
{
	int flp = digitalRead(far_left_pin_);
	int lp = digitalRead(left_pin_) << 1;
	int mp = digitalRead(mid_pin_) << 2;
	int rp = digitalRead(right_pin_) << 3;
	int frp = digitalRead(far_right_pin_) << 4;
	return frp + rp + mp + lp + flp;
}

bool Infrared::one_on()
{
	return direction() != 0b00000;
}

bool Infrared::all_on()
{
	return direction() == 0b11111;
}
