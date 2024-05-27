#ifndef COMPONENT_INFRARED_HPP
#define COMPONENT_INFRARED_HPP

class Infrared
{
	public:
		Infrared(const int lleft_pin,
			const int left_pin,
			const int mid_pin,
			const int right_pin,
			const int rright_pin);

		int direction() const;
	
	private:
		const int far_left_pin_    ;
		const int slight_left_pin_ ;
		const int middle_pin_      ;
		const int slight_right_pin_;
		const int far_right_pin_   ;
};

#endif // COMPONENT_INFRARED_HPP
