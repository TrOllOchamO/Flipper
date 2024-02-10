#ifndef MULTIPLICATEUR_H_
#define MULTIPLICATEUR_H_

#include "Circle.h"
#include "Shape.h"
#include "PhysicsProperties.h"
#include <SFML/Graphics.hpp>
#include <memory>

class Multiplicateur: public Entity {
private:
  std::unique_ptr<Shape> shape;
  PhysicsProperties props;
  sf::Texture texture;

public:
  Multiplicateur(std::unique_ptr<Shape> shape, const std::string &texturePath);

  bool is_resolvable() override { return true; } ;
  Shape* get_shape() override { return this->shape.get(); }
  PhysicsProperties& get_physics_props() override { return this->props; }

  void render(sf::RenderWindow &window, sf::Color color) const override;
  void render(sf::RenderWindow &window) const override;
};

#endif /* !MULTIPLICATEUR_H_ */
