#include "Rectangle.h"

Vector2D Rectangle::get_center() {
  return Vector2D(pos.x + width / 2, pos.y + height / 2);
}

Vector2D Rectangle::get_futhest_point(const Vector2D &direction) {
  const std::vector<Vector2D> vertices = get_vertices();
  Vector2D futhest_point = vertices[0];
  float best_score = direction.dot(futhest_point);

  // search for a point with a superior score
  for (int i = 1; i < 4; ++i) {
    const float new_score = direction.dot(vertices[i]);
    if (new_score > best_score) {
      best_score = new_score;
      futhest_point = vertices[i];
    }
  }

  return futhest_point;
}

std::vector<Vector2D> Rectangle::get_vertices() {
  return {
          pos,
          Vector2D(pos.x + width, pos.y), 
          Vector2D(pos.x, pos.y + height),
          Vector2D(pos.x + width, pos.y + height)};
}
