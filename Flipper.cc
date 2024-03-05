#include "Flipper.h"
#include "Ball.h"
#include "Collision.h"
#include "Game.h"
#include "Polygone.h"
#include "Vector2D.h"
#include <SFML/Graphics/Color.hpp>
#include <cmath>
#include <vector>

#define ROTATION_STEP 17
#define ROTATE_LIMITE_ACTIVATED 0.5
#define ROTATE_LIMITE_DESACTIVATED 0.0
#define ANGULAR_VELOCITY_WHEN_ACTIVATED 2.0
#define DEFAULT_BOUNCINESS 0.6
#define DEFAULT_ROTATION 0.3

#define LEFT_FLIPPER_POINTS { Vector2D(135, 735), Vector2D(155, 740), Vector2D(135, 745), Vector2D(55, 750), Vector2D(50, 745), Vector2D(50, 735), Vector2D(55, 730)}
#define RIGHT_FLIPPER_POINTS { Vector2D(195, 740), Vector2D(215, 735), Vector2D(295, 730), Vector2D(300, 735), Vector2D(300, 745), Vector2D(295, 750), Vector2D(215, 745) }
#define LEFT_ROTATION_POINT Vector2D(60, 740)
#define RIGHT_ROTATION_POINT Vector2D(290, 740)

Flipper::Flipper(const std::string &texturePath, FLIPPER_ORIENTATION orientation) : shape(Polygone()), orientation(orientation) {
  if (!texture.loadFromFile(texturePath)) {
    std::cerr << "Error loading texture from file: " << texturePath << std::endl;
  }
  texture.setRepeated(true);

  if (!buffer.loadFromFile("../resources/tac.wav")) {
    std::cerr << "Error loading sound from file: ../resources/tac.wav" << std::endl;
  }

  props.should_be_affected_by_others = false;
  props.velocity = Vector2D::zero();
  props.acceleration = Vector2D::zero();
  props.bounciness = DEFAULT_BOUNCINESS;

  switch (orientation) {
  case LEFT:
    shape.add_points(LEFT_FLIPPER_POINTS);
    rotation_direction = CLOCKWISE;
    rotation_point = LEFT_ROTATION_POINT;
    is_activated = &Inputs::left_flipper;
    break;
  case RIGHT:
    shape.add_points(RIGHT_FLIPPER_POINTS);
    rotation_direction = COUNTERCLOCKWISE;
    rotation_point = RIGHT_ROTATION_POINT;
    is_activated = &Inputs::right_flipper;
    break;
  }

  shape.rotate(rotation_direction * DEFAULT_ROTATION, rotation_point);
};

void Flipper::update(const Inputs &player_inputs, float dt) {
  props.should_affect_others = true;

  const bool flipper_activated = player_inputs.*is_activated;
  if (flipper_activated && rotation < ROTATE_LIMITE_ACTIVATED) {
    props.should_affect_others = false;
    shape.rotate(-rotation_direction * ROTATION_STEP, rotation_point, dt);
    rotation += ROTATION_STEP * dt;
    bump_the_ball();
  } else if (!flipper_activated && rotation > ROTATE_LIMITE_DESACTIVATED) {
    props.should_affect_others = false;
    shape.rotate(rotation_direction * ROTATION_STEP, rotation_point, dt);
    rotation -= ROTATION_STEP * dt;
  }
};

void Flipper::bump_the_ball() {
  Ball *ball_handle = game->get_ball_handle();
  if (ball_handle == nullptr) {
    return;
  }

  auto ball_shape = ball_handle->get_shape();

  std::vector<Vector2D> simplex;
  if (!Collision::GJK(ball_shape, &shape, simplex)) {
    return;
  }

  // FIXME améliorer le hack ?
  Vector2D direction;
  Collision::EPA(ball_shape, &shape, direction, simplex);

  const Vector2D ball_current_velocity = ball_handle->get_props()->velocity;
  const float dist_from_rotation_point = (ball_shape->get_center() - rotation_point).length();
  const Vector2D new_velocity = ball_current_velocity - (direction * (20 + log(dist_from_rotation_point)));
  ball_handle->set_velocity(new_velocity);
}

void Flipper::render(sf::RenderWindow &window, sf::Color color) const {
  shape.render(window, color);
}

void Flipper::render(sf::RenderWindow &window) const {
  shape.render(window, texture);
}