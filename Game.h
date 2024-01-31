#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
#include <memory>

#include "Inputs.h"
#include "Interfaces.h"
#include "Map.h"

#ifndef GAME_H_
#define GAME_H_

class Game {
private:
  float score;
  int vie;
  Map map;

public:
  Game(Map map);
  void set_map(Map new_map);
  void make_entity(std::unique_ptr<Entity> new_element);
  void update(sf::RenderWindow& window, const Inputs& player_inputs, float dt);

  void update_score(float add);
  float get_score();
};

#endif /* !GAME_H_ */
