#pragma once
#include "main.h"
#include "odometry.h"

class Robot{
    public:
        void SplitArcade(int dir, int turn);
        void init();
    private:
        pros::MotorGroup leftDrive = pros::MotorGroup({2, 1, 3});
        pros::MotorGroup rightDrive = pros::MotorGroup({4, 5, 9});
        Odometry odm = Odometry(1.0f, 12, 13, 14, 3.0f, 4.0f);

};