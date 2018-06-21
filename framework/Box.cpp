#include <glm/vec3.hpp>
#include <cmath>
#include <string>
#include <iostream>

#include "Box.hpp"
#include "color.hpp"

//Child Constructors
//Standard Constructor
Box::Box() :
    Shape{string("Box"), Color{0.0f, 0.0f, 0.0f}},
    min_{{0.0f, 0.0f, 0.0f}},
    max_{{1.0f, 1.0f, 1.0f}}
{
    cout << "Standard constructor" << '\n';
};

//Costum Constructor 1
Box::Box(glm::vec3 const &min, glm::vec3 const &max) :
    Shape{},
    min_{min},
    max_{max}
{
    cout << "Costum constructor w/ min, max" << '\n';
};

//Costum Constructor 2
Box::Box(glm::vec3 const &min, glm::vec3 const &max, string const &name, Color const &color) :
    Shape{name, color},
    min_{min},
    max_{max}
{
    cout << "Costum constructor w/ name, color" << '\n';
};

//Destructor
Box::~Box() {
    cout << "Destructor" << '\n';
};

glm::vec3 const& get_min() const {
    return min_;
}

glm::vec3 const& get_max() const {
    return max_;
}

//overriding methods of base class (area&volume)
double Box::area() const{

    double length{abs(max_.x - min_.x)};
    double height{abs(max_.y - min_.y)};
    double width {abs(max_.z - min_.z)};

    return 2*(length*width) + 2*(length*height) + 2*(height*width);
}

double Box::volume() const {

    double length{abs(max_.x - min_.x)};
    double width {abs(max_.y - min_.y)};
    double height{abs(max_.z - min_.z)};

    return length*width*height;
}

ostream& Box::print(ostream& ost) const {

    Shape::print(ost);
    ost << "Minimum: " << min_.x << ", " << min_.y << ", " << mix_.z << '\n';
    ost << "Maximum: " << max_.x << ", " << max_.y << ", " << max_.z << '\n';
    ost << "Area: "    << area() << '\n';
    ost << "Volume: "  << volume() << '\n';

    return ost;
}