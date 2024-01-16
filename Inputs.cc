#include "Inputs.h"

#define LEFT_FLIPPER sf::Keyboard::Q
#define RIGHT_FLIPPER sf::Keyboard::D

#define DOWN_LAUNCHER sf::Keyboard::Up
#define UP_LAUNCHER sf::Keyboard::Down
#define ENTER_LAUNCHER sf::Keyboard::Enter

void Inputs::update(sf::RenderWindow &window) {
    sf::Event event;
    while (window.pollEvent(event)) {

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
    }
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

        default:
            break;
    }
}
