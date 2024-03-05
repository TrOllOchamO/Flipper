#include "Launcher.h"
#include "Ball.h"
#include "Game.h"
#include "Polygone.h"
#include "Vector2D.h"
#include <SFML/Graphics/Color.hpp>
#include <memory>

#define BALL_RADIUS 8
#define BALL_MASS 1

Launcher::Launcher(const std::string &texturePath) : shape(Polygone()) {
  if (!texture.loadFromFile(texturePath)) {
    std::cerr << "Error loading texture from file: " << texturePath << std::endl;
  }
  texture.setRepeated(true);

  if (!bufferLaunch.loadFromFile("../resources/launch.wav")) {
    std::cerr << "Error loading sound from file: ../resources/launch.wav" << std::endl;
  } else {
    soundLaunch.setBuffer(bufferLaunch);
  }

  if (!bufferLoose.loadFromFile("../resources/chval.wav")) {
    std::cerr << "Error loading sound from file: ../resources/chval.wav" << std::endl;
  } else {
    soundLoose.setBuffer(bufferLoose);
  }

  props.should_be_affected_by_others = false;
  props.mass = 10000000000;
  props.velocity = Vector2D::zero();
  props.acceleration = Vector2D::zero();
  props.bounciness = 0.5;

  shape.add_points({Vector2D(360, 750), Vector2D(380, 750), Vector2D(380, 790), Vector2D(360, 790)});
};

void Launcher::update(const Inputs &player_inputs, [[maybe_unused]] float dt) {
  Ball *ball_handle = game->get_ball_handle();
  if (player_inputs.space_launcher && ball_handle == nullptr && game->get_life()>0) {
    add_ball();
  }
  if (player_inputs.up_launcher && can_move_up) {
    can_move_up = false;
    update_value(1);
  }
  if (player_inputs.down_launcher && can_move_down) {
    can_move_down = false;
    update_value(-1);
  }
  if (player_inputs.enter_launcher && can_launch) {
    can_launch = false;
    launch();
  }
  if (!player_inputs.up_launcher) {
    can_move_up = true;
  }
  if (!player_inputs.down_launcher) {
    can_move_down = true;
  }
  if (!player_inputs.enter_launcher) {
    can_launch = true;
  }
  if (ball_handle != nullptr) {
    check_if_ball_out();
  }
}

void Launcher::update_value(int value) {
  if (force + value * 3 > 30 || force + value * 3 < 0) {
    return;
  }

  if (ball_ok() && value < 0) {
    Ball *ball_handle = game->get_ball_handle();
    ball_handle->set_posiion(ball_handle->get_position() - Vector2D(0, 4));
  }

  force += value * 3;
  shape.clear();
  shape.add_points({Vector2D(360, 750 + force), Vector2D(380, 750 + force), Vector2D(380, 790), Vector2D(360, 790)});
}

void Launcher::launch() {
  if (ball_ok()) {
    Ball *ball_handle = game->get_ball_handle();
    ball_handle->set_posiion(Vector2D(362, 732));
    ball_handle->set_velocity(Vector2D(0, -force * 50));
    soundLaunch.play();
  }
  force = 0;
  shape.clear();
  shape.add_points({Vector2D(360, 750), Vector2D(380, 750), Vector2D(380, 790), Vector2D(360, 790)});
}

void Launcher::render(sf::RenderWindow &window, sf::Color color) const {
  shape.render(window, color);
}

void Launcher::render(sf::RenderWindow &window) const {
  shape.render(window, texture);
}

void Launcher::add_ball() {
  std::unique_ptr<Ball> new_ball = std::make_unique<Ball>(Vector2D(362, 732), BALL_RADIUS, "resources/bille.png");
  game->make_ball(std::move(new_ball));
}

bool Launcher::ball_ok() {
  Ball *ball_handle = game->get_ball_handle();
  return ball_handle != nullptr && ball_handle->get_position().x > 350;
}

void Launcher::check_if_ball_out() {
  Ball *ball_handle = game->get_ball_handle();
  if (Collision::are_colliding(ball_handle->get_shape(), &kill_zone)) {
    soundLoose.play();
    game->loose_life();
    if (game->get_life() > 0) {
      ball_handle->set_radius(8);
      ball_handle->get_physics_props().mass = BALL_MASS;
      ball_handle->set_posiion(Vector2D(362, 732));
      ball_handle->set_velocity(Vector2D::zero());
    } else {
      game->kill_ball();
    }
  }
}
