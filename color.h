#ifndef COLOR_H
#define COLOR_H

#include "vec.h"

#include <iostream>

inline double normalize(double x, double min, double max)
{
    if (x < min){
        return min;
    }
    else if (x > max){
        return max;
    }
    return x;
}

void write_color(std::ostream &out, color pixel_color, double samples) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // gamma correction
    r *= (1/samples);
    r = std::sqrt(r);
    g *= (1/samples);
    g = std::sqrt(g);
    b *= (1/samples);
    b = std::sqrt(b);

    out << (int)(255.999 * normalize(r,0,0.9999)) << ' '
        << (int)(255.999 * normalize(g,0,0.9999)) << ' '
        << (int)(255.999 * normalize(b,0,0.9999)) << '\n';
}

#endif