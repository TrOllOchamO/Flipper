#include "Interfaces.h"
#include "Polygone.h"
#include <SFML/Graphics.hpp>
#include "PhysicsProperties.h"

#ifndef FLIPPER_LEFT_H_
#define FLIPPER_LEFT_H_

class FlipperLeft : public Entity {
private:
  Polygone shape;
  PhysicsProperties props;
  float rotation = 0;
  sf::Texture texture;

public:
  FlipperLeft(const std::string &texturePath);

  bool is_resolvable() override { return true; };
  Shape *get_shape() override { return &shape; }
  PhysicsProperties &get_physics_props() override { return props; }

  void use_inputs([[maybe_unused]] const Inputs &player_inputs) override;
  void render(sf::RenderWindow &window, sf::Color color) const override;
  void render(sf::RenderWindow &window) const override;
};

#endif /* !FLIPPER_LEFT_H_ */
