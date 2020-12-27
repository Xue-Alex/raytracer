#ifndef RAY_H
#define RAY_H

#include "vec.h"

class ray {
public:
    ray();
    ray(const point& origin, const vec& direction);

    point origin() const;
    vec direction() const;

    point at(double t) const;

public:
    point orig;
    vec dir;
};


#endif