#include "ray.h"


ray::ray() {};

ray::ray(const point &origin, const vec &direction)
{
    orig = origin;
    dir = direction;
}

point ray::origin() const
{
    return orig;
}

vec ray::direction() const
{
    return dir;
}

point ray::at(double t) const
{
    return orig + t*dir;
}