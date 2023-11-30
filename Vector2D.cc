#include "Vector2D.h"
#include <math.h>

Vector2D &Vector2D::normalize() {
  const float vectorLength = std::sqrt(this->x * this->x + this->y * this->y);
  this->x = this->x / vectorLength;
  this->y = this->y / vectorLength;
  return *this;
}

float Vector2D::length() const { return Vector2D::length(*this); }

float Vector2D::dot(const Vector2D &other) const {
  return Vector2D::dot(*this, other);
}

Vector2D Vector2D::get_normalized_vector(const Vector2D &v) {
  Vector2D copy = v;
  return copy.normalize();
}

sf::Vector2f Vector2D::to_sfml() { return sf::Vector2f(x, y); }

float Vector2D::length(const Vector2D &v) {
  return sqrt(v.x * v.x + v.y * v.y);
}

float Vector2D::dot(const Vector2D &v1, const Vector2D &v2) {
  return v1.x * v2.x + v1.y * v2.y;
}

Vector2D Vector2D::triple_cross_product(const Vector2D &v1, const Vector2D &v2, const Vector2D &v3) {
  return Vector2D::dot(v1, v3) * v2 - Vector2D::dot(v2, v3) * v1;
}

Vector2D Vector2D::normal_clockwise(const Vector2D &v) {
  return Vector2D(v.y, -v.x);
}

Vector2D Vector2D::normal_counter_clockwise(const Vector2D &v) {
  return Vector2D(-v.y, v.x);
}

Vector2D Vector2D::zero() { return Vector2D(0, 0); }
Vector2D Vector2D::left() { return Vector2D(-1, 0); }
Vector2D Vector2D::right() { return Vector2D(1, 0); }
Vector2D Vector2D::up() { return Vector2D(0, 1); }
Vector2D Vector2D::down() { return Vector2D(0, -1); }

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

std::ostream &operator<<(std::ostream &os, const Vector2D &v) {
  os << "(" << v.x << ", " << v.y << ")";
  return os;
}

std::ostream& operator<<(std::ostream& os, const std::vector<Vector2D> &vector) {
    os << "[";

    size_t vectorSize = vector.size();
    for (size_t i = 0; i < vectorSize; ++i) {
        os << vector[i];
        if (i != vectorSize -1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

bool operator==(const Vector2D &v1, const Vector2D &v2) {
  return (v1.x == v2.x && v1.y == v2.y);
}
