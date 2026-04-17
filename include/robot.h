#pragma once
#include "main.h"
#include "odometry.h"

class Robot{
    public:
        void SplitArcade(int dir, int turn);
        void init();
        Position GetPosition();
    private:
        pros::MotorGroup leftDrive = pros::MotorGroup({-6, 8, 10});
        pros::MotorGroup rightDrive = pros::MotorGroup({5, 13, -15});
        //Odometry odm = Odometry(1.0f, 20, 18, 11, 3.0f, 4.0f);

};