#include <iostream>
#include "color.h"
#include "vec.h"
#include "omp.h"
#include "ray.h"
#include <chrono>



inline double random_double() {
    // Returns a random real in [0,1).
    return rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max) {
    // Returns a random real in [min,max).
    return min + (max-min)*random_double();
}

double hit_sphere(const point & center , double radius, const ray & r)
{

    auto a = dot(r.direction(), r.direction());
    vec AC = r.origin() - center;
    auto b = dot(2.0 * r.direction(), AC);
    auto c = dot(AC,AC) - radius*radius;
    auto discriminant = b*b - 4*a*c;
    if (discriminant < 0){
        return -1;
    }
    else{
        return (-b - sqrt(discriminant)) / (2*a);
    }
}
color ray_color(const ray& r) {
    auto t = hit_sphere(point(0,0,-1) , 0.6, r);

    if (t > 0){
        vec normal = unit_vector(r.at(t) - vec(0,0,-1));
        return 0.5*color(normal.x()+1, normal.y()+1, normal.z()+1);
    }
    vec unit_direction = unit_vector(r.direction());
    t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}

int main() {

    // Image
    const auto aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;
    const int image_height = (int)(image_width / aspect_ratio);
    double samples = 100;

    // Camera
    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0;

    auto origin = point(0, 0, 0);
    auto horizontal = vec(viewport_width, 0, 0);
    auto vertical = vec(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal/2 - vertical/2 - vec(0, 0, focal_length);


    // Render
    auto start = std::chrono::steady_clock::now();

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    #pragma omp parallel for collapse(2) ordered
    for (int j = image_height-1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i) {

            color pixel_col(0,0,0);
            //anti aliasing
            for (int c=0;c<(int)samples;c++){

                auto u = double(i + random_double()) / (image_width-1);
                auto v = double(j + random_double()) / (image_height-1);
                ray r(origin, lower_left_corner + u*horizontal + v*vertical);
                pixel_col += ray_color(r);
            }
            #pragma omp ordered
            write_color(std::cout , pixel_col, samples);
        }
    }
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    std::cerr << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;
}
