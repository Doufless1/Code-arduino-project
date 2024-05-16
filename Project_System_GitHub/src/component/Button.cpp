#include "component/Button.hpp"

#include <Arduino.h>

Button::Button(const int pin) :
	pin_{pin}
{
	pinMode(pin_, INPUT);
}

// TODO Debounce.
bool Button::pressed()
{
	return digitalRead(pin_);
}
