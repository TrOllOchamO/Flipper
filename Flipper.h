#include "Interfaces.h"
#include "Polygone.h"
#include "Inputs.h"
#include <SFML/Graphics.hpp>
#include "PhysicsProperties.h"

#ifndef FLIPPER_H_
#define FLIPPER_H_

enum FLIPPER_ORIENTATION {
  LEFT,
  RIGHT,
};

enum FLIPPER_ROTATION_DIRECTION {
  CLOCKWISE = 1,
  COUNTERCLOCKWISE = -1,
};

class Flipper: public Entity {
private:
  Polygone shape;
  FLIPPER_ORIENTATION orientation;
  PhysicsProperties props;
  float rotation = 0;
  bool collided_with_ball_on_last_update = false;
  sf::Texture texture;
  bool const Inputs::* is_activated = nullptr;
  Vector2D rotation_point;
  FLIPPER_ROTATION_DIRECTION rotation_direction;

  void bump_the_ball(); 

public:
  Flipper(const std::string &texturePath, FLIPPER_ORIENTATION orientation);

  bool is_resolvable() override { return true; };
  Shape *get_shape() override { return &shape; }
  PhysicsProperties &get_physics_props() override { return props; }

  void update([[maybe_unused]] const Inputs &player_inputs, [[maybe_unused]] float dt) override;
  void render(sf::RenderWindow &window, sf::Color color) const override;
  void render(sf::RenderWindow &window) const override;
};

#endif /* !FLIPPER_H_ */
