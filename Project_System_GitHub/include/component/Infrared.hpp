#ifndef COMPONENT_INFRARED_HPP
#define COMPONENT_INFRARED_HPP

class Infrared
{
	public:
		Infrared(const int far_left_pin,
			const int left_pin,
			const int mid_pin,
			const int right_pin,
			const int far_right_pin);

		int direction();
		bool one_on();
		bool all_on();
	
	private:
		const int far_left_pin_;
		const int left_pin_;
		const int mid_pin_;
		const int right_pin_;
		const int far_right_pin_;
};

#endif // COMPONENT_INFRARED_HPP
