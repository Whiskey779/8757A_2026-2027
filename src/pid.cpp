#include "pid.h"
#include <cmath>

static double prevError = 0, integral = 0;

double PID::Calculate(PID::Values v, double target, double current){
    double error = target - current;
    integral += error;
    if(error == 0 || std::abs(error) > v.integralStart){
        integral = 0;
    }
    double derivative = error- prevError;
    prevError = error;

    return error * v.Kp + integral * v.Ki + derivative * v.Kd;
}

void PID::Reset(double newError){
    prevError = newError;
    integral = 0;
}