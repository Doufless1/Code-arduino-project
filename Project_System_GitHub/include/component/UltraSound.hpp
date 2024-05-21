#ifndef COMPONENT_ULTRASOUND_HPP
#define COMPONENT_ULTRASOUND_HPP

class UltraSound
{
	public:
		UltraSound(const int trigPin, const int echoPin);
		bool is_obstacle() const;
		float distance() const;
	
	private:
		const int trigPin_;
		const int echoPin_;
};


#endif // COMPONENT_ULTRASOUND_HPP
