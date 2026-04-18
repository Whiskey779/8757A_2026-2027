#pragma once
#include "main.h"

struct Position{
    double heading, x, y;
};

struct TrakingWheel{
    pros::Rotation senesor;
    double radius;
    double offset;
};


class Odometry{
    public:
        void initialise();
        void reset();
        void updateHeading();
        Position GetPosition();
    private:
        TrakingWheel horizontal = {pros::Rotation(20), 1, 3}, vertical = {pros::Rotation(18), 1, 4};
        pros::Imu imu = pros::Imu(11);
        double preHeading = 0;
        double sumHeading = 0;
        pros::rtos::Mutex headingMtx;

        double distanceTravled(const TrakingWheel& trackingWheel) const;
};
