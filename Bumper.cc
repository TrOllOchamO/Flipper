#include "Bumper.h"
#include <SFML/Graphics/Color.hpp>
#include <iostream>

Bumper::Bumper(std::unique_ptr<Shape> shape, const std::string& texturePath) : shape(std::move(shape)) {
    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "Error loading texture from file: " << texturePath << std::endl;
    }
    texture.setRepeated(true);

    if (!buffer.loadFromFile("../resources/ding.wav")) {
        std::cerr << "Error loading sound from file: ../resources/ding.wav" << std::endl;
    }

    props.should_be_affected_by_others = false;
    props.mass = 10000000000;
    props.velocity = Vector2D::zero();
    props.acceleration = Vector2D::zero();
    props.bounciness = 1.01;

    points_add = 1;
}

void Bumper::render(sf::RenderWindow &window, sf::Color color) const {
    this->shape->render(window, color);
}

void Bumper::render(sf::RenderWindow &window) const {
    this->shape->render(window, texture);
}