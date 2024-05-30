#include "Car.hpp"

#include <Arduino.h>
#include <Servo.h>

void setup()
{}

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

	if (car.detects_obstacle(45, 50))
		car.evade_obstacle(40, 30, 750);

	/*if (car.is_tilted(120))
		*/

	delay(10);
}
