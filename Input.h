#include <SFML/Graphics.hpp>

#ifndef INPUT_H_
#define INPUT_H_

class Input {
private:
    void key_up(sf::Keyboard::Key key);
    void key_down(sf::Keyboard::Key key);

public:
    bool left_flipper = false;
    bool right_flipper = false;

    void update(sf::RenderWindow &m_window);
};

#endif /* !INPUT_H_ */
