#ifndef PHYSICS_PROPERTIES_H_
#define PHYSICS_PROPERTIES_H_

#include "Vector2D.h"

struct PhysicsProperties {
  bool should_be_affected_by_others = true;
  bool should_affect_others = true;
  Vector2D velocity = Vector2D::zero();
  Vector2D acceleration = Vector2D::zero();
  float bounciness = 0.7;
  float mass = 1;
  float angular_velocity = 0;
};

#endif /* !PHYSICS_PROPERTIES_H_*/
