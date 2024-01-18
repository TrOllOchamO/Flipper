#include "Ball.h"
#include "Vector2D.h"
#include <SFML/Graphics/Color.hpp>
#include <stdio.h>

Ball::Ball(Vector2D pos, float radius, const std::string& texturePath) : shape(std::make_unique<Circle>(pos, radius)) {
    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "Error loading texture from file: " << texturePath << std::endl;
    }
    texture.setRepeated(true);

    props.should_react_with_other = true;
    props.velocity = Vector2D::zero();
    props.acceleration = Vector2D(0, 750);
    props.bounciness = 0.9;
}
  
void Ball::render(sf::RenderWindow &window, sf::Color color) const {
    shape->render(window, color);
}

void Ball::render(sf::RenderWindow &window) const {
    shape->render(window, texture);
}
