#include "main.h"

class Robot{
    public:
        void driverInput(pros::Controller& master);
    private:
        pros::MotorGroup leftDrive = pros::MotorGroup({2, 1, 3});
        pros::MotorGroup rightDrive = pros::MotorGroup({4, 5, 9});
};