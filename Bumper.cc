#include "Bumper.h"
#include <SFML/Graphics/Color.hpp>
#include <iostream>

Bumper::Bumper(std::unique_ptr<Shape> shape, const std::string& texturePath) : shape(std::move(shape)) {
    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "Error loading texture from file: " << texturePath << std::endl;
    }
    texture.setRepeated(true);

    props.should_react_with_other = false;
    props.mass = 10000000000;
    props.velocity = Vector2D::zero();
    props.acceleration = Vector2D::zero();
    props.bounciness = 1.2;
}

void Bumper::render(sf::RenderWindow &window, sf::Color color) const {
    this->shape->render(window, color);
}

void Bumper::render(sf::RenderWindow &window) const {
    this->shape->render(window, texture);
}
