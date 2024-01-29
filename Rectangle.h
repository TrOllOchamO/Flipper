#include <iostream>
#include "Vector2D.h"
#include "Shape.h"

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

class Rectangle: public Shape {
private:
  float width;
  float height;

public:
  Rectangle(Vector2D pos, float width, float height): Shape(pos), width(width), height(height) {};

  Vector2D get_center() const override;
  Vector2D get_futhest_point(const Vector2D &direction) const override;
  std::vector<Vector2D> get_vertices() const;

  void render(sf::RenderWindow &window, sf::Color color) const override;
  void render(sf::RenderWindow &window, const sf::Texture &texture) const override;
};

#endif /* !RECTANGLE_H_ */
