#ifndef TRILATERATION_H
#define TRILATERATION_H
#endif

#include <iostream>
#include <Egien>

template <class T>
struct StationData {
    StationData (const T pos, double dis)
        : _pos(pos), _dis(dis);
    
}