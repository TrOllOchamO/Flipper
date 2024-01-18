#ifndef PHYSICS_PROPERTIES_H_
#define PHYSICS_PROPERTIES_H_

#include "Vector2D.h"

struct PhysicsProperties {
  bool should_react_with_other;
  Vector2D velocity;
  Vector2D acceleration;
  float bounciness;
  float mass;
  float angular_velocity;
};

#endif /* !PHYSICS_PROPERTIES_H_*/
