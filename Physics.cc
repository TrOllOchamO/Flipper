#include "Physics.h"
#include <iostream>
#include <type_traits>

#define SEPARATION_MAX_ITERATION 300
#define SEPARATION_THRESHOLD 0.001
#define RESTING_CONTACT_EPSILON 0.00001 

void Physics::solve(Shape *s1, PhysicsProperties &data1, Shape *s2, PhysicsProperties &data2, float dt) {
  std::vector<Vector2D> simplex;

  if (!data1.should_react_with_other && !data2.should_react_with_other) {
    return;
  }

  // if there is no collision to begin with, there is nothing to do
  if (!Collision::GJK(s1, s2, simplex)) {
    return;
  }

  Vector2D direction = Vector2D::zero();
  Collision::EPA(s1, s2, direction, simplex);
  Physics::separate_shapes(s1, data1.velocity, s2, data2.velocity,  dt);
  Physics::resolve_velocities(data1, data2, direction);
}

void Physics::update(Shape *s, PhysicsProperties &data, float dt) {
  data.velocity += data.acceleration * dt;
  Physics::update_pos_based_on_velocity(s, data.velocity, dt);
}

void Physics::update_pos_based_on_velocity(Shape *s, const Vector2D &velocity, float dt) {
  Vector2D new_position = s->get_pos() + (velocity * dt);
  s->set_pos(new_position);
}

// simply implement the formula on slide 18
// https://perso.liris.cnrs.fr/nicolas.pronost/UUCourses/GamePhysics/lectures/lecture%207%20Collision%20Resolution.pdf
float Physics::get_impulse_value(const PhysicsProperties &data1, const PhysicsProperties &data2, const Vector2D &direction) {
  // the bounciness factor is not a mistake, it's intentional so that objects bounciness affect the ball velocity
  // and not there own velocity
  return -(1 + data2.bounciness) * (data1.velocity - data2.velocity).dot(direction) / (1/data1.mass + 1/data2.mass);
}

// simply implement the formula on slide 19
// https://perso.liris.cnrs.fr/nicolas.pronost/UUCourses/GamePhysics/lectures/lecture%207%20Collision%20Resolution.pdf
void Physics::resolve_velocities(PhysicsProperties &data1, PhysicsProperties &data2, const Vector2D &direction) {
  Vector2D new_velocity1 = data1.velocity;
  Vector2D new_velocity2 = data2.velocity;

  if (data1.should_react_with_other) {
    const float impulse = get_impulse_value(data1, data2, direction);
    if (std::abs(impulse) > RESTING_CONTACT_EPSILON) {
      new_velocity1 = (impulse/data1.mass) * direction;
    }
  }

  if (data2.should_react_with_other) {
    const float impulse = get_impulse_value(data2, data1, direction);
    if (std::abs(impulse) > RESTING_CONTACT_EPSILON) {
      new_velocity2 = (impulse/data2.mass) * direction;
    }
  }

  data1.velocity = new_velocity1;
  data2.velocity = new_velocity2;
}

bool Physics::separate_shapes(Shape *s1, Vector2D &v1, Shape *s2, Vector2D &v2, float dt) {
  // reset both shapes positions before the update call
  Physics::update_pos_based_on_velocity(s1, v1, -dt);
  Physics::update_pos_based_on_velocity(s2, v2, -dt);

  const float dist = Collision::get_minimum_dist(s1, s2);
  if (dist < SEPARATION_THRESHOLD) {
    // they were already colliding then it's hopeless to separate them so return
    if (dist <= 0) {
      return false;
    }

    // if they were already touching before the update
    return true;
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
      return true;
    }

    dt /= 2;
  }

  return true;
}
