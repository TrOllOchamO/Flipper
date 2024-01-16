#include <iostream>
#include "Vector2D.h"
#include "Renderable.h"

#ifndef SHAPE_H_
#define SHAPE_H_

class Shape : public Renderable {
private:
  Vector2D pos;
  int z_ordering = 0;
  bool convex = true;

public:
  Shape(Vector2D pos) : pos(pos) {};

  Vector2D get_pos() const;
  void set_pos(Vector2D new_pos);
  int get_z_ordering() const;
  void set_z_ordering(int new_z_ordering);

  bool is_shape_convex() const;
  void set_convex(bool value);

  virtual Vector2D get_center() const = 0;
  virtual Vector2D get_futhest_point(const Vector2D &direction) const = 0;
};

#endif /* !SHAPE_H_ */
