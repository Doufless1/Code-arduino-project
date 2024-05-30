#include "Car.hpp"

#include <Arduino.h>
#include <Servo.h>

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	static Car car{
		Button(4),
		Buzzer(8),
		GyroScope(A4, A5),
		Infrared(9, 10, 11, 12 , 13),
		Motor(6, 5),
		SServo(7),
		UltraSound(3, 2)
	};
	static bool running = false;

	if (car.is_button_pressed())
		running = !running;

	if (!running)
	{
		car.stop();
		car.look_straight();
		delay(10);
		return;
	}

	if (car.is_all_on())
	{
		car.stop();
		car.look_straight();
		car.play_music();

		running = false;
		return;
	}

	if (car.is_only_middle_on())
		car.move(33);
	else
		car.move(28);

	if (car.is_only_middle_on())
		car.look_straight();
	else if (car.is_any_on())
		car.change_angle(11, 30);

	if (car.detects_obstacle(44, 46))
		car.evade_obstacle(35, 30, 630);

	delay(10);
}
