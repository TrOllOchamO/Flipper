#include "Interfaces.h"
#include "Polygone.h"
#include "PhysicsProperties.h"
#include <SFML/Graphics.hpp>

#ifndef LAUNCHER_H_
#define LAUNCHER_H_

class Launcher : public Entity {
private:
  Polygone shape;
  sf::Texture texture;
  float force = 0;
  PhysicsProperties props;

  bool can_move_up = true;
  bool can_move_down = true;
  bool can_launch = true;

  void update_value(int value);
  void launch();

public:
  Launcher(const std::string &texturePath);

  bool is_resolvable() override { return true; };
  Shape *get_shape() override { return &shape; }
  PhysicsProperties &get_physics_props() override { return props; }

  void use_inputs([[maybe_unused]] const Inputs &player_inputs) override;
  void render(sf::RenderWindow &window, sf::Color color) const override;
  void render(sf::RenderWindow &window) const override;
};

#endif /* !LAUNCHER_H_ */
