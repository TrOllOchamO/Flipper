#include "Bumper.h"
#include <SFML/Graphics/Color.hpp>
#include <iostream>

Bumper::Bumper(std::unique_ptr<Shape> shape, const std::string& texturePath) : shape(std::move(shape)) {
    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "Error loading texture from file: " << texturePath << std::endl;
    }
    sprite.setTexture(texture);

    props.should_react_with_other = false;
    props.velocity = Vector2D::zero();
    props.acceleration = Vector2D::zero();
    props.angular_velocity = 0;
    props.bounciness = 1.1;
    props.mass = 10000000000;
}

void Bumper::render(sf::RenderWindow &window, sf::Color color) const {
    this->shape->render(window, color);
}

void Bumper::render(sf::RenderWindow &window) const {
    this->shape->render(window, sf::Color::Red);
}

Shape * Bumper::get_shape() {
    return this->shape.get();
}

PhysicsProperties& Bumper::get_physics_props() {
    return this->props;
}
