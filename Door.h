#ifndef DOOR_H_
#define DOOR_H_

#include "Physics.h"
#include "PhysicsProperties.h"
#include "Polygone.h"
#include "Shape.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <memory>

class Door : public Entity {
private:
  Polygone shape;
  PhysicsProperties props;
  sf::Texture texture;

public:
  Door(const std::string& texturePath);

  bool is_resolvable() override;

  Shape* get_shape() override { return &shape; }
  PhysicsProperties& get_physics_props() override { return this->props; }

  void render(sf::RenderWindow &window, sf::Color color) const override;
  void render(sf::RenderWindow &window) const override;
};

#endif /* !DOOR_H_ */
