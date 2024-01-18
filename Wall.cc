#include "Wall.h"
#include <SFML/Graphics/Color.hpp>
#include <iostream>

Wall::Wall(std::unique_ptr<Shape> shape, const std::string& texturePath) : shape(std::move(shape)) {
    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "Error loading texture from file: " << texturePath << std::endl;
    }

    props.should_react_with_other = false;
    props.velocity = Vector2D::zero();
    props.acceleration = Vector2D::zero();
    props.angular_velocity = 0;
    props.bounciness = 0.6;
    props.mass = 10000000000;
}

void Wall::render(sf::RenderWindow &window, sf::Color color) const {
    shape->render(window, color);
}

void Wall::render(sf::RenderWindow &window) const {
    shape->render(window, texture);
}
