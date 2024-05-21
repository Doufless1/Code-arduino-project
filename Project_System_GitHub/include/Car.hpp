#ifndef CAR_HPP
#define CAR_HPP

#include "component/Button.hpp"
#include "component/Buzzer.hpp"
#include "component/GyroScope.hpp"
#include "component/Infrared.hpp"
#include "component/Motor.hpp"
#include "component/SServo.hpp"
#include "component/UltraSound.hpp"

class Car
{
	public:
		Car(Button button, Buzzer buzzer, GyroScope gyroscope, Infrared infrared, Motor motor, SServo servo, UltraSound ultrasound);

		Button getButton() const;
		Buzzer getBuzzer() const;
		GyroScope getGyroScope() const;
		Infrared getInfrared() const;
		Motor getMotor() const;
		SServo getSServo() const;
		UltraSound getUltraSound() const;

	private:
		Button button_;
		Buzzer buzzer_;
		GyroScope gyroscope_;
		Infrared infrared_;
		Motor motor_;
		SServo servo_;
		UltraSound ultrasound_;
};

#endif // CAR_HPP
