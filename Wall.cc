#include "Wall.h"
#include <iostream>

Wall::Wall(Vector2D pos, const std::string& texturePath)
    : Shape(pos) {
    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "Error loading texture from file: " << texturePath << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(pos.x, pos.y);
}

Vector2D Wall::get_center() const {
    return get_pos();
}

Vector2D Wall::get_futhest_point(const Vector2D &direction) const {
    return get_pos();
}

void Wall::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}
