#include "Wall.h"
#include <SFML/Graphics/Color.hpp>
#include <iostream>

Wall::Wall(std::unique_ptr<Shape> shape, const std::string& texturePath) : shape(std::move(shape)) {
    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "Error loading texture from file: " << texturePath << std::endl;
    }
    sprite.setTexture(texture);

    props.should_react_with_other = false;
    props.velocity = Vector2D::zero();
    props.acceleration = Vector2D::zero();
    props.angular_velocity = 0;
    props.bounciness = 0.6;
    props.mass = 10000000000;
}

void Wall::render(sf::RenderWindow &window, sf::Color color) const {
    this->shape->render(window, color);
}

void Wall::render(sf::RenderWindow &window) const {
    std::cout << "je suis pas render =)" << std::endl;
    this->shape->render(window, sf::Color::Blue);
}

Shape * Wall::get_shape() {
    return this->shape.get();
}

PhysicsProperties& Wall::get_physics_props() {
    return this->props;
}
