#pragma once
#include "main.h"
#include "odometry.h"

class Robot{
    public:
        void SplitArcade(int dir, int turn);
        void init();
        void HeadingUpdateLoop();
        void TurnHeading(double targetAngle);
        Position GetPosition();
    private:
        bool driveDisabled = false;
        bool traingMode = true;
        pros::MotorGroup leftDrive = pros::MotorGroup({-6, 8, 10});
        pros::MotorGroup rightDrive = pros::MotorGroup({5, 13, -15});
        Odometry odm;
};