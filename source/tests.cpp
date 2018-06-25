#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <glm/vec3.hpp>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>

#include "../framework/Sphere.hpp"
#include "../framework/Box.hpp"
#include "../framework/color.hpp"

using namespace std;

TEST_CASE(" intersect_ray_sphere", "[intersect]")
{
  //Ray
  glm::vec3 ray_origin{0.0f, 0.0f, 0.0f};
  //ray direction has to be normalized
  //you can use :
  //v = glm::normalize(some_vector)
  glm::vec3 ray_direction{0.0f, 0.0f, 1.0f};

  //Sphere
  glm::vec3 sphere_center{0.0f, 0.0f, 5.0f};
  float sphere_radius{1.0f};

  float distance = 0.0f;
  auto result = glm::intersectRaySphere(
          ray_origin, ray_direction,
          sphere_center ,
          sphere_radius * sphere_radius , //squared radius
          distance
          );
  REQUIRE(distance == Approx(4.0f));

  //Costum Sphere
  glm::vec3 center1{1.0f, 0.0f, 2.0f};
  double radius1{6.0f};
  Color color1{1.0f, 1.0f, 1.0f};
  Sphere s1{center1, radius1, "Sphere1", color1};

  float distance1 = 1.0f;
  REQUIRE(distance1 == Approx(1.0f));

  glm::vec3 center2{0.0f, 0.0f, 0.0f};
  double radius2{1.0f};
  Color color2{0.0f, 1.0f, 0.0f};
  Sphere s2{center2, radius2, "Sphere2", color2};

  REQUIRE(s2.intersect(Ray{}, distance));

}

TEST_CASE(" destructor", "[destructor]")
{
  cout << " ======================================================= " << '\n';
  Color red{255,0,0};
  glm::vec3 position{0.0f, 0.0f, 0.0f};
  Sphere* s1 = new Sphere{position,1.2f, "Sphere0" , red};
  Shape* s2 = new Sphere{position, 1.2f, "Sphere1" , red};

  s1 -> print(cout);
  s2 -> print(cout);

  delete s1;
  delete s2;
}

TEST_CASE(" Constructors", "[Shape(s)]")
{
  glm::vec3 center{0.0, 0.0, 0.0};
  glm::vec3 max{2.0, -2.0, 2.0};
  double radius{5.5};
  Color color{1.0f, 1.0f, 0.0f};

  //try for a standard constructor
  //Shape zero{};
  Sphere s0{center, radius, "Sphere0", color};
  Box b0{center, max}; // center for minimum

  /*REQUIRE(zero.get_name().compare("unnamed") == 0.0);
  REQUIRE(zero.get_color().r == 0.0f);
  REQUIRE(zero.get_color().g == 0.0f);
  REQUIRE(zero.get_color().b == 0.0f);*/

  REQUIRE(s0.get_center().x == 0.0f);
  REQUIRE(s0.get_center().y == 0.0f);
  REQUIRE(s0.get_center().z == 0.0f);
  REQUIRE(s0.get_radius() == Approx(5.5f));
  REQUIRE(s0.get_name().compare("Sphere0") == 0.0);

  REQUIRE(b0.get_name().compare("unnamed") == 0.0);
  REQUIRE(b0.get_max().x == 2.0f);
  REQUIRE(b0.get_max().y == -2.0f);
  REQUIRE(b0.get_max().z == 2.0f);
}

TEST_CASE(" Sphere_methods", "[Sphere]")
{
    glm::vec3 center{0.0f, 0.0f, 0.0f};
    double radius{3.5f};
    Sphere s0{center, radius};

    REQUIRE(s0.volume() == Approx(179.594));
    REQUIRE(s0.area() == Approx(153.938));

}

TEST_CASE(" Box_methods", "[Box]")
{
    glm::vec3 min{0.0f, 0.0f, 0.0f};
    glm::vec3 max{1.0f, 2.0f, 1.0f};
    Box b0{min, max};

    REQUIRE(b0.volume() == Approx(2.0));
    REQUIRE(b0.area() == Approx(10.0));

}

TEST_CASE(" Operator_and_print", "[Shape(s)]")
{
    glm::vec3 center{1.5f, 1.0f, 1.0f};
    double radius = {4.6f};
    Sphere s0{center, radius};

    glm::vec3 max{-5.0f, -3.0f, -3.0f};
    Box b0{center, max}; //center variable for minimum again

    cout << b0 << '\n';
    cout << s0 << '\n';


}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
