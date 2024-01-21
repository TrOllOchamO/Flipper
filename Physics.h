#include "Shape.h"
#include "Collision.h"
#include "PhysicsProperties.h"

#ifndef PHYSICS_H_
#define PHYSICS_H_

/* https://perso.liris.cnrs.fr/nicolas.pronost/UUCourses/GamePhysics/lectures/lecture%207%20Collision%20Resolution.pdf */

class Physics {
public:
  // if the two convex shapes are colliding, try to resolve the collision
  // by taking in account the pysics properties of both elements
  static void solve(Shape *s1, PhysicsProperties &data1, Shape *s2, PhysicsProperties &data2, float dt);

  // 
  static void update(Shape *s, PhysicsProperties &data, float dt);
  
private:
  // try to separate the 2 shapes by finding the exact point before the entered in collision
  static bool separate_shapes(Shape *s1, Vector2D &v1, Shape *s2, Vector2D &v2, float dt);

  //
  static void resolve_velocities(PhysicsProperties &data1, PhysicsProperties &data2, const Vector2D &direction);

  static void update_pos_based_on_velocity(Shape *s, const Vector2D &velocity, float dt);
};

#endif /* !PHYSICS_H_*/
