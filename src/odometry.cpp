#include "odometry.h"
#include "angle.h"
#include "mutex.h"
#include <cmath>

void Odometry::initialise(){
    imu.reset(false);
    vertical.senesor.reset();
    horizontal.senesor.reset();
}

void Odometry::reset(){
    imu.tare();
    vertical.senesor.reset();
    horizontal.senesor.reset();
}

inline double Odometry::distanceTravled(const TrakingWheel &trackingWheel) const{
    return DegToRad(trackingWheel.senesor.get_position() * 100) * trackingWheel.radius;
}

Position Odometry::GetPosition(){
    Position pos;
    {
        MutexGuard mg(headingMtx);
        pos.heading = sumHeading;
    }
    pos.x = 2 * std::sin(pos.heading / 2) * (distanceTravled(horizontal) / pos.heading + horizontal.offset);
    pos.y = 2 * std::sin(pos.heading / 2) * (distanceTravled(vertical) / pos.heading + vertical.offset);
    return pos;
}

void Odometry::updateHeading(){
    double heading = DegToRad(imu.get_heading());
    double deltaHeading = calcAngleDif(preHeading, heading);
    preHeading = heading;
    MutexGuard mg(headingMtx);
    sumHeading += deltaHeading;
}