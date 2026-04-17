#include "robot.h"

void Robot::SplitArcade(int dir, int turn){
    leftDrive.move(dir + turn);
    rightDrive.move(dir - turn);
}

void Robot::init(){
    //odm.initialise();
}

Position Robot::GetPosition(){
    //return odm.GetPosition();
    return {0, 0, 0};
}