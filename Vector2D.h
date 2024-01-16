#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef VECTOR2D_H_
#define VECTOR2D_H_

class Vector2D {
public:
  float x;
  float y;

  Vector2D();
  Vector2D(float inputX, float inputY) : x(inputX), y(inputY) {};

  Vector2D& normalize();
  bool is_zero();
  float length() const;
  float dot(const Vector2D &other) const;
  float cross_product(const Vector2D &other) const;

  // static methods operations
  static float length(const Vector2D &v);
  static float dot(const Vector2D &v1, const Vector2D &v2);
  static float cross_product(const Vector2D &v1, const Vector2D &v2);
  static Vector2D get_normalized_vector(const Vector2D &v);
  static Vector2D triple_cross_product(const Vector2D &v1, const Vector2D &v2, const Vector2D &v3);
  static Vector2D normal_clockwise(const Vector2D &v);
  static Vector2D normal_counter_clockwise(const Vector2D &v);

  // shorthands
  static Vector2D zero();
  static Vector2D left(); 
  static Vector2D right();
  static Vector2D up();
  static Vector2D down();

  // operator overload
  Vector2D &operator+=(const Vector2D &v);
  Vector2D &operator-=(const Vector2D &v);
  Vector2D &operator*=(const float &f);
  Vector2D &operator/=(const float &f);
  friend Vector2D operator-(const Vector2D &v);
  friend Vector2D operator-(const Vector2D &v1, const Vector2D &v2);
  friend Vector2D operator+(const Vector2D &v1, const Vector2D &v2);
  friend Vector2D operator*(const Vector2D &v, float f);
  friend Vector2D operator*(float f, const Vector2D &v);
  friend Vector2D operator/(const Vector2D &v, float f);
  friend bool operator==(const Vector2D &v1, const Vector2D &v2);
  friend bool operator!=(const Vector2D &v1, const Vector2D &v2);
  friend std::ostream &operator<<(std::ostream &os, const Vector2D &v);
  friend std::ostream &operator<<(std::ostream& os, const std::vector<Vector2D> &vector);
  operator sf::Vector2f() const;
};

#endif /* !VECTOR2D_H_ */
