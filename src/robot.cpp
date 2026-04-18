#include "robot.h"
#include <cmath>

void Robot::SplitArcade(int dir, int turn){
    if(traingMode){
        if(!driveDisabled){
            if(std::abs(dir) > 114 || std::abs(turn) > 114){
                driveDisabled = true;
                leftDrive.move(0);
                rightDrive.move(0);
            }
            else{
                leftDrive.move(dir + turn);
                rightDrive.move(dir - turn);
            }
            
        }
        else if(dir == 0 && turn == 0) driveDisabled = false;
    }
    else{
        leftDrive.move(dir + turn);
        rightDrive.move(dir - turn);
    }
}

void Robot::init(){
    odm.initialise();
}

Position Robot::GetPosition(){
    Position relativePos = odm.GetPosition();
    Position absPos;
    absPos.heading = std::atan2(std::sin(relativePos.heading), std::cos(relativePos.heading)) * 180 / M_PI;
    absPos.x = relativePos.x * (relativePos.heading/2);
    absPos.y = relativePos.y * (relativePos.heading/2);
    return absPos;
}

void Robot::HeadingUpdateLoop(){
    while(true){
        odm.updateHeading();
        pros::delay(10);
    }
}