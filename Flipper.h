#include <SFML/Graphics.hpp>
#include "Polygone.h"


#ifndef FLIPPER_H_
#define FLIPPER_H_

class Flipper {
private:
    Polygone left;
    Polygone right;
    bool left_up = false;
    bool right_up = false;

public:
    Flipper() : left(Polygone(Vector2D(90,725))), right(Polygone(Vector2D(310,725))) {
        left.add_point(Vector2D(80, 740));
        left.add_point(Vector2D(80, 710));
        left.add_point(Vector2D(180, 740));
        left.add_point(Vector2D(180, 745));
        left.rotate(0.1);
        right.add_point(Vector2D(320, 740));
        right.add_point(Vector2D(320, 710));
        right.add_point(Vector2D(220, 740));
        right.add_point(Vector2D(220, 745));
        right.rotate(-0.1);
    };

    void upate(bool left, bool right);
    void render(sf::RenderWindow &window, sf::Color color);


};

#endif /* !FLIPPER_H_ */
