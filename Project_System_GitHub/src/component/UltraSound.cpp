#include "component/UltraSound.hpp"

#include <Arduino.h>

const int trigPin = 9;
const int echoPin = 8;

UltraSound::UltraSound()
{
	pinMode(echoPin, INPUT);
	pinMode(trigPin, OUTPUT);
	digitalWrite(trigPin, LOW);
}

float UltraSound::distance()
{
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);

	long duration_us = pulseIn(echoPin, HIGH);
	float distance_cm = 0.017 * duration_us;
	return distance_cm;
}
