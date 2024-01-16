#ifndef INTERFACES_H_
#define INTERFACES_H_

#include <assert.h>
#include <SFML/Graphics.hpp>
#include "Inputs.h"

class Shape; // forward declaration
struct PhysicsProperties; // forward declaration

class Entity {};

class Resolvable {
public:
  virtual Shape* get_shape() = 0;
  virtual PhysicsProperties& get_physics_props() = 0;
};

class Renderable {
public:
  virtual void render([[maybe_unused]] sf::RenderWindow &window, [[maybe_unused]] sf::Color color) const { assert(false); };
  virtual void render([[maybe_unused]] sf::RenderWindow &window) const { assert(false); };
};

class Interactable {
  public:
  virtual void use_inputs(const Inputs& player_inputs) = 0;
};

#endif /* !INTERFACES_H_*/
