#include "FlipperRight.h"
#include "Polygone.h"
#include "Vector2D.h"
#include <SFML/Graphics/Color.hpp>

#define ROTATE 0.01
#define ROTATE_LIMITE 0.5

FlipperRight::FlipperRight(const std::string& texturePath) : shape(Polygone()) {
    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "Error loading texture from file: " << texturePath << std::endl;
    }
    texture.setRepeated(true);

    props.should_react_with_other = false;
    props.mass = 10000000000;
    props.velocity = Vector2D::zero();
    props.acceleration = Vector2D::zero();
    props.bounciness = 1.3;

    shape.add_points( {Vector2D(220, 740), Vector2D(240, 735), Vector2D(320, 730), Vector2D(325, 735), Vector2D(325, 745), Vector2D(320, 750), Vector2D(240, 745)} );
    shape.rotate(-0.3, Vector2D(315,740));
};

void FlipperRight::use_inputs([[maybe_unused]] const Inputs& player_inputs) {
    if (player_inputs.right_flipper && rotation < ROTATE_LIMITE){
        shape.rotate(ROTATE, Vector2D(315,740));
        rotation += ROTATE;
    } 
    if (!player_inputs.right_flipper && rotation > 0.0){
        shape.rotate(-ROTATE, Vector2D(315,740));
        rotation -= ROTATE;
    }
}

void FlipperRight::render(sf::RenderWindow &window, sf::Color color) const {
    shape.render(window, color);
}

void FlipperRight::render(sf::RenderWindow &window) const {
    shape.render(window, texture);
}
