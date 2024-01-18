#include "Flipper.h"
#include "Polygone.h"
#include "Vector2D.h"
#include <SFML/Graphics/Color.hpp>

#define ROTATE 0.01
#define ROTATE_LIMITE 0.5

Flipper::Flipper(const std::string& texturePath) : left(Polygone()), right(Polygone()) {
    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "Error loading texture from file: " << texturePath << std::endl;
    }
    texture.setRepeated(true);

    left.add_points( {Vector2D(160, 735), Vector2D(180, 740), Vector2D(160, 745), Vector2D(80, 750), Vector2D(75, 745), Vector2D(75, 735), Vector2D(80, 730)} );
    left.rotate(0.3, Vector2D(85,740));

    right.add_points( {Vector2D(220, 740), Vector2D(240, 735), Vector2D(320, 730), Vector2D(325, 735), Vector2D(325, 745), Vector2D(320, 750), Vector2D(240, 745)} );
    right.rotate(-0.3, Vector2D(315,740));
};

void Flipper::upate(bool left_value, bool right_value){
    if (right_value && right_rotation<ROTATE_LIMITE){
        right.rotate(ROTATE, Vector2D(315,740));
        right_rotation += ROTATE;
    } 
    if (!right_value && right_rotation>0.0){
        right.rotate(-ROTATE, Vector2D(315,740));
        right_rotation -= ROTATE;
    }

    if (left_value && left_rotation<ROTATE_LIMITE){
        left.rotate(-ROTATE, Vector2D(85,740));
        left_rotation += ROTATE;
    } 
    if (!left_value && left_rotation>0.0){
        left.rotate(ROTATE, Vector2D(85,740));
        left_rotation -= ROTATE;
    } 
}

void Flipper::render(sf::RenderWindow &window, sf::Color color) const {
    left.render(window, color);
    right.render(window, color);
}

void Flipper::render(sf::RenderWindow &window) const {
    left.render(window, texture);
    right.render(window, texture);
}
