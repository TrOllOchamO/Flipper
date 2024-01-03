#include "Shape.h"
#include "Vector2D.h"
#include <iostream>

#ifndef COLLISION_H_
#define COLLISION_H_

class Collision {
public:
  // return true if the 2 shapes are overlapping
  static bool are_colliding(const Shape *s1, const Shape *s2);

  // return the minimum distance between the 2 shapes, if the 2 shapes are
  // ovrelapping return the maximum depth penetration distance
  static float get_minimum_dist(const Shape *s1, const Shape *s2);

  // return the minimum distance between the 2 shapes
  // if the 2 shapes are ovrelapping return the maximum depth penetration distance
  // fill the direction argument with the direction along the shortest distance between the 2 shapes
  static float get_minimum_dist_and_direction(const Shape *s1, const Shape *s2, Vector2D &direction);

private:
  // return true if the 2 shapes are overlapping, takes an empty vector and fill it
  // with all the points forming the final simplex
  static bool GJK(const Shape *s1, const Shape *s2, std::vector<Vector2D> &simplex);

  // return the minimum distance between the 2 shapes
  // if the 2 shapes are ovrelapping return the maximum depth penetration distance
  // fill the direction argument with the direction along the shortest distance between the 2 shapes
  // take the simplex produced by GJK as his starting point polytope
  static float EPA(const Shape *s1, const Shape *s2, Vector2D &direction, std::vector<Vector2D> polytope);

  // return the point the point on the edge of the Minkowski difference in the
  // given direction
  static Vector2D get_support_point(const Shape *s1, const Shape *s2, Vector2D &direction);

  // return true if the origin is inside the simplex
  // else modify the simplex by adding/modifying points and redifine the
  // direction vector to prepare to the next step of the gjk algorithm
  static bool handle_simplex(std::vector<Vector2D> &simplex, Vector2D &direction);

  // take a 2 points simplex, update the direction toward the origin, return false
  static bool handle_line_simplex(std::vector<Vector2D> &simplex, Vector2D &direction);

  // take a 3 points simplex, check if the the origin belongs in the simplex, if
  // yes return true, if not check the origin could belong in the Minkowski
  // difference, if yes update the simplex by removing a point else return false
  static bool handle_triangle_simplex(std::vector<Vector2D> &simplex, Vector2D &direction);

  // return the index of the point A of the edge AB wich is the closest to the origin
  // fill minDistance with distance between A and the origin, fill the vector minNormal 
  // with the normal of AB pointing toward the origin
  static unsigned long get_closest_edge_infos(const std::vector<Vector2D> &polytope, float &minDistance, Vector2D &minNormal);
};

#endif /* !COLLISION_H_ */
