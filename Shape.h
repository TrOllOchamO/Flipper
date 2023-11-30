#include <iostream>
#include "Vector2D.h"

#ifndef SHAPE_H_
#define SHAPE_H_

class Shape{
private:
  Vector2D pos;

public:
  Shape(Vector2D pos) : pos(pos) {};

  Vector2D get_pos();
  void set_pos(Vector2D new_pos);

  virtual Vector2D get_center() const = 0;
  virtual Vector2D get_futhest_point(const Vector2D &direction) const = 0;
};

#endif /* !SHAPE_H_ */
