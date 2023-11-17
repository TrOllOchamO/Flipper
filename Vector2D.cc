#include "Vector2D.h"
#include <math.h>

Vector2D::Vector2D(float inputX, float inputY) : x(inputX), y(inputY) {}

Vector2D &Vector2D::operator+=(const Vector2D &v) {
  this->x += v.x;
  this->y += v.y;
  return *this;
}

Vector2D &Vector2D::operator-=(const Vector2D &v) {
  this->x -= v.x;
  this->y -= v.y;
  return *this;
}

Vector2D &Vector2D::operator*=(const float &f) {
  this->x *= f;
  this->y *= f;
  return *this;
}

Vector2D operator-(const Vector2D &v) {
  Vector2D result = {-v.x, -v.y};

  // avoid -0 shenanigans
  if (result.x == -0.0) {
    result.x = 0.0;
  }
  if (result.y == -0.0) {
    result.y = 0.0;
  }

  return result;
}

Vector2D operator-(const Vector2D &v1, const Vector2D &v2) {
    Vector2D result = v1;
    return result -= v2;
}

Vector2D operator+(const Vector2D &v1, const Vector2D &v2) {
    Vector2D result = v1;
    return result += v2;
}

Vector2D operator*(const Vector2D &v, float f) {
    Vector2D result = v;
    return result *= f;
}

Vector2D operator*(float f, const Vector2D &v) {
    Vector2D result = v;
    return result *= f;
}

std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

bool operator==(const Vector2D& v1, const Vector2D& v2) {
    return (v1.x == v2.x && v1.y == v2.y);
}

Vector2D& Vector2D::normalize() {
    const float vectorLength = std::sqrt(this->x*this->x + this->y*this->y);
    this->x = this->x/vectorLength;
    this->y = this->y/vectorLength;
    return *this;
}

float Vector2D::dot(const Vector2D &vect1, const Vector2D &vect2) {
    return vect1.x*vect2.x + vect1.y*vect2.y;
}

Vector2D Vector2D::triple_cross_product(const Vector2D &vect1, const Vector2D &vect2, const Vector2D &vect3) {
    return Vector2D::dot(vect1, vect3)*vect2 - Vector2D::dot(vect2, vect3)*vect1;
}

Vector2D Vector2D::normal_clockwise(const Vector2D &vect) {
    return Vector2D(vect.y, -vect.x);
}

Vector2D Vector2D::normal_counter_clockwise(const Vector2D &vect) {
    return Vector2D(-vect.y, vect.x);
}

float Vector2D::length() {
    return sqrt(x*x + y*y);
}

Vector2D Vector2D::zero() {
    return Vector2D(0, 0);
}

Vector2D Vector2D::left() {
    return Vector2D(-1, 0);
}

Vector2D Vector2D::right() {
    return Vector2D(1, 0);
}

Vector2D Vector2D::up() {
    return Vector2D(0, 1);
}

Vector2D Vector2D::down() {
    return Vector2D(0, -1);
}

sf::Vector2f Vector2D::to_sfml() {
    return sf::Vector2f(x,y);
}