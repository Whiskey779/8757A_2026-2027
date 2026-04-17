#include "odometry.h"
#include "angle.h"
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

inline double Odometry::distanceTravled(const TrakingWheel& trackingWheel) const{
    return DegToRad(trackingWheel.senesor.get_position() * 100) * trackingWheel.radius;
}
 
Position Odometry::GetPosition() const {
    Position pos;
    pos.heading = DegToRad(imu.get_heading());
    pos.x = 2 * std::sin(pos.heading/2) * (distanceTravled(horizontal)/pos.heading + horizontal.distance);
    pos.y = 2 * std::sin(pos.heading/2) * (distanceTravled(vertical)/pos.heading + vertical.distance);
    return pos;
}