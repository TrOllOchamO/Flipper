#include "Interfaces.h"
#include "Polygone.h"
#include "PhysicsProperties.h"
#include "Ball.h"
#include "Game.h"
#include "Rectangle.h"
#include "Vector2D.h"
#include <SFML/Graphics.hpp>

#ifndef LAUNCHER_H_
#define LAUNCHER_H_

class Launcher : public Entity {
private:
  Polygone shape;
  sf::Texture texture;
  float force = 0;
  PhysicsProperties props;
  Rectangle kill_zone = Rectangle(Vector2D(0,816), 400, 5);

  bool can_move_up = true;
  bool can_move_down = true;
  bool can_launch = true;

  void update_value(int value);
  void launch();

  void add_ball();

  void check_if_ball_out();

  sf::SoundBuffer bufferLaunch;
  sf::Sound soundLaunch;
  
  sf::SoundBuffer bufferLoose;
  sf::Sound soundLoose;

public:
  Launcher(const std::string &texturePath);

  bool ball_ok();
  bool is_resolvable() override { return true; };
  Shape *get_shape() override { return &shape; }
  PhysicsProperties &get_physics_props() override { return props; }

  void update([[maybe_unused]] const Inputs &player_inputs, [[maybe_unused]] float dt) override;
  void render(sf::RenderWindow &window, sf::Color color) const override;
  void render(sf::RenderWindow &window) const override;
};

#endif /* !LAUNCHER_H_ */
