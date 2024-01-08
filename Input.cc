#include "Input.h"

#define LEFT_FLIPPER sf::Keyboard::Q
#define RIGHT_FLIPPER sf::Keyboard::D

void Input::update(sf::RenderWindow &window) {
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

void Input::key_down(sf::Keyboard::Key key){
    switch (key) {
        case LEFT_FLIPPER:
            left_flipper = true;
            break;
        case RIGHT_FLIPPER:
            right_flipper = true;
            break;
        default:
            break;
    }
}

void Input::key_up(sf::Keyboard::Key key){
    switch (key) {
        case LEFT_FLIPPER:
            left_flipper = false;
            break;
        case RIGHT_FLIPPER:
            right_flipper = false;
            break;
        default:
            break;
    }
}
