#include "component/SServo.hpp"

#include <Arduino.h>

SServo::SServo(const int pin) :
	pin_{pin}
{
	servo_.attach(pin_);
}

void SServo::angle(int angle) const
{
	if (angle > 15 || angle < -15)
		return;
	servo_.write(90 + angle);
}
