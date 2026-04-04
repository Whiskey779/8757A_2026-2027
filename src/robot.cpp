#include "robot.h"

void Robot::driverInput(pros::Controller& master){
    int dir = master.get_analog(ANALOG_LEFT_Y);
    int turn = master.get_analog(ANALOG_RIGHT_X);
    leftDrive.move(dir - turn);
    rightDrive.move(dir + turn);
}