#include "Circle.h"
#include <cmath>

Vector2D Circle::get_center() const {
  const Vector2D pos = this->get_pos();
  return Vector2D(pos.x + radius, pos.y + radius);
}

Vector2D Circle::get_futhest_point(const Vector2D &direction) const {
  const Vector2D center = this->get_center();
  const Vector2D direction_unit = Vector2D::get_normalized_vector(direction);
  const Vector2D futhest_point = center + (direction_unit * radius);
  return futhest_point;
}

void Circle::render(sf::RenderWindow &window, sf::Color color) const {
  sf::CircleShape shape(radius);
  shape.setFillColor(color);
  shape.setPosition(get_pos());
  window.draw(shape);
}

void Circle::render(sf::RenderWindow &window, const sf::Texture &texture) const {
  sf::CircleShape shape(radius);
  shape.setTexture(&texture);
  // shape.setTextureRect(sf::IntRect(0, 0, radius*2, radius*2));
  shape.setPosition(get_pos());
  window.draw(shape);
}

float Circle::get_radius() const {
  return this->radius;
}
