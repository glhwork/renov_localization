#ifndef LOCALIZATION_H
#define LOCALIZATION_H

#include <cmath>
#include <eigen3/Eigen/Dense>

class Localization {
 public:
    Localization();
    virtual ~Localization() { };
    void KalmanFilter();
    void TimeOfAdvent();

 private:
    /* data */
};






















#endif