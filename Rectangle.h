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

  Vector2D get_center();
  Vector2D get_futhest_point(const Vector2D &direction);
  std::vector<Vector2D> get_vertices();
};

#endif /* !RECTANGLE_H_ */
