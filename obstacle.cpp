//
// Created by onno1 on 28/04/2024.
//

#include <stdio.h>
#include "obstacle.h"
#include "steering.h"
#include <Arduino.h>

const int trigPin = 9;
const int echoPin = 10;

bool obstacle::is_obstacle(){

    long distance = get_distance();

    // no need to update ob_distance here because get_distance already does it

    return distance < 15 ;
}

void obstacle::avoid_obstacle(){
    const int speed = 10;

    steering steer;
    steer.steer(105);
    steer.drive(speed, true);
}

long obstacle::get_distance()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    long duration = pulseIn(echoPin, HIGH);
    long distance = duration * 0.034 / 2;

    ob_distance = distance;

    return distance;
}