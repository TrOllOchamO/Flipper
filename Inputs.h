#include <SFML/Graphics.hpp>
#ifndef INPUTS_H_
#define INPUTS_H_
#include "MenuState.h"

#include <iostream>

class Inputs {
private:
    void key_up(sf::Keyboard::Key key);
    void key_down(sf::Keyboard::Key key);

public:
    bool left_flipper = false;
    bool right_flipper = false;
    sf::Vector2i mousePosition;
    sf::Vector2i mousePositionClicked;
    bool up_launcher = false;
    bool down_launcher = false;
    bool enter_launcher = false;
    bool space_launcher = false;
    bool escape = false;

    void update(sf::RenderWindow &m_window);
};

#endif /* !INPUTS_H_ */
