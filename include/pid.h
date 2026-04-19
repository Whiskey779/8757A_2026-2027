#pragma once

namespace PID{

    struct Values{
        double Ki, Kp, Kd, integralStart;
    };

    double Calculate(Values v, double taget, double current);

    void Reset(double newError);

};