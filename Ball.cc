#include "Ball.h"
#include "Vector2D.h"
#include <SFML/Graphics/Color.hpp>
#include <iostream>
#include <ostream>
#include <stdio.h>

Ball::Ball(Vector2D pos, float radius, const std::string& texturePath) : shape(std::make_unique<Circle>(pos, radius)) {
    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "Error loading texture from file: " << texturePath << std::endl;
    }
    texture.setRepeated(true);

    props.mass = 1;
    props.velocity = Vector2D::zero();
    props.acceleration = Vector2D(0, 500);
    props.bounciness = 1;
}
  
void Ball::render(sf::RenderWindow &window, sf::Color color) const {
    shape->render(window, color);
}

void Ball::render(sf::RenderWindow &window) const {
    shape->render(window, texture);
}

 void Ball::set_posiion(Vector2D new_pos){
    shape->set_pos(new_pos);
}

void Ball::set_radius(float new_radius) {
    shape.get()->set_radius(new_radius);
}

float Ball::get_radius() const {
    return shape.get()->get_radius();
}

Vector2D Ball::get_position() const{
    return shape->get_pos();
}
