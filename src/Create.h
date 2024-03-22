//
// Created by reini on 22.03.24.
//

#ifndef MAIN_CREATE_H
#define MAIN_CREATE_H

#include <wallaby/wallaby.h>

class Create {

private:
    // declaration of constructor and destructor

    Create();
    ~Create();
public:
    // getInstance to get a new Create object

    static Create &getInstance() {
        static Create instance;
        return instance;
    }

    // method prototypes

    void drive(int speed, int time_ms);
    void turn(int speed, int time_ms);
    void drive_until_bump(int speed);
    void wiggle(int wiggles, int time_per_wiggle);
    void disconnect();
};

/**
 * Connect to the robot
 */
Create::Create() {
    create_connect();
}

/**
 * Destructor of the class
 *
 * Disconnects from the robot
 */
Create::~Create() {
    create_disconnect();
}

/**
 * Drive at a specific speed for a specified time
 *
 * @param speed integer speed value
 * @param time_ms time in ms
 */
void Create::drive(int speed, int time_ms) {
    create_drive_direct(speed, speed);
    msleep(time_ms);
    create_stop();
}

/**
 * Turn with a specifc speed for a specified time
 *
 * @param speed integer speed value
 * @param tims_ms time in ms
 */
void Create::turn(int speed, int tims_ms) {
    create_drive_direct(speed, -speed);
    msleep(tims_ms);
    create_stop();
}

/**
 * Drive until a bump has been detected by the Create
 *
 * @param speed integer speed value
 */
void Create::drive_until_bump(int speed) {
    while ((get_create_lbump() == 0) && (get_create_rbump() == 0))
    {
        create_drive_direct(speed, speed);
    }
    create_stop();
}

/**
 * Wiggles the robot
 *
 * @param wiggles How many time the robot should wiggle
 * @param time_per_wiggle time for one wiggle in ms
 */
void Create::wiggle(int wiggles, int time_per_wiggle) {

    for(int i = 0; i <= wiggles; i++) {
        turn(30 * i % 2 == 0 ? -1 : 1, time_per_wiggle);
    }
}

/**
 * Disconnects from the robot
 */
void Create::disconnect() {
    create_disconnect();
}

#endif //MAIN_CREATE_H
