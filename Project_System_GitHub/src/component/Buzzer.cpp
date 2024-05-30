#include "component/Buzzer.hpp"

#include <Arduino.h>

Buzzer::Buzzer(const int pin) :
	pin_{pin}
{
	if (pin_ != 0) pinMode(pin_, OUTPUT);
}

void Buzzer::play(int note, int duration) const
{
	duration = 1000 / duration;
	tone(pin_, note, duration);
	int pause = duration * 1.30;
	delay(pause);
	noTone(pin_);
}
