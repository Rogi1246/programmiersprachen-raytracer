#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include <iostream>
#include "color.hpp"

using namespace std;

class Shape {
    public :
        Shape();
        Shape(string const& name, Color const& color);
        virtual ~Shape();

        virtual double area() const = 0;
        virtual double volume() const = 0;
        string name() const;
        Color color() const;

        virtual ostream& print(ostream ost) const;

    private:
        string name_;
        Color color_;

};

ostream& operator << (ostream& ost, Shape const& sh);

#endif