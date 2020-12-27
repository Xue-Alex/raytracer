//
// Created by alexx on 2020-12-25.
//

#ifndef MAIN_CC_VEC_H
#define MAIN_CC_VEC_H

#include <cmath>
#include <iostream>


class vec{


    private:
        double coord[3];

    public:
        vec();
        vec(double first, double second, double third);
        double x() const;
        double y() const;
        double z() const;
        double operator[](int i); //return index i
       // double & operator[](int i); //return index i
        vec& operator-();
        vec& operator+=(const vec &v);
        vec& operator-=(vec &v);
        vec& operator/=(vec &v);
        vec& operator*=(vec &v);

        double length();




};

std::ostream& operator<<(std::ostream &out, const vec &v);

vec operator+(const vec &a, const vec&b);

vec operator/(const vec &a, const vec&b);
vec operator-(const vec &a, const vec&b);
vec operator*(const vec &a, const vec&b);
vec operator*(const vec &a, double s);
vec operator*(double s, const vec &a);
vec operator/(const vec &a, double s);

double dot (const vec &a, const vec &b);

vec cross(const vec &a , const vec &b);

vec unit_vector(vec a);


using point = vec;
using color = vec;
#endif //MAIN_CC_VEC_H
