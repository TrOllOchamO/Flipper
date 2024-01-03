#include "Collision.h"
#include <iostream>
#include <assert.h>
#include <limits>

/* 
 * The implementation below rely on GJK and EPA algorithms, for more informations :
 *
 * GJK :
 * https://www.youtube.com/watch?v=ajv46BSqcK4&t
 * https://dyn4j.org/2010/04/gjk-gilbert-johnson-keerthi
 * 
 * EPA :
 * https://dyn4j.org/2010/05/epa-expanding-polytope-algorithm/
 * https://blog.winter.dev/2020/epa-algorithm/
 */

#define INFINIT_DISTANCE std::numeric_limits<float>::max()
#define EPA_PRECISION_WANTED 0.001

bool Collision::are_colliding(const Shape *s1, const Shape *s2) {
  std::vector<Vector2D> simplex;
  simplex.reserve(3);
  return Collision::GJK(s1, s2, simplex);
}

float Collision::get_minimum_dist(const Shape *s1, const Shape *s2)
{
    std::vector<Vector2D> polytope;
    Collision::GJK(s1, s2, polytope);
    Vector2D direction = Vector2D::zero();
    return Collision::EPA(s1, s2, direction, polytope);
}

float Collision::get_minimum_dist_and_direction(const Shape *s1, const Shape *s2, Vector2D &direction)
{
    std::vector<Vector2D> polytope;
    Collision::GJK(s1, s2, polytope);
    return Collision::EPA(s1, s2, direction, polytope);
}

bool Collision::GJK(const Shape *s1, const Shape *s2, std::vector<Vector2D> &simplex) {
  // get the first direction vector
  const Vector2D s1Center = s1->get_center();
  const Vector2D s2Center = s2->get_center();
  Vector2D direction(Vector2D::get_normalized_vector(s2Center - s1Center));

  // make sure the simplex is empty and then add the first point to it
  assert(simplex.size() == 0);
  simplex.push_back(Collision::get_support_point(s1, s2, direction));

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

float Collision::EPA(const Shape *s1, const Shape *s2, Vector2D &direction, std::vector<Vector2D> polytope)
{
    float closestEdgeDistance;
    Vector2D closestEdgeNormal = Vector2D::zero();

    // while the precision is too low copared to the goal minDistance will be set to INFINIT_DISTANCE
    while (true)
    {
        int closestEdgeIndex = Collision::get_closest_edge_infos(polytope, closestEdgeDistance, closestEdgeNormal);

        // once we got the normal of the closest edge to the origin so we can use it to determine a new point
        // on the edge of the Minkowski difference
        Vector2D support = Collision::get_support_point(s1, s2, closestEdgeNormal);

        // calculate the distance 
        float supportDistance = Vector2D::dot(closestEdgeNormal, support);
        
        // the difference between the 2 distance is less then the precision then we 
        // there is no need to expand the polytope any futher, so we return 
        if(supportDistance - closestEdgeDistance < EPA_PRECISION_WANTED)
        {
            direction = closestEdgeNormal;
            return -closestEdgeDistance; // negate the distance to correct the winding probleme
        }

        // if we still are able to expand the polytope, insert the new point in the polytope
        // the point must be inserted bewteen i and j in order to keep the polytope convex
        polytope.insert(polytope.begin() + closestEdgeIndex, support);
    }
}

Vector2D Collision::get_support_point(const Shape *s1, const Shape *s2, Vector2D &direction) {
  return s1->get_futhest_point(direction) - s2->get_futhest_point(-direction);
}

bool Collision::handle_simplex(std::vector<Vector2D> &simplex, Vector2D &direction) {
    if (simplex.size() == 2) { return handle_line_simplex(simplex, direction); }
    return handle_triangle_simplex(simplex, direction);
}

bool Collision::handle_line_simplex(std::vector<Vector2D> &simplex, Vector2D &direction) {
    const Vector2D B = simplex[0];
    const Vector2D A = simplex[1];

    const Vector2D AB = B - A;
    const Vector2D OA = -A; // == (0, 0) - A

    // get the vector perpendicular to AB and pointing toward the origin
    Vector2D ABPerp = Vector2D::triple_cross_product(AB, OA, AB);

    direction = Vector2D::get_normalized_vector(ABPerp); // redifine the direction toward the origin

    // since the simplex is a line the odd of it to containing the origin in a 2D space
    // is almost null, so return null without bothering to check is more efficient
    // if the simplex was indeed containing the origin the next step of the gjk will tell it
    return false;
}

bool Collision::handle_triangle_simplex(std::vector<Vector2D> &simplex, Vector2D &direction) {
    const Vector2D A = simplex[2];
    const Vector2D B = simplex[1];
    const Vector2D C = simplex[0];

    const Vector2D AB = B - A;
    const Vector2D AC = C - A;
    const Vector2D AO = -A; // == (0, 0) - A

    Vector2D ABPerp = Vector2D::triple_cross_product(AC, AB, AB);
    if (Vector2D::dot(ABPerp, AO) > 0) // if the origin is in the region AB
    {
        simplex.erase(simplex.begin()); // remove the point C of the simplex
        direction = Vector2D::get_normalized_vector(ABPerp); // setting the new direction toward the region AB
        return false; // since the point is contain in the region AB then it's not contain in the simplex
    }

    Vector2D ACPerp = Vector2D::triple_cross_product(AB, AC, AC);
    if (Vector2D::dot(ACPerp, AO) > 0) // if the origin is in the region AC
    {
        simplex.erase(std::next(simplex.begin())); // remove the point B of the simplex
        direction = Vector2D::get_normalized_vector(ACPerp); // setting the new direction toward the region AC
        return false; // since the point is contain in the region AC then it's not contain in the simplex
    }

    // if the origin isn't in both of the 2 area then it belong in the simplex due to the way
    // we first obtained this simplex, so we return true
    return true;
}

unsigned long Collision::get_closest_edge_infos(const std::vector<Vector2D> &polytope, float &minDistance, Vector2D &minNormal)
{
    // making sure the politype is valid
    assert(polytope.size() > 2);

    unsigned long closestEdgeIndex;
    minDistance = INFINIT_DISTANCE;

    for (unsigned long i = 0; i < polytope.size(); ++i)
    {
        // determine the index j wich is the second point of the tested edge (i being the first one)
        unsigned long j = (i+1) % polytope.size();

        Vector2D vertexI = polytope[i];
        Vector2D vertexJ = polytope[j];

        Vector2D IJ = vertexJ - vertexI;

        // get the normal vector by swapping coordinates and negating one
        // avoid to use the triple product wich can cause troubles when dealing with really tiny vectors
        Vector2D currentNormal = Vector2D::normal_clockwise(IJ).normalize();

        float currentDistance = Vector2D::dot(currentNormal, vertexI);

        // if the new distance is smaller than the actual smallest replace the smallest
        if (currentDistance < minDistance)
        {
            minDistance = currentDistance;
            minNormal = currentNormal;
            closestEdgeIndex = j;
        }
    }

    return closestEdgeIndex;
}
