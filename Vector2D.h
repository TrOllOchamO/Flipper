#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef VECTOR2D_H_
#define VECTOR2D_H_

class Vector2D {
public:
  float x;
  float y;

  Vector2D(float inputX, float inputY);

  Vector2D &operator+=(const Vector2D &v);
  Vector2D &operator-=(const Vector2D &v);
  Vector2D &operator*=(const float &f);
  Vector2D &normalize();

  float length();
  float dot(const Vector2D &vect1, const Vector2D &vect2);
  Vector2D triple_cross_product(const Vector2D &vect1, const Vector2D &vect2, const Vector2D &vect3);
  Vector2D normal_clockwise(const Vector2D &vect);
  Vector2D normal_counter_clockwise(const Vector2D &vect);

  friend Vector2D operator-(const Vector2D &v);
  friend Vector2D operator-(const Vector2D &v1, const Vector2D &v2);
  friend Vector2D operator+(const Vector2D &v1, const Vector2D &v2);
  friend Vector2D operator*(const Vector2D &v, float f);
  friend Vector2D operator*(float f, const Vector2D &v);
  friend bool operator==(const Vector2D &v1, const Vector2D &v2);

  friend std::ostream &operator<<(std::ostream &os, const Vector2D &v);

  static Vector2D zero();
  static Vector2D left(); 
  static Vector2D right();
  static Vector2D up();
  static Vector2D down();

  sf::Vector2f to_sfml(); 
};

#endif /* !VECTOR2D_H_ */
