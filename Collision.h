#include "Shape.h"
#include "Vector2D.h"
#include <iostream>

#ifndef COLLISION_H_
#define COLLISION_H_

/* 
 * The implementation rely on GJK and EPA algorithms, for more informations :
 *
 * GJK :
 * https://www.youtube.com/watch?v=ajv46BSqcK4&t
 * https://dyn4j.org/2010/04/gjk-gilbert-johnson-keerthi
 * 
 * EPA :
 * https://dyn4j.org/2010/05/epa-expanding-polytope-algorithm/
 * https://blog.winter.dev/2020/epa-algorithm/
 */
class Collision {
public:
  // return true if the 2 shapes are in contact
  static bool are_colliding(const Shape *s1, const Shape *s2);

  // return the minimum distance between the 2 shapes
  // if the 2 shapes are ovrelapping : return the maximum depth penetration distance (negative value)
  // if the 2 shapes are not ovrelapping : return the minimal distance between this 2 shapes (positive value)
  static float get_minimum_dist(const Shape *s1, const Shape *s2);

  // return the minimum distance between the 2 shapes
  // if the 2 shapes are ovrelapping : return the maximum depth penetration distance (negative value)
  // if the 2 shapes are not ovrelapping : return the minimal distance between this 2 shapes (positive value)
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

  // generate a 2 point polytope to bootstrap EPA when GJK exit too early
  static std::vector<Vector2D> generate_minimal_polytope(const Shape *s1, const Shape *s2);

  // return the point the point on the edge of the Minkowski difference in the
  // given direction
  static Vector2D get_support_point(const Shape *s1, const Shape *s2, Vector2D &direction);

  // return true if the origin is inside the simplex
  // else modify the simplex by adding/modifying points and redifine the
  // direction vector to prepare to the next step of the gjk algorithm
  static bool handle_simplex(std::vector<Vector2D> &simplex, Vector2D &direction);

  // take a 2 points simplex
  // if the origin lies on the 2 points simplex return true,
  // else update the direction toward the origin and return false
  static bool handle_line_simplex(const std::vector<Vector2D> &simplex, Vector2D &direction);

  // take a 3 points simplex, check if the the origin belongs in the simplex, if
  // yes return true, if not check the origin could belong in the Minkowski
  // difference, if yes update the simplex by removing a point else return false
  static bool handle_triangle_simplex(std::vector<Vector2D> &simplex, Vector2D &direction);

  // return true if the segment formed by the two points contains the origin
  static bool line_contains_origin(const Vector2D &p1, const Vector2D &p2);

  // return the index of the point A of the edge AB wich is the closest to the origin
  // fill minDistance with distance between A and the origin
  // fill the vector minNormal with the normal of AB pointing toward the origin
  static unsigned long get_closest_edge_infos(const std::vector<Vector2D> &polytope, float &minDistance, Vector2D &minNormal);
};

#endif /* !COLLISION_H_ */
