#ifndef WALL_H_
#define WALL_H_

#include "Physics.h"
#include "PhysicsProperties.h"
#include "Polygone.h"
#include "Shape.h"
#include <SFML/Graphics.hpp>
#include <memory>

class Wall : public Entity {
private:
  std::unique_ptr<Shape> shape;
  PhysicsProperties props;
  sf::Texture texture;

public:
  Wall(std::unique_ptr<Shape> shape, const std::string& texturePath);

  bool is_resolvable() override { return true; } ;
  Shape* get_shape() override { return this->shape.get(); }
  PhysicsProperties& get_physics_props() override { return this->props; }

  void render(sf::RenderWindow &window, sf::Color color) const override;
  void render(sf::RenderWindow &window) const override;
};

#endif /* !WALL_H_ */
