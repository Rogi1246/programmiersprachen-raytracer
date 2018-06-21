#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <glm/vec3.hpp>
#include <string>
#include <iostream>
#include "shape.hpp"
#include "color.hpp"
#include "Ray.hpp"

using namespace std;

class Sphere : public Shape {

    public:
        Sphere();
        Sphere(glm::vec3 const& center, double const& radius);
        Sphere(glm::vec3 const& center, double const& radius, string const& name, Color const& color);

        ~Sphere();

        glm::vec3 const& get_center() const ;
        double get_radius();
        double get_volume() const override ;
        double get_area() const override ;

        ostream& print(ostream& ost) const override ;

        bool intersect(Ray const& ray, float& distance) const;

    private:
        glm::vec3 center_;
        double radius_;

};

#endif