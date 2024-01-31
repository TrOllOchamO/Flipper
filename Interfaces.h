#ifndef ENTITY_H_
#define ENTITY_H_

#include <assert.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Inputs.h"

class Shape; // forward declaration
class Game; // forward declaration
struct PhysicsProperties; // forward declaration

class Renderable {
public:
  virtual void render([[maybe_unused]] sf::RenderWindow &window, [[maybe_unused]] sf::Color color) const { }
  virtual void render([[maybe_unused]] sf::RenderWindow &window, [[maybe_unused]] const sf::Texture &texture) const { }
  virtual void render([[maybe_unused]] sf::RenderWindow &window) const { }
  virtual ~Renderable() = default;
};

class Resolvable {
public:
  virtual bool is_resolvable() { return false; }
  virtual Shape* get_shape() { assert(false); }
  virtual PhysicsProperties& get_physics_props() { assert(false); }
  virtual ~Resolvable() = default;
};

class Interactable {
public:
  virtual void update([[maybe_unused]] const Inputs& player_inputs) {}
  virtual ~Interactable() = default;
};

class Entity : public Renderable, public Resolvable, public Interactable {
protected: 
  Game* game = nullptr;
private:
public:
  void set_game(Game* new_game) { this->game = new_game; }
  virtual ~Entity() = default;
};

#endif /* !ENTITY_H_*/
