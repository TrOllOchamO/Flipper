#include <iostream>
#include "Vector2D.h"
#include "PhysicsProperties.h"
#include "Physics.h"
#include "Renderable.h"
#include "Circle.h"
#include <SFML/Graphics.hpp>

#ifndef BALL_H_
#define BALL_H_

class Ball : public Resolvable, public Renderable {
private:
  Circle shape;
  PhysicsProperties props;

public:
  Ball(Vector2D pos, float radius);

  Shape * get_shape() override;
  PhysicsProperties& get_physics_props() override;
  void render(sf::RenderWindow &window, sf::Color color) const override;
  void render(sf::RenderWindow &window) const override;

  Vector2D get_center_position();
};

#endif /* !BALL_H_ */
