#include "Inputs.h"
#define WINDOWS_WIDTH 400
#define WINDOWS_HEIGHT 800
#define LEFT_FLIPPER sf::Keyboard::Q
#define RIGHT_FLIPPER sf::Keyboard::D
#define DOWN_LAUNCHER sf::Keyboard::Up
#define UP_LAUNCHER sf::Keyboard::Down
#define ENTER_LAUNCHER sf::Keyboard::Enter
#define SPACE_LAUNCHER sf::Keyboard::Space
#define ESCAPE sf::Keyboard::Escape


void Inputs::update(sf::RenderWindow &window) { 
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed){
            window.close();
        }
        mousePosition= sf::Mouse::getPosition(window);
        switch (event.type) {
            case sf::Event::KeyPressed:
                key_down(event.key.code);
                break;

            case sf::Event::MouseButtonPressed:
                mousePositionClicked = sf::Mouse::getPosition(window);
                break;

            case sf::Event::KeyReleased:
                key_up(event.key.code);
                break;

            default:
                mousePositionClicked= sf::Vector2i(0,0) ;
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

        case SPACE_LAUNCHER:
            space_launcher = true;
            break;
         case ESCAPE:
            escape = true;
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
        case ESCAPE:
            escape = false;
            break;

        default:
            break;
    }
}
