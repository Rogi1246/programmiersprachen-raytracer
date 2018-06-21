#ifndef BOX_HPP
#define BOX_HPP

#include <glm/vec3.hpp>
#include <string>
#include <iostream>

#include "Shape.hpp"
#include "color.hpp"

using namespace std;

class Box : public Shape {

    public :
        Box();
        Box(glm::vec3 const& min, glm::vec3 const& max);
        Box(glm::vec3 const& min, glm::vec3 const& max, string const& name, Color const& color);

        ~Box();

        glm::vec3 get_min() const;
        glm::vec3 get_max() const;

        double area() const override;
        double volume() const override;

        ostream& print(ostream& ost) const override;

    private :
        glm::vec3 min_;
        glm::vec3 max_;

};

#endif