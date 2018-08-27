#ifndef TRILATERATION_H
#define TRILATERATION_H
#endif

#include <iostream>
#include <vector>
#include <Egien/Dense>

template <class T>
struct StationData {
    StationData (const T &pos, double dis)
        : _pos(pos), _dis(dis);
    T _pos;
    double _dis; 
};

typedef StationData<Eigen::Vector3d> PosData3d;
typedef vector<PosData3d> PosDataVec3d;

class Trilateration {
 public:
    Trilateration() { }
    ~Trilateration() { }
    Egien::Vector3d PosiCalcu(const PosDataVec3d &uwb_input);
};

