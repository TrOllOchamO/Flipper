#include "Wall.h"
#include <iostream>

Wall::Wall(Vector2D pos, const std::string& texturePath)
    : Shape(pos) {
    // Load the texture
    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "Error loading texture from file: " << texturePath << std::endl;
        // Handle error loading texture
    }

    // Set the texture to the sprite
    sprite.setTexture(texture);
    // Set the position of the sprite to the position of the wall
    sprite.setPosition(pos.x, pos.y);
}

Vector2D Wall::get_center() const {
    // Assuming the center is at the center of the texture
    return get_pos() + Vector2D(texture.getSize().x / 2, texture.getSize().y / 2);
}

Vector2D Wall::get_futhest_point(const Vector2D &direction) const {
    // Assuming the farthest point is at the corner of the texture
    return get_pos() + Vector2D(texture.getSize().x, texture.getSize().y);
}

void Wall::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}
