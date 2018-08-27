#ifndef LOCALIZATION_H
#define LOCALIZATION_H

#include <cmath>
#include <Eigen>

class Localization {
 public:
    Localization();
    virtual ~Localization() { };
    void Localization::KalmanFilter();
    void Localization::TimeOfAdvent();

 private:
    /* data */
};






















#endif