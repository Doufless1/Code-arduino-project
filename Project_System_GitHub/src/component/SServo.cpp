#include "component/SServo.hpp"

#include <Arduino.h>

SServo::SServo(const int pin) :
	pin_{pin}
{
	servo_.attach(pin_);
}

void SServo::angle(int angle) const
{
	servo_.write(90 + angle);
}
