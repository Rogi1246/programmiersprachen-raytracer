#include "Shape.hpp"
#include "color.hpp"

#include <iostream>
#include <string>

using namespace std;

Shape::Shape():
    name_{"unnamed"},
    color_{Color{0.0f, 0.0f, 0.0f}}
{
    cout << "Standard constructor" << '\n';
};

Shape::Shape(string const& name, Color const& color) :
        name_{name},
        color_{color}
{
    cout << "Costum constructor" << '\n';
};

string Shape::get_name() const {
    return name_;
};

Color Shape::get_color() const {
    return color_;
};

ostream& Shape::print(ostream& ost)const {
    return ost << "Shapename : " << name_ << '\n' << "Shapecolor : " << color << '\n';
}

ostream& operator << (ostream& ost, Shape const& sh) {
    return sh.print(ost);
}