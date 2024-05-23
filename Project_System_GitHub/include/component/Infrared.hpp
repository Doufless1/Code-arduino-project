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

		int middle() const;
		int direction(const int slight, const int far) const;
		bool all_on() const;
	
	private:
		const int lleft_pin_;
		const int left_pin_;
		const int mid_pin_;
		const int right_pin_;
		const int rright_pin_;
};

#endif // COMPONENT_INFRARED_HPP
