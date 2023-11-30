#include "Collision.h"

bool Collision::is_colliding(const Shape *s1, const Shape *s2) {
  // get the first direction vector
  const Vector2D s1Center = s1->get_center();
  const Vector2D s2Center = s2->get_center();
  Vector2D direction(Vector2D::get_normalized_vector(s2Center - s1Center));

  // create the simplex vector and then add the first point to it
  std::vector<Vector2D> simplex;
  simplex.push_back(Collision::get_support_point(s1, s2, direction));

  // setting the new direction toward the origin
  direction = Vector2D::get_normalized_vector(-simplex[0]); // == ORIGIN - A == (0, 0) - A

  while (true) {
    // get an other point on the Minkowski difference
    Vector2D A = Collision::get_support_point(s1, s2, direction);

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

Vector2D Collision::get_support_point(const Shape *s1, const Shape *s2, Vector2D &direction) {
  return s1->get_futhest_point(direction) - s2->get_futhest_point(-direction);
}

bool Collision::handle_simplex(std::vector<Vector2D> &simplex, Vector2D &direction)
{
    if (simplex.size() == 2) { return handle_line_simplex(simplex, direction); }
    return handle_triangle_simplex(simplex, direction);
}

bool Collision::handle_line_simplex(std::vector<Vector2D> &simplex, Vector2D &direction)
{
    Vector2D B = simplex[0];
    Vector2D A = simplex[1];

    Vector2D AB = B - A;
    Vector2D OA = -A; // == (0, 0) - A

    // get the vector perpendicular to AB and pointing toward the origin
    Vector2D ABPerp = Vector2D::triple_cross_product(AB, OA, AB);

    direction = Vector2D::get_normalized_vector(ABPerp); // redifine the direction toward the origin

    // since the simplex is a line the odd of it to containing the origin in a 2D space
    // is almost null, so return null without bothering to check is more efficient
    // if the simplex was indeed containing the origin the next step of the gjk will tell it
    return false;
}

bool Collision::handle_triangle_simplex(std::vector<Vector2D> &simplex, Vector2D &direction)
{
    Vector2D A = simplex[2];
    Vector2D B = simplex[1];
    Vector2D C = simplex[0];

    Vector2D AB = B - A;
    Vector2D AC = C - A;
    Vector2D AO = -A; // == (0, 0) - A

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
