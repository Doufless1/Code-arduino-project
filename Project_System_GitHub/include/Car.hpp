#ifndef CAR_HPP
#define CAR_HPP

#include "component/Button.hpp"
#include "component/GyroScope.hpp"
#include "component/Infrared.hpp"
#include "component/Steering.hpp"
#include "component/UltraSound.hpp"

class Car
{
	public:
		Car(const int button_pin,
			const int infrared_flpin,
			const int infrared_lpin,
			const int infrared_mpin,
			const int infrared_rpin,
			const int infrared_frpin,
			const int ultrasound_trigpin
			const int ultrasound_echopin);
		void drive();

	private:
		Button button_;
		GyroScope gyroscope_;
		Infrared infrared_;
		Steering steering_;
		UltraSound ultrasound_;
};

#endif // CAR_HPP
