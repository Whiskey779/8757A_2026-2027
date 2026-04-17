#pragma once
#include "main.h"

struct Position{
    double heading, x, y;
};

struct TrakingWheel{
    pros::Rotation senesor;
    double radius;
    double distance;
};


class Odometry{
    public:
        void initialise();
        void reset();
        Position GetPosition() const;
    private:
        TrakingWheel horizontal = {pros::Rotation(20), 1, 3}, vertical = {pros::Rotation(18), 1, 4};
        pros::Imu imu = pros::Imu(11);

        double distanceTravled(const TrakingWheel& trackingWheel) const;
};
