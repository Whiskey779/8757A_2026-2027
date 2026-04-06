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
        Odometry(float trakingWheelRadius, int horizontalTrackingWheelPort, int verticalTrackingWheelPort, int imuPort, float verticalDistanceTraking, float horizontalDistanceTraking);
        void initialise();
        void reset();
        Position GetPosition() const;
    private:
        TrakingWheel horizontal, vertical;
        pros::Imu imu;

        double distanceTravled(const TrakingWheel& trackingWheel) const;
};
