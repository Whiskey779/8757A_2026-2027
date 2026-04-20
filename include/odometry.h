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
        Odometry(int imuPort, int verticalTrackingPort, double verticalTrackingOffset, int horizontalTrackingPort, double horizontalTrackingOffset, double trackingWheelRadius);
    private:
        TrakingWheel horizontal, vertical;
        pros::Imu imu;
        double preHeading = 0;
        double sumHeading = 0;
        pros::rtos::Mutex headingMtx;

        double distanceTravled(const TrakingWheel& trackingWheel) const;
};
