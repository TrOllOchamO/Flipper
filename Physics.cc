#include "Physics.h"
#include <cmath>
#include <iostream>
#include <type_traits>
#include <limits>

#define SEPARATION_MAX_ITERATION 300
#define SEPARATION_THRESHOLD 0.001
#define RESTING_CONTACT_EPSILON 0.00001 

bool Physics::solve(Shape *s1, PhysicsProperties &data1, Shape *s2, PhysicsProperties &data2, float dt) {
  std::vector<Vector2D> simplex;

  const bool both_object_are_not_affected = (!data1.should_be_affected_by_others && !data2.should_be_affected_by_others);
  const bool one_object_doesnt_interact = !data1.should_affect_others || !data2.should_affect_others;
  if (both_object_are_not_affected || one_object_doesnt_interact) {
    return false;
  }

  // if there is no collision to begin with, there is nothing to do
  if (!Collision::GJK(s1, s2, simplex)) {
    return false;
  }

  Vector2D direction = Vector2D::zero();
  Collision::EPA(s1, s2, direction, simplex);
  Physics::separate_shapes(s1, data1.velocity, s2, data2.velocity,  dt);
  const Vector2D relative_velocity = data1.velocity - data2.velocity;
  const bool are_already_separating = relative_velocity.dot(direction) < 0;
  if (!are_already_separating) {
    Physics::resolve_velocities(data1, data2, direction);
    return true;
  }

  return false;
}

void Physics::update(Shape *s, PhysicsProperties &data, float dt) {
  data.velocity += data.acceleration * dt;
  Physics::update_pos_based_on_velocity(s, data.velocity, dt);
}

void Physics::update_pos_based_on_velocity(Shape *s, const Vector2D &velocity, float dt) {
  Vector2D new_position = s->get_pos() + (velocity * dt);

  s->set_pos(new_position);
}

// simply implement the formula on slide 19
// https://perso.liris.cnrs.fr/nicolas.pronost/UUCourses/GamePhysics/lectures/lecture%207%20Collision%20Resolution.pdf
void Physics::resolve_velocities(PhysicsProperties &data1, PhysicsProperties &data2, const Vector2D &direction) {
  float mass1 = data1.mass;
  float mass2 = data2.mass;
  if (!data1.should_be_affected_by_others) { mass1 = std::numeric_limits<float>::infinity(); }
  if (!data2.should_be_affected_by_others) { mass2 = std::numeric_limits<float>::infinity(); }
  
  const Vector2D relative_velocities = data1.velocity - data2.velocity;
  const float impulse_without_bounciness = relative_velocities.dot(direction) / (1/mass1 + 1/mass2);

  const float impulse1 = -(1 + data2.bounciness) * impulse_without_bounciness;
  data1.velocity += (impulse1/mass1) * direction;

  const float impulse2 = -(1 + data1.bounciness) * impulse_without_bounciness;
  data2.velocity -= (impulse2/data2.mass) * direction;
}

bool Physics::separate_shapes(Shape *s1, Vector2D &v1, Shape *s2, Vector2D &v2, float dt) {
  // reset both shapes positions before the update call
  Physics::update_pos_based_on_velocity(s1, v1, -dt);
  Physics::update_pos_based_on_velocity(s2, v2, -dt);

  const float dist = Collision::get_minimum_dist(s1, s2);
  if (dist < SEPARATION_THRESHOLD) {
    Physics::update_pos_based_on_velocity(s1, v1, dt);
    Physics::update_pos_based_on_velocity(s2, v2, dt);

    // they were already colliding then it's hopeless to separate them so return
    return false;
  }

  dt /= 2;

  for (int i = 0; i < SEPARATION_MAX_ITERATION; ++i) {
    Physics::update_pos_based_on_velocity(s1, v1, dt);
    Physics::update_pos_based_on_velocity(s2, v2, dt);

    const float dist = Collision::get_minimum_dist(s1, s2);

    // if we collide it mean the step was too large so step back
    if (dist < 0) {
      Physics::update_pos_based_on_velocity(s1, v1, -dt);
      Physics::update_pos_based_on_velocity(s2, v2, -dt);
    } else if (dist < SEPARATION_THRESHOLD) { // if we are touching
      return false;
    }

    dt /= 2;
  }

  return true;
}
