#ifndef RANDOMIZER_H_
#define RANDOMIZER_H_

#include "Physics.h"
#include "PhysicsProperties.h"
#include "Polygone.h"
#include "Shape.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>

class Randomizer: public Entity {
private:
  std::unique_ptr<Shape> shape;
  PhysicsProperties props;
  sf::Texture texture;
  bool keep = false;
  int c=0;

  sf::SoundBuffer bufferS;
  sf::Sound soundS;

public:
  Randomizer(std::unique_ptr<Shape> shape, const std::string &texturePath);

  bool is_resolvable() override { return true; } ;
  Shape* get_shape() override { return this->shape.get(); }
  PhysicsProperties& get_physics_props() override { return this->props; }

  void render(sf::RenderWindow &window, sf::Color color) const override;
  void render(sf::RenderWindow &window) const override;

  void update([[maybe_unused]] const Inputs &player_inputs, [[maybe_unused]] float dt) override;
  void new_velocity_for_ball();

  void play_audioS();
};

#endif /* !RANDOMIZER_H_ */
