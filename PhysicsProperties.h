#ifndef PHYSICS_PROPERTIES_H_
#define PHYSICS_PROPERTIES_H_

#include "Vector2D.h"

struct PhysicsProperties {
  bool should_react_with_other = true;
  Vector2D velocity = Vector2D::zero();
  Vector2D acceleration = Vector2D::zero();
  float bounciness = 0.7;
  float mass = 10000;
  float angular_velocity = 0;
};

#endif /* !PHYSICS_PROPERTIES_H_*/
