// TODO Code is incomplete.

#include "Car.hpp"

#include <Arduino.h>

Car::Car(const int button_pin,
		const int infrared_flpin,
		const int infrared_lpin,
		const int infrared_mpin,
		const int infrared_rpin,
		const int infrared_frpin,
		const int ultrasound_trigpin
		const int ultrasound_echopin) :
	button_{},
	gyroscope_{},
	infrared_{},
	steering_{},
	ultrasound_{}
{}

// TODO For the time being, this is all debugging code to see if the modules actually work.
void drive()
{
	/*static bool toggle;
	toggle_ = button_.pressed();
	if (!toggle_)
		return;*/
	Serial.print("Button |");
	Serial.print(" button pressed: ");
	Serial.print(button_.pressed());
	Serial.println("");

	Serial.print("GyroScope |");
	Serial.print();
	Serial.println("");

	Serial.print("Infrared |");
	Serial.print(" direction: ");
	Serial.print(infrared_.direction());
	Serial.print(" one on: ");
	Serial.print(infrared_.one_on());
	Serial.print(" all on: ");
	Serial.print(infrared_.all_on());
	Serial.println("");

	/*Serial.print("Steering |");
	Serial.print();
	Serial.println("");*/

	Serial.print("UltraSound |");
	Serial.print(" distance: ");
	Serial.print(ultrasound_.distance());
	Serial.println("");

	Serial.println("");
}
