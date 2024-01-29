#include <iostream>
#include "Vector2D.h"
#include "Shape.h"

#ifndef CIRCLE_H_
#define CIRCLE_H_

class Circle: public Shape {
private:
  float radius;

public:
  Circle(Vector2D pos, float radius): Shape(pos), radius(radius) {};

  Vector2D get_center() const override;
  Vector2D get_futhest_point(const Vector2D &direction) const override;
  float get_radius() const;

  void render(sf::RenderWindow &window, sf::Color color) const override;
  void render(sf::RenderWindow &window, const sf::Texture &texture) const override;
};

#endif /* !CIRCLE_H_ */
