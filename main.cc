#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <iostream>
#include <memory>
#include <vector>

#include "Inputs.h"
#include "Game.h"
#include "Map.h"
#include "Loader.h"

#define WINDOWS_WIDTH 400
#define WINDOWS_HEIGHT 800

int main() {
  sf::RenderWindow window(sf::VideoMode(WINDOWS_WIDTH, WINDOWS_HEIGHT), "Flipper");
  sf::Clock clock;
  Inputs inputs;

  // on créer la map
  Map map;
  Loader::load_map_1(map);
  
  // load map
  Game game(std::move(map));
    
  while (window.isOpen()) {
    float dt = clock.restart().asSeconds();
    inputs.update(window);
    window.clear(sf::Color::Black);

    game.update(window, inputs, dt);

    window.display();
  }
}
