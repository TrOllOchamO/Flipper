#ifndef WALL_H_
#define WALL_H_

#include "Physics.h"
#include "PhysicsProperties.h"
#include "Polygone.h"
#include "Renderable.h"
#include "Shape.h"
#include <SFML/Graphics.hpp>
#include <memory>

class Wall : public Resolvable, public Renderable, public Entity {
private:
  std::unique_ptr<Shape> shape;
  PhysicsProperties props;
  sf::Texture texture;
  sf::Sprite sprite;

public:
  Wall(std::unique_ptr<Shape> shape, const std::string &texturePath);

  Shape *get_shape() override;
  PhysicsProperties &get_physics_props() override;
  void render(sf::RenderWindow &window, sf::Color color) const override;
  void render(sf::RenderWindow &window) const override;
};

#endif /* !WALL_H_ */
