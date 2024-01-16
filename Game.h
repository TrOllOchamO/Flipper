#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

#include "Renderable.h"
#include "Physics.h"
#include "Inputs.h"
#include "Map.h"

#ifndef GAME_H_
#define GAME_H_

class Game {
private:
  float score;
  Map map;

public:
  void set_map(Map new_map);
  void update(sf::RenderWindow& window, const Inputs& player_inputs, float dt);
};

#endif /* !GAME_H_ */
