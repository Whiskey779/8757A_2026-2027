#include "main.h"

class MutexGuard {
public:
    explicit MutexGuard(pros::Mutex& m) : mutex(m) {
        mutex.take();
    }

    ~MutexGuard() {
        mutex.give();
    }

    // prevent copying
    MutexGuard(const MutexGuard&) = delete;
    MutexGuard& operator=(const MutexGuard&) = delete;

private:
    pros::Mutex& mutex;
};