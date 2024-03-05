#include <SFML/Graphics.hpp>
#ifndef INPUTS_H_
#define INPUTS_H_
#include "MenuState.h"
#include "MapSelection.h"
#include <iostream>

class Inputs {
private:
    void key_up(sf::Keyboard::Key key);
    void key_down(sf::Keyboard::Key key);

public:
    bool left_flipper = false;
    bool right_flipper = false;

    bool up_launcher = false;
    bool down_launcher = false;
    bool enter_launcher = false;
    bool space_launcher = false;

    MenuState update(sf::RenderWindow &m_window, MenuState &currentState);
    MapSelection MapSelector(sf::RenderWindow &m_window);
};

#endif /* !INPUTS_H_ */
