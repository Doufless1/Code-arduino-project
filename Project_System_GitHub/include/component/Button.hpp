#ifndef COMPONENT_BUTTON_HPP
#define COMPONENT_BUTTON_HPP

class Button
{
	public:
		Button(const int pin);
		bool pressed();
	
	private:
		const int pin_;
};


#endif // COMPONENT_BUTTON_HPP
