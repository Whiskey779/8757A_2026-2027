#pragma once

inline double DegToRad(double degAngle){
    return degAngle * 3.14159265358979323846 / 180;
}

inline double calcAngleDif(double initAngle, double finalAngle) {
    double diff = fmod(finalAngle - initAngle, 2 * M_PI);

    if (diff > M_PI) diff -= 2 * M_PI;
    else if (diff < -M_PI) diff += 2 * M_PI;

    return -diff;
}