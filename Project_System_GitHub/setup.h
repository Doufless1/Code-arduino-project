//
// Created by onno1 on 04/05/2024.
//

//
// Created by onno1 on 04/05/2024.
//

#ifndef PROJECT_SYSTEMS_SETUP_H
#define PROJECT_SYSTEMS_SETUP_H

#include <Arduino.h>
#include "line.h"
#include "gyro.h"
#include "obstacle.h"

class Setup {
public:
    Setup();  // Constructor declaration
    const int BUZZER = 8;
private:
    void initializeSensors();
};

#endif //PROJECT_SYSTEMS_SETUP_H


#endif //PROJECT_SYSTEMS_SETUP_H
