#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef VECTOR2D_H_
#define VECTOR2D_H_

class Vector2D {
public:
  float x;
  float y;

  Vector2D(float inputX, float inputY) : x(inputX), y(inputY) {};

  Vector2D& normalize();
  float length() const;
  float dot(const Vector2D &other) const;
  sf::Vector2f to_sfml(); 

  // static methods operations
  static float length(const Vector2D &v);
  static float dot(const Vector2D &v1, const Vector2D &v2);
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
  friend Vector2D operator-(const Vector2D &v);
  friend Vector2D operator-(const Vector2D &v1, const Vector2D &v2);
  friend Vector2D operator+(const Vector2D &v1, const Vector2D &v2);
  friend Vector2D operator*(const Vector2D &v, float f);
  friend Vector2D operator*(float f, const Vector2D &v);
  friend bool operator==(const Vector2D &v1, const Vector2D &v2);
  friend std::ostream &operator<<(std::ostream &os, const Vector2D &v);
  // TODO overload stream operator for vector<Vectro2D>
};

#endif /* !VECTOR2D_H_ */
