g//
// Created by reini on 22.03.24.
//

#include "Create.h"

int main() {

    // -- Variables --

    // ARM
    const int ARM = 3;
    const int arm_down = 1024;
    const int arm_under_noodle = 512;
    const int arm_high_tube = 464;
    const int arm_medium_tube = 332;
    const int arm_up = 0;
    const int arm_upper_hab = 54;
    const int arm_middle_hab = 482;
    const int arm_down_hab = 823;
    const int arm_hab_down = 923;


    // TILT
    const int TILT = 2;
    const int tilt_back = 1024;

    // MINISERVO
    const int MINI = 1;
    const int mini_closed = 1024;
    const int mini_open = 0;

    // HAND
    const int HAND = 0;


    //Connecting to the Create2
    auto &create = Create::getInstance();

    create.drive(100, 50);
    // -- Initialization --

    // assuming starting with our wooden precision tool at the perfect location

    //driving forward to take out the tool
    create.drive(50, 40);

    //giving us time to remove it
    msleep(100);

    //driving backwards into the starting position
    create.drive(-50, 40);

    //moving the arm into starting position
    enable_servo(ARM);
    set_servo_position(ARM, arm_down);

    //moving the tilt into starting position
    enable_servo(TILT);
    set_servo_position(TILT, tilt_back);

    //moving the mini servo into starting position
    enable_servo(MINI);
    set_servo_position(MINI, mini_closed);

    // opening motor to fit in starting box
    motor(HAND, 50);
    msleep(30);
    ao();

    //waiting for light & shutdown before game ends
    wait_for_light(0);
    shut_down_in(119);

    // -- Strategy --

    // turning out of start position - parallel to pipe
    create.turn(-10, 40);

    // driving straight to purple noodles
    create.drive(50, 50);

    //positioning to purple noodles
    create.turn(-5, 20);

    //positioning arm and waiting for noodles to fall + grabbing

    set_servo_position(ARM, arm_under_noodle);
    msleep(300);

    //moving motor just to the right position for the noodles to fall in
    motor(HAND, -30);
    msleep(30);
    ao();

    //turning back straight and driving till bumping
    create.turn(5, 20);
    create.drive_until_bump(80);

    //positioning over lava tube

    create.turn(-10, 30);
    set_servo_position(MINI, mini_open);
    set_servo_position(ARM, arm_high_tube);

    //letting go of purple noodle and wiggle to fit it in


    motor(HAND, -30);
    msleep(30);
    ao();

    create.wiggle(3, 1);

    //grabbing purple noodle again and driving back
    motor(HAND, -30);

    create.drive(-10, 10);

    //positioning over smaller lava tube
    set_servo_position(ARM, arm_medium_tube);

    //again letting go and wiggle it again
    motor(HAND, 30);
    msleep(30);
    ao();
    create.wiggle(3, 1);

    //aligning parallel to pvc pipe
    create.turn(-40, 34);

    //bumping against pvc pipe
    create.drive(-10, 10);

    //driving to first habitat and turning left to put it on (moving tilt, so we can grab it of the tower)
    create.drive(40, 56);
    set_servo_position(TILT, tilt_back);

    motor(HAND, -40);
    create.turn(30, 36);
    create.drive(10, 32);
    motor(HAND, 40);
    msleep(30);
    ao();

    //turing facing into starting of smaller starting box
    create.drive(-20, 34);
    create.turn(40, 56);

    //driving forward till bumping & putting arm up
    set_servo_position(ARM, arm_up);
    create.drive_until_bump(80);

    //driving back a little and putting the habitats on construct
    create.drive(-10, 12);

    //first habitat
    create.turn(10, 22);
    create.drive(10, 20);
    set_servo_position(ARM, arm_upper_hab);
    motor(HAND, -40);
    set_servo_position(ARM, arm_up);
    create.turn(40,35);

    set_servo_position(ARM, arm_hab_down);
    motor(HAND, 40);
    msleep(30);
    ao();
    set_servo_position(ARM, arm_up);

    //second habitat
    create.turn(-40, 35);
    set_servo_position(ARM, arm_middle_hab);
    motor(HAND, -40);
    set_servo_position(ARM, arm_up);
    create.turn(40, 42);
    set_servo_position(ARM, arm_hab_down);
    motor(HAND, 40);
    msleep(30);
    ao();
    set_servo_position(ARM, arm_up);

    //third habitat

    create.turn(-40, 42);
    set_servo_position(ARM, arm_down_hab);
    motor(HAND, -40);
    set_servo_position(ARM, arm_up);
    create.turn(40, 47);
    set_servo_position(ARM, arm_hab_down);

    motor(HAND, 40);
    msleep(30);
    ao();




    //Disconnecting from the Create2
    create.disconnect();
}

