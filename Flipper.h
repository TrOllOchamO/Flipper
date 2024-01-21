#include "Interfaces.h"
#include "Polygone.h"
#include <SFML/Graphics.hpp>

#ifndef FLIPPER_H_
#define FLIPPER_H_

class Flipper : public Entity {
private:
  Polygone left;
  Polygone right;
  float left_rotation = 0;
  float right_rotation = 0;
  sf::Texture texture;

public:
  Flipper(const std::string &texturePath);

  bool is_resolvable() override { return true; };
  Shape *get_shape() override { return this->shape.get(); }
  PhysicsProperties &get_physics_props() override { return this->props; }

  void upate(bool left, bool right);
  void render(sf::RenderWindow &window, sf::Color color) const override;
  void render(sf::RenderWindow &window) const override;
};

#endif /* !FLIPPER_H_ */
