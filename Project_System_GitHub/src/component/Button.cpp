#include "component/Button.hpp"

#include <Arduino.h>

Button::Button(const int pin) :
	pin_{pin}
{
	pinMode(pin_, INPUT);
}

bool Button::pressed()
{
	const int DEBOUNCE_MS = 10;

	static int prev_state = LOW;
	static unsigned long prev_mil = millis();

	int curr_state = digitalRead(pin_);
	unsigned long curr_mil = millis();

	if (curr_state != prev_state && curr_mil - prev_mil > DEBOUNCE_MS)
	{
		prev_state = curr_state;
		prev_mil = curr_mil;

		return prev_state == LOW;
	}

	return false;
}
