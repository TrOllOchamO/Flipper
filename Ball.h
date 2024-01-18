#include <iostream>
#include "Vector2D.h"
#include "PhysicsProperties.h"
#include "Physics.h"
#include "Interfaces.h"
#include "Circle.h"
#include <SFML/Graphics.hpp>

#ifndef BALL_H_
#define BALL_H_

class Ball : public Entity {
private:
  std::unique_ptr<Shape> shape;
  PhysicsProperties props;
  sf::Texture texture;

public:
  Ball(Vector2D pos, float radius, const std::string& texturePath);

  bool is_resolvable() override { return true; } ;
  Shape* get_shape() override { return this->shape.get(); }
  PhysicsProperties& get_physics_props() override { return this->props; }

  void render(sf::RenderWindow &window, sf::Color color) const override;
  void render(sf::RenderWindow &window) const override;
};

#endif /* !BALL_H_ */
