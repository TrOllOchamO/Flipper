#include "BallExpander.h"
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

#define RESPAWN_TIME 10

BallExpander::BallExpander(Vector2D pos, float radius, const std::string& texturePath) : shape(std::make_unique<Circle>(pos, radius)) {
    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "Error loading texture from file: " << texturePath << std::endl;
    }
    texture.setRepeated(true);
}

void BallExpander::render(sf::RenderWindow &window, sf::Color color) const {
  shape->render(window, color);
}

void BallExpander::render(sf::RenderWindow &window) const {
  if (!has_been_taken) {
    shape->render(window, texture);
  }
}

void BallExpander::update([[maybe_unused]] const Inputs &player_inputs, float dt) {
  Ball *ball_handle = game->get_ball_handle();
  if (ball_handle == nullptr) {
    has_been_taken = false;
    dt_since_has_been_taken = 0;
    return;
  }

  if (has_been_taken) {
    dt_since_has_been_taken += dt;
    if (dt_since_has_been_taken > RESPAWN_TIME) {
      ball_handle->get_physics_props().mass = previous_ball_mass;
      ball_handle->set_radius(previous_ball_radius);
      dt_since_has_been_taken = 0;
      has_been_taken = false;
    }
    return;
  }

  Shape* brick_shape = shape.get();
  Shape* ball_shape = ball_handle->get_shape();
  if (Collision::are_colliding(brick_shape, ball_shape)) {
    previous_ball_mass = ball_handle->get_physics_props().mass;
    ball_handle->get_physics_props().mass *= 4;
    float ball_radius = ball_handle->get_radius();
    previous_ball_radius = ball_radius;
    ball_handle->set_radius(ball_radius * 2);
    has_been_taken = true;
    // TODO play sound
  }
}
