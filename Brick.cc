#include "Brick.h"
#include "Vector2D.h"
#include <SFML/Graphics/Color.hpp>
#include <iostream>
#include <ostream>
#include <stdio.h>

#define BRICK_WIDTH 20
#define BRICK_HEIGHT 10

Brick::Brick(Vector2D pos, const std::string& texturePath) : shape(std::make_unique<Rectangle>(pos, BRICK_WIDTH, BRICK_HEIGHT)) {
    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "Error loading texture from file: " << texturePath << std::endl;
    }
    texture.setRepeated(true);

    props.should_be_affected_by_others = false;
    props.mass = 10000000000;
    props.velocity = Vector2D::zero();
    props.acceleration = Vector2D::zero();
    props.bounciness = 0.7;
}
  
void Brick::render(sf::RenderWindow &window, sf::Color color) const {
    shape->render(window, color);
}

void Brick::render(sf::RenderWindow &window) const {
    shape->render(window, sf::Color::Red);
}
