#include "Interfaces.h"
#include "Polygone.h"
#include <SFML/Graphics.hpp>
#include "PhysicsProperties.h"

#ifndef FLIPPER_H_
#define FLIPPER_H_

enum FLIPPER_ORIENTATION {
  LEFT,
  RIGHT,
};

class Flipper: public Entity {
private:
  Polygone shape;
  FLIPPER_ORIENTATION orientation;
  PhysicsProperties props;
  float rotation = 0;
  sf::Texture texture;

public:
  Flipper(const std::string &texturePath, FLIPPER_ORIENTATION orientation);

  bool is_resolvable() override { return true; };
  Shape *get_shape() override { return &shape; }
  PhysicsProperties &get_physics_props() override { return props; }

  void use_inputs([[maybe_unused]] const Inputs &player_inputs) override;
  void render(sf::RenderWindow &window, sf::Color color) const override;
  void render(sf::RenderWindow &window) const override;
};

#endif /* !FLIPPER_H_ */
