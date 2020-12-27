#include "vec.h"


vec::vec()
{
    coord[0] = 0;
    coord[1] = 0;
    coord[2] = 0;
};

vec::vec(double first, double second, double third)
{
    coord[0] = first;
    coord[1] = second;
    coord[2] = third;
}

double vec::x() const {return coord[0];}

double vec::y() const {return coord[1];}

double vec::z() const {return coord[2];}

double vec::operator[](int i)
{
    return coord[i];
}


vec & vec::operator-()
{
    coord[0] *= -1;
    coord[1] *= -1;
    coord[2] *= -1;
    return *this;
}

vec & vec::operator+=(const vec & v)
{
    coord[0] += v.x();
    coord[1] += v.y();
    coord[2] += v.z();
    return *this;
}

vec & vec::operator-=(vec & v)
{
    coord[0] -= v.x();
    coord[1] -= v.y();
    coord[2] -= v.z();
    return *this;
}

vec & vec::operator*=(vec & v)
{
    coord[0] *= v.x();
    coord[1] *= v.y();
    coord[2] *= v.z();
    return *this;
}

vec & vec::operator/=(vec & v)
{
    coord[0] /= v.x();
    coord[1] /= v.y();
    coord[2] /= v.z();
    return *this;
}

double vec::length()
{
    return std::sqrt(coord[0]*coord[0] + coord[1]*coord[1] + coord[2]*coord[2]);
}

std::ostream& operator<<(std::ostream &out, const vec &v) {
    return out << v.x() << ' ' << v.y() << ' ' << v.z();
}

vec operator+(const vec &a, const vec&b)
{
    return vec(a.x() + b.x(), a.y() + b.y() , a.z() + b.z());
}

vec operator/(const vec &a,const  vec&b)
{
    return vec(a.x() / b.x(), a.y() / b.y() , a.z() / b.z());
}
vec operator-(const vec &a, const vec&b)
{
    return vec(a.x() -b.x(), a.y() - b.y() , a.z() - b.z());
}
vec operator*(const vec &a, const vec&b)
{
    return vec(a.x() *b.x(), a.y() *b.y() , a.z() * b.z());
}
vec operator*(const vec &a, double s)
{
    return vec(a.x()*s, a.y()*s, a.z()*s);
}
vec operator*(double s, const vec &a)
{
    return vec(a.x()*s, a.y()*s, a.z()*s);
}
vec operator/(const vec &a, double s)
{
    return vec(a.x()/s, a.y()/s, a.z()/s);
}

double dot (const vec &a, const vec &b)
{
    return a.x()*b.x() + a.y()*b.y() + a.z()*b.z();
}

vec cross(const vec &a , const vec &b)
{

    return vec(a.x() * b.y() - a.y() * b.x(),
               a.z() * b.x() - a.x() * b.z(),
               a.x() * b.y() - a.y() * b.x());

}

vec unit_vector(vec a)
{
    return a / a.length();
}