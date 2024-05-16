#ifndef CAR_HPP
#define CAR_HPP

#include "component/Gyroscope.hpp"
#include "component/Infrared.hpp"
#include "component/Steering.hpp"
#include "component/Ultrasound.hpp"

class Car
{
	public:
		Car();

	private:
		Gyroscope gyroscope_;
		Infrared infrared_;
		Steering steering_;
		Ultrasound ultrasound_;
};

#endif // CAR_HPP
