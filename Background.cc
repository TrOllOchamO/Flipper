#include "Background.h"
#include <SFML/Graphics/Color.hpp>
#include <iostream>

Background::Background(std::unique_ptr<Shape> shape, const std::string& texturePath) : shape(std::move(shape)) {
    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "Error loading texture from file: " << texturePath << std::endl;
    }

  if (!buffer.loadFromFile("../resources/bonk.wav")) {
    std::cerr << "Error loading sound from file: ../resources/bonk.wav" << std::endl;
  }

    props.should_be_affected_by_others = false;
    props.should_affect_others = false;
}

void Background::render(sf::RenderWindow &window, sf::Color color) const {
    shape->render(window, color);
}

void Background::render(sf::RenderWindow &window) const {
    shape->render(window, texture);
}
