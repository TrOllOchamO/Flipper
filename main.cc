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
    MenuState menuState = MenuState::MainMenu;
    sf::Font font;
    //resources/arial.ttf
    if (!font.loadFromFile("resources/arial.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
        return 1;
    }
  // placement des boutotns 
    sf::Text launchButton("Lancer", font, 24);
    sf::Text quitButton("Quitter", font, 24);
    launchButton.setPosition(WINDOWS_WIDTH / 2 - 50, 300);
    quitButton.setPosition(WINDOWS_WIDTH / 2 - 50, 400);

    sf::Text resumeButton("Reprendre", font, 24);
    sf::Text mainMenuButton("Menu principal", font, 24);
    resumeButton.setPosition(WINDOWS_WIDTH / 2 - 80, 300);
    mainMenuButton.setPosition(WINDOWS_WIDTH / 2 - 100, 400);

    // on crée la map
    Map map;
    Loader::load_map_1(map);

    // load map
    Game game(std::move(map));

    while (window.isOpen()) {

      float dt = clock.restart().asSeconds();;
      
      window.clear(sf::Color::Black);
      menuState = inputs.update(window,menuState);
     switch (menuState) {
        case MenuState::GameRunning:
            
            game.update(window, inputs, dt);
            break;
        case MenuState::MainMenu:
            game.reset();
            game.kill_ball();
            window.draw(launchButton);
            window.draw(quitButton);
            break;
        case MenuState::GameMenu:
            window.draw(resumeButton);
            window.draw(mainMenuButton);
            break;
        default:
          break;
      }
      window.display();
    }

    return 0;
}