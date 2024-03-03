#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <iostream>
#include <memory>
#include <vector>
#include <ctime>

#include "Inputs.h"
#include "Game.h"
#include "Map.h"
#include "Loader.h"

#define WINDOWS_WIDTH 400
#define WINDOWS_HEIGHT 800


int main() {
    srand(time(0));
    
    sf::RenderWindow window(sf::VideoMode(WINDOWS_WIDTH, WINDOWS_HEIGHT), "Flipper");
    sf::Clock clock;
    Inputs inputs;
    MenuState menuState = MenuState::MainMenu;
    
    // on crée la map
    Map map;
    Loader::load_map_1(map);
    MapSelection MapSelected = MapSelection::Map1;
    // load map
    Game game(std::move(map));

    while (window.isOpen()) {

      float dt = clock.restart().asSeconds();;
      
      window.clear(sf::Color::Black);
      
     switch (menuState) {
        case MenuState::GameRunning:
            menuState = inputs.update(window,menuState);
            game.update(window, inputs, dt);
            break;
        case MenuState::MainMenu:
            menuState = inputs.update(window,menuState);
            game.reset();
            game.kill_ball(); 
            break;
        case MenuState::GameMenu:
            menuState = inputs.update(window,menuState);
            break;

        case MenuState::MapSelection:
            window.clear(sf::Color::Blue);

            MapSelected = inputs.MapSelector(window);
                switch (MapSelected) {
                    case MapSelection::Map1:
                        Loader::load_map_1(map);
                        game.set_map(std::move(map));
                        menuState = MenuState::GameRunning;
                        break;
                    case MapSelection::Map2:
                        Loader::load_map_2(map);
                        game.set_map(std::move(map));
                        menuState = MenuState::GameRunning;
                        break;
                    case MapSelection::Map3:
                        Loader::load_map_3(map);
                        game.set_map(std::move(map));
                        menuState = MenuState::GameRunning;
                        break;
                    default:
                        break;
                }
            break;

        default:
          break;
      }
      window.display();
    }

    return 0;
}