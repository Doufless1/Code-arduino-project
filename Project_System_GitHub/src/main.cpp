#include "Car.hpp"

#include <Arduino.h>
#include <Servo.h>

/*Car car{
	Button(13),
	Buzzer(12),
	GyroScope(),
	Infrared(11, 10, 9, 8, 7),
	Motor(6, 5),
	SServo(4),
	UltraSound(3, 2)
};*/

Infrared i = Infrared(13, 12, 11, 10, 9);
Motor m = Motor(6, 5);
//SServo s = SServo(7); // TODO fix issue with Servo.
UltraSound u = UltraSound(3, 2);

Servo s;

void setup()
{
	s.attach(7);
}

void loop()
{
	static bool running = true;
	if (!running)
		return;

	if (i.all_on())
	{
		running = false;
		m.stop();
		return;
	}

	//s.angle(!i.middle() * i.direction(-11, 40));
	s.write(90 + !i.middle() * i.direction(-11, 40));
	m.move(32);

	int u_dis = u.distance();
	if (u_dis >= 44 && u_dis <= 46)
	{
		//s.angle(-30);
		s.write(90 - 30);
		m.move(35);

		delay(630);

		//s.angle(30);
		s.write(90 - 30);
		delay(630);
	}

	delay(50);
}
