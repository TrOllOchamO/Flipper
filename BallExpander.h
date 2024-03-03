#include <SFML/Graphics/Color.hpp>
#include <iostream>
#include "Vector2D.h"
#include "PhysicsProperties.h"
#include "Physics.h"
#include "Interfaces.h"
#include "Circle.h"
#include <SFML/Graphics.hpp>
#include <memory>

#ifndef BALL_EXPANDER_H_
#define BALL_EXPANDER_H_

class BallExpander : public Entity {
private:
  std::unique_ptr<Circle> shape;
  sf::Color color;
  sf::Texture texture;
  bool has_been_taken= false;
  float dt_since_has_been_taken = 0;
  float previous_ball_radius;
  float previous_ball_mass;

public:
  BallExpander(Vector2D pos, float radius, const std::string& texturePath);

  void update([[maybe_unused]] const Inputs &player_inputs, [[maybe_unused]] float dt) override;
  void render(sf::RenderWindow &window, sf::Color color) const override;
  void render(sf::RenderWindow &window) const override;
};

#endif /* !BALL_EXPANDER_H_ */
