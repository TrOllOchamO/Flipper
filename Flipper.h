#include <SFML/Graphics.hpp>
#include "Polygone.h"


#ifndef FLIPPER_H_
#define FLIPPER_H_

class Flipper {
private:
    Polygone left;
    Polygone right;
    float left_rotation = 0;
    float right_rotation = 0;

public:
    Flipper() : left(Polygone()), right(Polygone()) {
        left.add_point( {Vector2D(160, 735), Vector2D(180, 740), Vector2D(160, 745), Vector2D(80, 750), Vector2D(75, 745), Vector2D(75, 735), Vector2D(80, 730)} );
        left.rotate(0.3, Vector2D(85,740));

        right.add_point( {Vector2D(220, 740), Vector2D(240, 735), Vector2D(320, 730), Vector2D(325, 735), Vector2D(325, 745), Vector2D(320, 750), Vector2D(240, 745)} );
        right.rotate(-0.3, Vector2D(315,740));
    };

    void upate(bool left, bool right);
    void render(sf::RenderWindow &window, sf::Color color);
};

#endif /* !FLIPPER_H_ */
