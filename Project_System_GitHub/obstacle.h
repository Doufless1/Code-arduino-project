//
// Created by onno1 on 28/04/2024.
//

#ifndef PROJECT_SYSTEMS_OBSTACLE_H
#define PROJECT_SYSTEMS_OBSTACLE_H


class obstacle {

    //if an obstacle is detected the value is saved in cm
    int ob_distance=0;
public:

        //checks if there is an obstacle and returns true if so
        bool is_obstacle();

        //finds the distance of obstacle in car's path and returns that distance
        long get_distance();

        //steers car out of obstacle path
        void avoid_obstacle();  ///dont think i need




        //refind_line();
};


#endif //PROJECT_SYSTEMS_OBSTACLE_H
