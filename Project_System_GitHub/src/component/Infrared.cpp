#include "component/Infrared.hpp"

#include <Arduino.h>

Infrared::Infrared(const int far_left_pin,
		const int slight_left_pin,
		const int middle_pin,
		const int slight_right_pin,
		const int far_right_pin) :
	far_left_pin_    {far_left_pin}    ,
	slight_left_pin_ {slight_left_pin} ,
	middle_pin_      {middle_pin}      ,
	slight_right_pin_{slight_right_pin},
	far_right_pin_   {far_right_pin}
{
	if (far_left_pin_     != 0) pinMode(far_left_pin_    , INPUT);
	if (slight_left_pin_  != 0) pinMode(slight_left_pin_ , INPUT);
	if (middle_pin_       != 0) pinMode(middle_pin_      , INPUT);
	if (slight_right_pin_ != 0) pinMode(slight_right_pin_, INPUT);
	if (far_right_pin_    != 0) pinMode(far_right_pin_   , INPUT);
}

int Infrared::direction() const
{
	int far_left_pin     = digitalRead(far_left_pin_)     << 0;
	int slight_left_pin  = digitalRead(slight_left_pin_)  << 1;
	int middle_pin       = digitalRead(middle_pin_)       << 2;
	int slight_right_pin = digitalRead(slight_right_pin_) << 3;
	int far_right_pin    = digitalRead(far_right_pin_)    << 4;

	return     far_right_pin |
		slight_right_pin |
		      middle_pin |
		 slight_left_pin |
		    far_left_pin ;
}
