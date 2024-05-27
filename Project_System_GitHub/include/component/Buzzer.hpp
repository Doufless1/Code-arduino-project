#ifndef COMPONENT_BUZZER_HPP
#define COMPONENT_BUZZER_HPP

class Buzzer
{
	public:
		Buzzer(const int pin);
		void play(const int note, const int duration) const;
	
	private:
		const int pin_;
};

#endif // COMPONENT_BUZZER_HPP
