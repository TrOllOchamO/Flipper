#include "Shape.h"
#include "Vector2D.h"
#include <iostream>

#ifndef COLLISION_H_
#define COLLISION_H_

class Collision {
public:
  // return true if the 2 shapes are overlapping
  static bool is_colliding(const Shape *s1, const Shape *s2);

private:
  // return the point the point on the edge of the Minkowski difference in the
  // given direction
  static Vector2D get_support_point(const Shape *s1, const Shape *s2, Vector2D &direction);

  // return true if the origin is inside the simplex
  // else modify the simplex by adding/modifying points and redifine the
  // direction vector to prepare to the next step of the gjk algorithm
  static bool handle_simplex(std::vector<Vector2D> &simplex, Vector2D &direction);

  // take a 2 points simplex, update the direction toward the origin, return
  // false
  static bool handle_line_simplex(std::vector<Vector2D> &simplex, Vector2D &direction);

  // take a 3 points simplex, check if the the origin belongs in the simplex, if
  // yes return true, if not check the origin could belong in the Minkowski
  // difference, if yes update the simplex by removing a point else return false
  static bool handle_triangle_simplex(std::vector<Vector2D> &simplex, Vector2D &direction);
};

#endif /* !COLLISION_H_ */
