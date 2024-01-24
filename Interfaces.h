#ifndef ENTITY_H_
#define ENTITY_H_

#include <assert.h>
#include <SFML/Graphics.hpp>
#include "Inputs.h"

class Shape; // forward declaration
struct PhysicsProperties; // forward declaration
class Game; // forward declaration

class Renderable {
public:
  virtual void render([[maybe_unused]] sf::RenderWindow &window, [[maybe_unused]] sf::Color color) const { }
  virtual void render([[maybe_unused]] sf::RenderWindow &window, [[maybe_unused]] const sf::Texture &texture) const { }
  virtual void render([[maybe_unused]] sf::RenderWindow &window) const { }
};

class Resolvable {
public:
  virtual bool is_resolvable() { return false; }
  virtual Shape* get_shape() { assert(false); }
  virtual PhysicsProperties& get_physics_props() { assert(false); }
};

class Interactable {
public:
  virtual void use_inputs([[maybe_unused]] const Inputs& player_inputs) {}
};

class Entity : public Renderable, public Resolvable, public Interactable {
private:
  Game* game = nullptr;
public:
  void set_game(Game* game) { this->game = game; }
  // virtual ~Entity() = default;
};

#endif /* !ENTITY_H_*/
