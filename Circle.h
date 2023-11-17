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

  Vector2D get_center();
  Vector2D get_futhest_point(const Vector2D &direction);
};

#endif /* !CIRCLE_H_ */
