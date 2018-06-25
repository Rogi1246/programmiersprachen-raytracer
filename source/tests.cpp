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


  Shape();
  Sphere s0{center, radius, "Sphere0", color};
  Box b0{center, max};

}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
