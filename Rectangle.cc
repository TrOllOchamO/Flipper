#include "Rectangle.h"

Vector2D Rectangle::get_center() const {
  return Vector2D(this->get_pos().x + width / 2, this->get_pos().y + height / 2);
}

Vector2D Rectangle::get_futhest_point(const Vector2D &direction) const{
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

std::vector<Vector2D> Rectangle::get_vertices() const {
  const Vector2D pos = this->get_pos();
  return {
          pos,
          Vector2D(pos.x + width, pos.y), 
          Vector2D(pos.x, pos.y + height),
          Vector2D(pos.x + width, pos.y + height)};
}

void Rectangle::render(sf::RenderWindow &window, sf::Color color) const {
  sf::Vector2f size(width, height);
  sf::RectangleShape shape(size);
  shape.setFillColor(color);
  shape.setPosition(get_pos());
  window.draw(shape);
}
