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

enum class MenuState {
    MainMenu,
    GameRunning,
    GameMenu,
    MapSelection
};

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOWS_WIDTH, WINDOWS_HEIGHT), "Flipper");
    sf::Clock clock;
    Inputs inputs;
    MenuState menuState = MenuState::MainMenu;

    // Création des boutons
    sf::Font font;
    //resources/arial.ttf
    if (!font.loadFromFile("resources/arial.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
        return 1;
    }

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
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                if (menuState == MenuState::GameRunning) {
                    menuState = MenuState::GameMenu;
                } else if (menuState == MenuState::GameMenu) {
                    menuState = MenuState::GameRunning;
                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (menuState == MenuState::MainMenu) {
                    if (launchButton.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                        menuState = MenuState::GameRunning;
                    } else if (quitButton.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                        window.close();
                    }
                } else if (menuState == MenuState::GameMenu) {
                    if (resumeButton.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                        menuState = MenuState::GameRunning;
                    } else if (mainMenuButton.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                        menuState = MenuState::MainMenu;
                    }
                }
            }
        }

        float dt = clock.restart().asSeconds();
        inputs.update(window);
        window.clear(sf::Color::Black);

        if (menuState == MenuState::MainMenu) {
            window.draw(launchButton);
            window.draw(quitButton);
        } else if (menuState == MenuState::GameRunning) {
            game.update(window, inputs, dt);
        } else if (menuState == MenuState::GameMenu) {
            window.draw(resumeButton);
            window.draw(mainMenuButton);
        }

        window.display();
    }

    return 0;
}