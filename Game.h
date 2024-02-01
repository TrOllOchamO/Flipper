#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
#include <memory>

#include "Inputs.h"
#include "Interfaces.h"
#include "Map.h"
#include "Ball.h"

#ifndef GAME_H_
#define GAME_H_

class Game {
private:
  Ball* ball_handle = nullptr;
  float score;
  Map map;

public:
  Game(Map map);
  void set_map(Map new_map);
  void make_ball(std::unique_ptr<Ball> new_ball);
  void kill_ball();
  Ball* get_ball_handle() { return ball_handle; }
  void make_entity(std::unique_ptr<Entity> new_element);
  void update(sf::RenderWindow& window, const Inputs& player_inputs, float dt);
};

#endif /* !GAME_H_ */
