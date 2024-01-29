#include "Shape.h"

Vector2D Shape::get_pos() const {
  return pos;
}

void Shape::set_pos(Vector2D new_pos) {
  pos = new_pos;
}

int Shape::get_z_ordering() const {
  return z_ordering;
}

void Shape::set_z_ordering(int new_z_ordering) {
  z_ordering = new_z_ordering;
}

bool Shape::is_shape_convex() const{
  return convex;
}

void Shape::set_convex(bool value) {
  convex = value;
}
