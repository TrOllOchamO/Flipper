#include "Inputs.h"
#define WINDOWS_WIDTH 400
#define WINDOWS_HEIGHT 800
#define LEFT_FLIPPER sf::Keyboard::Q
#define RIGHT_FLIPPER sf::Keyboard::D

#define DOWN_LAUNCHER sf::Keyboard::Up
#define UP_LAUNCHER sf::Keyboard::Down
#define ENTER_LAUNCHER sf::Keyboard::Enter
#define SPACE_LAUNCHER sf::Keyboard::Space


MenuState Inputs::update(sf::RenderWindow &window, MenuState &currentState) {
    //a changer pour avoir les info des bouttons sans avoir a faire un truc degeu comme çàa 
    sf::Font font;
    font.loadFromFile("resources/arial.ttf");
    sf::Text launchButton("Lancer", font, 24);
    sf::Text quitButton("Quitter", font, 24);
    launchButton.setPosition(WINDOWS_WIDTH / 2 - 50, 300);
    quitButton.setPosition(WINDOWS_WIDTH / 2 - 50, 400);
    sf::Text resumeButton("Reprendre", font, 24);
    sf::Text mainMenuButton("Menu principal", font, 24);
    resumeButton.setPosition(WINDOWS_WIDTH / 2 - 80, 300);
    mainMenuButton.setPosition(WINDOWS_WIDTH / 2 - 100, 400);
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed){
            window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (currentState == MenuState::MainMenu) {
                if (launchButton.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                    currentState = MenuState::GameRunning;
                } else if (quitButton.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                    window.close();
                }
            } else if (currentState == MenuState::GameMenu) {
                if (resumeButton.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                    currentState = MenuState::GameRunning;
                } else if (mainMenuButton.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                    currentState = MenuState::MainMenu;
                }
            }
        }

        if (event.type == sf::Event::Closed) {
            window.close();
        }

        switch (event.type) {
            case sf::Event::KeyPressed:
                key_down(event.key.code);
                break;

            case sf::Event::KeyReleased:
                key_up(event.key.code);
                break;

            default:
                break;
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            if (currentState == MenuState::GameRunning) {
                return MenuState::GameMenu;
            }
        }
    }
    return currentState;
}

void Inputs::key_down(sf::Keyboard::Key key){
    switch (key) {
        case LEFT_FLIPPER:
            left_flipper = true;
            break;

        case RIGHT_FLIPPER:
            right_flipper = true;
            break;

        case DOWN_LAUNCHER:
            down_launcher = true;
            break;

        case UP_LAUNCHER:
            up_launcher = true;
            break;

        case ENTER_LAUNCHER:
            enter_launcher = true;
            break;

        case SPACE_LAUNCHER:
            space_launcher = true;
            break;

        default:
            break;
    }
}

void Inputs::key_up(sf::Keyboard::Key key){
    switch (key) {
        case LEFT_FLIPPER:
            left_flipper = false;
            break;

        case RIGHT_FLIPPER:
            right_flipper = false;
            break;

        case DOWN_LAUNCHER:
            down_launcher = false;
            break;

        case UP_LAUNCHER:
            up_launcher  = false;
            break;

        case ENTER_LAUNCHER:
            enter_launcher = false;
            break;

        case SPACE_LAUNCHER:
            space_launcher = false;
            break;

        default:
            break;
    }
}
