#ifndef COMPONENT_MOTOR_HPP
#define COMPONENT_MOTOR_HPP

class Motor
{
	public:
		Motor(const int lpwm_pin, const int rpwm_pin);

		void Motor::forwards(int speed) const;
		void Motor::backwards(int speed) const;
		void Motor::stop() const;
	
	private:
		const int lpwm_pin_;
		const int rpwm_pin_;
};

#endif // COMPONENT_MOTOR_HPP
