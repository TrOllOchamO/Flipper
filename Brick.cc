#include "Brick.h"
#include "Ball.h"
#include "Game.h"
#include "Collision.h"
#include "Physics.h"
#include "Vector2D.h"
#include <SFML/Graphics/Color.hpp>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <stdio.h>

Brick::Brick(Vector2D pos, float width, float height) : shape(std::make_unique<Rectangle>(pos, width, height)) {
  auto max = 255;
  auto red = (rand() % (max - 200)) + 200;
  auto green = rand() % 15;
  auto blue = rand() % 15;

  color = sf::Color(red, green, blue, max);

  props.should_be_affected_by_others = false;
  props.should_affect_others = false;
  props.mass = 10000000000;
  props.velocity = Vector2D::zero();
  props.acceleration = Vector2D::zero();
  props.bounciness = 0.7;
}

void Brick::render(sf::RenderWindow &window, sf::Color color) const {
  shape->render(window, color);
}

void Brick::render(sf::RenderWindow &window) const {
  shape->render(window, color);
}

void Brick::update([[maybe_unused]] const Inputs &player_inputs, float dt) {
  Ball *ball_handle = game->get_ball_handle();

  if (ball_handle == nullptr) {
    return;
  }

  Shape* brick_shape = shape.get();
  Shape* ball_shape = ball_handle->get_shape();
  if (Collision::are_colliding(brick_shape, ball_shape)) {
    props.should_affect_others = true;
    Physics::solve(brick_shape, props, ball_shape, ball_handle->get_physics_props(), dt);


    game->update_score(1);
    this->should_get_killed = true;
  }

}
