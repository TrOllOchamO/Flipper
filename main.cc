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
    sf::Font font;
    //resources/arial.ttf
    if (!font.loadFromFile("resources/arial.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
        return 1;
    }
  // placement des boutotns 
    sf::Text launchButton("Lancer", font, 24);
    sf::Text MapSelectionButton("Selection de cartes", font, 24);
    sf::Text quitButton("Quitter", font, 24);
    launchButton.setPosition(WINDOWS_WIDTH / 2 - 50, 300);
    MapSelectionButton.setPosition(WINDOWS_WIDTH / 2 - 50, 400);
    quitButton.setPosition(WINDOWS_WIDTH / 2 - 50, 500);

    sf::Text resumeButton("Reprendre", font, 24);
    sf::Text mainMenuButton("Menu principal", font, 24);
    resumeButton.setPosition(WINDOWS_WIDTH / 2 - 80, 300);
    mainMenuButton.setPosition(WINDOWS_WIDTH / 2 - 100, 400);


    sf::Text map1Button("Map 1", font, 24);
    sf::Text map2Button("Map 2", font, 24);
    sf::Text map3Button("Map 3", font, 24);
    map1Button.setPosition(WINDOWS_WIDTH / 2 - 50, 300);
    map2Button.setPosition(WINDOWS_WIDTH / 2 - 50, 400);
    map3Button.setPosition(WINDOWS_WIDTH / 2 - 50, 500);
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
            window.draw(MapSelectionButton);
            window.draw(quitButton);
            break;
        case MenuState::GameMenu:
            window.draw(resumeButton);
            window.draw(mainMenuButton);
            break;

        case MenuState::MapSelection:
            window.clear(sf::Color::Blue);
            window.draw(map1Button);
            window.draw(map2Button);
            window.draw(map3Button);
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::MouseButtonPressed) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (map1Button.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        Loader::load_map_1(map);
                        game.set_map(std::move(map));
                        menuState = MenuState::MainMenu;
                    } else if (map2Button.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        Loader::load_map_2(map);
                        game.set_map(std::move(map));
                        menuState = MenuState::MainMenu;
                    } else if (map3Button.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        Loader::load_map_3(map);
                        game.set_map(std::move(map));

                        menuState = MenuState::MainMenu;
                    }
                }
            }
            break;
        default:
          break;
      }
      window.display();
    }

    return 0;
}