#include <SFML/Graphics.hpp>
#include "Polygone.h"


#ifndef FLIPPER_H_
#define FLIPPER_H_

class Flipper {
private:
    Polygone left;
    Polygone right;

public:
    Flipper() : left(Polygone(Vector2D(0,0))), right(Polygone(Vector2D(0,0))) {};

    void upate(bool left, bool right);
    void render(sf::RenderWindow &window, sf::Color color);


};

#endif /* !FLIPPER_H_ */
