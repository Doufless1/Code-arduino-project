#include "component/UltraSound.hpp"

#include <Arduino.h>

UltraSound::UltraSound(const int trigPin, const int echoPin) :
	trigPin_{trigPin},
	echoPin_{echoPin}
{
	pinMode(echoPin_, INPUT);
	pinMode(trigPin_, OUTPUT);
	digitalWrite(trigPin_, LOW);
}

bool UltraSound::is_obstacle() const
{
	return distance() < 30;
}

float UltraSound::distance() const
{
	digitalWrite(trigPin_, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin_, LOW);

	long duration_us = pulseIn(echoPin_, HIGH);
	float distance_cm = 0.017 * duration_us;
	return distance_cm;
}
