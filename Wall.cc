#include "Wall.h"
#include <SFML/Graphics/Color.hpp>
#include <iostream>

Wall::Wall(std::unique_ptr<Shape> shape, const std::string& texturePath) : shape(std::move(shape)) {
    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "Error loading texture from file: " << texturePath << std::endl;
    }

  if (!buffer.loadFromFile("../resources/bonk.wav")) {
    std::cerr << "Error loading sound from file: ../resources/bonk.wav" << std::endl;
  }

    props.should_be_affected_by_others = false;
    props.mass = 10000000000;
    props.velocity = Vector2D::zero();
    props.acceleration = Vector2D::zero();
    props.bounciness = 0.7;
}

void Wall::render(sf::RenderWindow &window, sf::Color color) const {
    shape->render(window, color);
}

void Wall::render(sf::RenderWindow &window) const {
    shape->render(window, texture);
}
