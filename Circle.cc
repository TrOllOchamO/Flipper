#include "Circle.h"

Vector2D Circle::get_center() {
  return Vector2D(pos.x + radius, pos.y + radius);
}

Vector2D Circle::get_futhest_point(const Vector2D &direction) {
  const Vector2D center = get_center();
  const Vector2D direction_unit = Vector2D(direction).normalize();
  const Vector2D futhest_point = center + direction_unit * radius;
  return futhest_point;
}
