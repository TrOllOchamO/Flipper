#ifndef ENTITY_H_
#define ENTITY_H_

#include <assert.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Inputs.h"
#include <iostream>

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
  virtual void update([[maybe_unused]] const Inputs& player_inputs, [[maybe_unused]] float dt) {}
  virtual ~Interactable() = default;
};

class Entity : public Renderable, public Resolvable, public Interactable {
protected: 
  Game* game = nullptr;
  bool should_get_killed = false;
  float points_add = 0;
  float mult_add = 0;

private:

public: 
  sf::SoundBuffer buffer;
  sf::Sound sound;
  void play_audio(){
    sound.setBuffer(buffer);
    if(buffer.getDuration().asSeconds()>0){
      sound.play();
    }
  };
  float get_points_to_add() {return points_add;}
  float get_mult() {return mult_add;}
  void kill() { should_get_killed = true; }
  bool has_to_be_killed() { return should_get_killed; }
  void set_game(Game* new_game) { this->game = new_game; }
  virtual ~Entity() = default;
};

#endif /* !ENTITY_H_*/
