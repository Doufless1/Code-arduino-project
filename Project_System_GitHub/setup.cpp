//
// Created by onno1 on 04/05/2024.
//

#include "setup.h"
#include "setup.h"

Setup::Setup() {
    initializeSensors();
}

void Setup::initializeSensors() {
    pinMode(ir1, INPUT);
    pinMode(ir2, INPUT);
    pinMode(ir3, INPUT);
    pinMode(ir4, INPUT);
    pinMode(ir5, INPUT);
    pinMode(GYRO, INPUT);
    pinMode(echoPin, INPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(BUZZER, OUTPUT);
}

