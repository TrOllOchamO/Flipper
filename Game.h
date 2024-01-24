#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>

#include "Inputs.h"
#include "Map.h"

#ifndef GAME_H_
#define GAME_H_

class Game {
private:
  float score;
  
  Map map;

public:
  Game(Map map) : map(std::move(map)) {}
  void set_map(Map new_map);
  void update(sf::RenderWindow& window, const Inputs& player_inputs, float dt);
};

#endif /* !GAME_H_ */
