#include <SFML/Graphics/Color.hpp>
#include <iostream>
#include "Vector2D.h"
#include "PhysicsProperties.h"
#include "Physics.h"
#include "Interfaces.h"
#include "Rectangle.h"
#include <SFML/Graphics.hpp>
#include <memory>

#ifndef BRICK_H_
#define BRICK_H_

class Brick : public Entity {
private:
  std::unique_ptr<Rectangle> shape;
  PhysicsProperties props;
  sf::Color color;

public:
  Brick(Vector2D pos, float width, float heigth);

  PhysicsProperties* get_props() { return &props; }

  bool is_resolvable() override { return true; } ;
  Shape* get_shape() override { return this->shape.get(); }
  PhysicsProperties& get_physics_props() override { return this->props; }

  void update([[maybe_unused]] const Inputs &player_inputs, [[maybe_unused]] float dt) override;
  void render(sf::RenderWindow &window, sf::Color color) const override;
  void render(sf::RenderWindow &window) const override;
};

#endif /* !BRICK_H_ */
