#include <SFML/Graphics.hpp>
#include "Polygone.h"
#include "Interfaces.h"


#ifndef FLIPPER_H_
#define FLIPPER_H_

class Flipper : public Entity {
private:
    Polygone left;
    Polygone right;
    float left_rotation = 0;
    float right_rotation = 0;

public:
    Flipper();

    void upate(bool left, bool right);
    void render(sf::RenderWindow &window, sf::Color color) const override;
    void render(sf::RenderWindow &window) const override;
};

#endif /* !FLIPPER_H_ */
