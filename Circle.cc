#include "Circle.h"
#include <cmath>

Vector2D Circle::get_center() const {
  const Vector2D pos = this->get_pos();
  return Vector2D(pos.x + radius, pos.y + radius);
}

Vector2D Circle::get_futhest_point(const Vector2D &direction) const {
  const Vector2D center = get_center();
  const Vector2D direction_unit = Vector2D(direction).normalize();
  const Vector2D futhest_point = center + direction_unit * radius;
  return futhest_point;
}

void Circle::render(sf::RenderWindow &window){
  sf::CircleShape shape(radius);
  shape.setFillColor(sf::Color::Green);
  shape.setPosition(get_pos().to_sfml());
  window.draw(shape);
}

float Circle::get_radius() const {
  return this->radius;
}
