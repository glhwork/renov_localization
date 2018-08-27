#ifndef TRILATERATION_H
#define TRILATERATION_H


#include <iostream>
#include <vector>
#include <cmath>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/SVD>

namespace Trila {

template <class T>
struct StationData {
    StationData (const T &pos, double dis)
        : _pos(pos), _dis(dis) { }
    T _pos;
    double _dis; 
};

typedef StationData<Eigen::Vector3d> PosData3d;
typedef std::vector<PosData3d> PosDataVec3d;

class Trilateration {
 public:
    Trilateration() { }
    ~Trilateration() { }
    Eigen::Vector3d PosiCalcu(const PosDataVec3d &uwb_input);
};

}

#endif