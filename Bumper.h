#ifndef BUMPER_H_
#define BUMPER_H_

#include "Physics.h"
#include "PhysicsProperties.h"
#include "Polygone.h"
#include "Renderable.h"
#include "Shape.h"
#include <SFML/Graphics.hpp>
#include <memory>

class Bumper: public Resolvable, public Renderable {
private:
  std::unique_ptr<Shape> shape;
  PhysicsProperties props;
  sf::Texture texture;
  sf::Sprite sprite;

public:
  Bumper(std::unique_ptr<Shape> shape, const std::string &texturePath);

  Shape *get_shape() override;
  PhysicsProperties &get_physics_props() override;
  void render(sf::RenderWindow &window, sf::Color color) const override;
  void render(sf::RenderWindow &window) const override;
};

#endif /* !BUMPER_H_ */
