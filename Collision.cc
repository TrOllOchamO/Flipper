#include "Collision.h"
#include <cmath>
#include <iostream>
#include <assert.h>
#include <limits>
#include <ostream>

#define INFINIT_DISTANCE std::numeric_limits<float>::max()
#define EPA_PRECISION_WANTED 0.001
#define EPA_MAX_ITERATION 300

bool Collision::are_colliding(const Shape *s1, const Shape *s2) {
  std::vector<Vector2D> simplex;
  simplex.reserve(3);
  return Collision::GJK(s1, s2, simplex);
}

float Collision::get_minimum_dist(const Shape *s1, const Shape *s2) {
    std::vector<Vector2D> polytope;
    Collision::GJK(s1, s2, polytope);
    Vector2D direction = Vector2D::zero();
    return Collision::EPA(s1, s2, direction, polytope);
}

float Collision::get_minimum_dist_and_direction(const Shape *s1, const Shape *s2, Vector2D &direction) {
    std::vector<Vector2D> polytope;
    Collision::GJK(s1, s2, polytope);
    return Collision::EPA(s1, s2, direction, polytope);
}

bool Collision::GJK(const Shape *s1, const Shape *s2, std::vector<Vector2D> &simplex) {
  // get the first direction vector
  const Vector2D s1Center = s1->get_center();
  const Vector2D s2Center = s2->get_center();

  Vector2D direction = s2Center - s1Center;

  // if the difference is the origin then it mean both shapes overlap
  if (direction.is_zero()) {
    return true;
  }
  direction = Vector2D::get_normalized_vector(direction);

  // make sure the simplex is empty and then add the first point to it
  assert(simplex.size() == 0);
  simplex.push_back(Collision::get_support_point(s1, s2, direction));

  // one edge of the  Minkowski difference lies on the origin
  if (simplex[0].is_zero()) {
    return true;
  }

  // setting the new direction toward the origin
  direction = Vector2D::get_normalized_vector(-simplex[0]); // == ORIGIN - A == (0, 0) - A

  while (true) {
    // get an other point on the Minkowski difference
    const Vector2D A = Collision::get_support_point(s1, s2, direction);

    // if the new point didn't pass the origin then the origin can't be inside
    // the Minkowski difference and by extention the 2 shapes aren't colliding,
    // so return false
    if (Vector2D::dot(A, direction) < 0) {
      return false;
    }

    // append the new point to the simplex
    simplex.push_back(A);

    // return true if the origin is inside the simplex
    // else modify the direction vector and the simplex in order to reiterate
    // the steps
    if (handle_simplex(simplex, direction)) {
      return true;
    }
  }
}

float Collision::EPA(const Shape *s1, const Shape *s2, Vector2D &direction, std::vector<Vector2D> polytope) {
  if (polytope.size() < 2) {
    polytope = generate_minimal_polytope(s1, s2);
  }

  float closest_edge_distance;
  Vector2D closest_edge_normal;

  // while the precision is too low copared to the goal minDistance will be set to INFINIT_DISTANCE
  for (size_t i = 0; i < EPA_MAX_ITERATION; ++i) {
    int closest_edge_index = Collision::get_closest_edge_infos(polytope, closest_edge_distance, closest_edge_normal);

    // once we got the normal of the closest edge to the origin so we can use it to determine a new point
    // on the edge of the Minkowski difference
    Vector2D support = Collision::get_support_point(s1, s2, closest_edge_normal);

    // calculate the distance 
    float support_distance = Vector2D::dot(closest_edge_normal, support);
    
    // the difference between the 2 distance is less then the precision then we 
    // there is no need to expand the polytope any futher, so we return 
    if(support_distance - closest_edge_distance < EPA_PRECISION_WANTED) {
        direction = closest_edge_normal;
        return -closest_edge_distance; // negate the distance to correct the winding probleme
    }

    // if we still are able to expand the polytope, insert the new point in the polytope
    // the point must be inserted bewteen i and j in order to keep the polytope convex
    polytope.insert(polytope.begin() + closest_edge_index, support);
  }

  direction = closest_edge_normal;
  return -closest_edge_distance;
}

std::vector<Vector2D> Collision::generate_minimal_polytope(const Shape *s1, const Shape *s2) {
  std::vector<Vector2D> polytope;
  Vector2D direction = Vector2D::up();
  polytope.push_back(Collision::get_support_point(s1, s2, direction));

  direction = Vector2D::down();
  Vector2D new_vertex = Collision::get_support_point(s1, s2, direction);
  if (new_vertex != polytope[0]) {
    polytope.push_back(new_vertex);
    return polytope;
  }

  direction = Vector2D::right();
  new_vertex = Collision::get_support_point(s1, s2, direction);
  if (new_vertex != polytope[0]) {
    polytope.push_back(new_vertex);
    return polytope;
  }

  direction = Vector2D::left();
  polytope.push_back(Collision::get_support_point(s1, s2, direction));
  return polytope;
}

Vector2D Collision::get_support_point(const Shape *s1, const Shape *s2, Vector2D &direction) {
  return s1->get_futhest_point(direction) - s2->get_futhest_point(-direction);
}

bool Collision::handle_simplex(std::vector<Vector2D> &simplex, Vector2D &direction) {
    if (simplex.size() == 2) { return handle_line_simplex(simplex, direction); }
    return handle_triangle_simplex(simplex, direction);
}

bool Collision::line_contains_origin(const Vector2D &p1, const Vector2D &p2) {
  const bool line_is_vertical = p1.x == 0 && p2.x == 0;
  if (line_is_vertical) {
    const float min_y = std::fmin(p1.y, p2.y);
    const float max_y = std::fmax(p1.y, p2.y);

    const bool origin_is_above = max_y < 0.0;
    const bool origin_is_below = min_y > 0.0;
    
    return !(origin_is_above || origin_is_below);
  }

  return p1.x != p2.x && p1.y/p1.x == p2.y/p2.y;
}

bool Collision::handle_line_simplex(const std::vector<Vector2D> &simplex, Vector2D &direction) {
  const Vector2D B = simplex[0];
  const Vector2D A = simplex[1];
  
  if (Collision::line_contains_origin(A, B)) {
    return true;
  }

  const Vector2D AB = B - A;
  const Vector2D OA = -A; // == (0, 0) - A

  // get the vector perpendicular to AB and pointing toward the origin
  Vector2D ABPerp = Vector2D::triple_cross_product(AB, OA, AB);

  if (ABPerp.is_zero()) {
    // assert(false); // i think we should not hit this assert, but if we do,
    // i think think the fix should be to remove the assert and replace it with :
    direction = OA;
    return false;
    // not sure thought
  }

  direction = Vector2D::get_normalized_vector(ABPerp); // redifine the direction toward the origin

  return false;
}

bool Collision::handle_triangle_simplex(std::vector<Vector2D> &simplex, Vector2D &direction) {
  const Vector2D A = simplex[2];
  const Vector2D B = simplex[1];
  const Vector2D C = simplex[0];

  // TODO may be usefull we'll see with the tests
  // if (Collision::line_contains_origin(A, B) ||
  //     Collision::line_contains_origin(B, C) || 
  //     Collision::line_contains_origin(C, A)
  // ) {
  //   return true;
  // }

  const Vector2D AB = B - A;
  const Vector2D AC = C - A;
  const Vector2D AO = -A; // == (0, 0) - A

  Vector2D ABPerp = Vector2D::triple_cross_product(AC, AB, AB);
  if (Vector2D::dot(ABPerp, AO) > 0) { // if the origin is in the region AB
      simplex.erase(simplex.begin()); // remove the point C of the simplex
      direction = Vector2D::get_normalized_vector(ABPerp); // setting the new direction toward the region AB
      return false; // since the point is contain in the region AB then it's not contain in the simplex
  }

  Vector2D ACPerp = Vector2D::triple_cross_product(AB, AC, AC);
  if (Vector2D::dot(ACPerp, AO) > 0) {// if the origin is in the region AC
      simplex.erase(std::next(simplex.begin())); // remove the point B of the simplex
      direction = Vector2D::get_normalized_vector(ACPerp); // setting the new direction toward the region AC
      return false; // since the point is contain in the region AC then it's not contain in the simplex
  }

  // if the origin isn't in both of the 2 area then it belong in the simplex due to the way
  // we first obtained this simplex, so we return true
  return true;
}

unsigned long Collision::get_closest_edge_infos(const std::vector<Vector2D> &polytope, float &minDistance, Vector2D &minNormal) {
  // making sure the polytope is valid
  assert(polytope.size() >= 2);

  unsigned long closestEdgeIndex = 0;
  minDistance = INFINIT_DISTANCE;

  for (unsigned long i = 0; i < polytope.size(); ++i) {
    // determine the index j wich is the second point of the tested edge (i being the first one)
    unsigned long j = (i+1) % polytope.size();

    Vector2D vertexI = polytope[i];
    Vector2D vertexJ = polytope[j];

    Vector2D IJ = vertexJ - vertexI;

    if (IJ.is_zero()) {
      continue;
    }

    // get the normal vector by swapping coordinates and negating one
    // avoid to use the triple product wich can cause troubles when dealing with really tiny vectors
    Vector2D currentNormal = Vector2D::normal_counter_clockwise(IJ).normalize();

    float currentDistance = Vector2D::dot(currentNormal, vertexI);

    // if the new distance is smaller than the actual smallest replace the smallest
    if (currentDistance < minDistance) {
        minDistance = currentDistance;
        minNormal = currentNormal;
        closestEdgeIndex = j;
    }
  }

  return closestEdgeIndex;
}
