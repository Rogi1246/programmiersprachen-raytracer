#include <cmath>
#include <glm/vec3.hpp>
#include <string>
#include <iostream>
#include <glm/gtx/intersect.hpp>

#include "Sphere.hpp"
#include "color.hpp"
#include "Ray.hpp"

using namespace std;

//Child Constructors
//Standard Constructor
Sphere::Sphere() :
    Shape{string ("Sphere"), Color{0.0f, 0.0f, 0.0f}},
    center_(glm::vec3{1.0f, 1.0f, 1.0f}),
    radius_(1.0f)
{
    cout << "Standard constructor" << '\n';
};

//Costum Constructor 1
Sphere::Sphere(glm::vec3 const& center, double const& radius) :
    Shape{},
    radius_{radius},
    center_{center}
{
    cout << "Costum constructor w/ size" << '\n';
};

//Costum Constructor 2
Sphere::Sphere(glm::vec3 const& center, double const& radius, string const& name, Color const& color) :
    Shape{name, color},
    radius_{radius},
    center_{center}
{
    cout << "Costum constructor w/ name, color" << '\n';
}



