#include "component/Buzzer.hpp"

#include <Arduino.h>

Buzzer::Buzzer(const int pin) :
	pin_{pin}
{}

void Buzzer::play() const
{
	const int G3 = 196;
	const int A3 = 220;
	const int B3 = 247;
	const int C4 = 262;

	struct
	{
		int note;
		int duration;
	} melody[] =
	{
		{C4, 4},
		{G3, 8},
		{G3, 8},
		{A3, 4},
		{G3, 4},
		{0 , 4},
		{B3, 4},
		{C4, 4}
	};
	const int len = sizeof(melody) / sizeof(melody[0]);
	
	for (int i = 0; i < len; i++) {
		int duration = 1000 / melody[i].duration;
		tone(pin_, melody[i].note, duration);

		int pause = duration * 1.30;
		delay(pause);
		noTone(pin_);
	}
}
