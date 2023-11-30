#include "Shape.h"

Vector2D Shape::get_pos() const {
  return pos;
}

void Shape::set_pos(Vector2D new_pos) {
  pos = new_pos;
}
