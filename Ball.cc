#include "Ball.h"
#include "Vector2D.h"
#include <SFML/Graphics/Color.hpp>
#include <stdio.h>

Ball::Ball(Vector2D pos, float radius) : shape(pos, radius) {
    props.should_react_with_other = true;
    props.velocity = Vector2D::zero();
    props.acceleration = Vector2D(0, 750);
    props.angular_velocity = 0;
    props.bounciness = 0.8;
    props.mass = 10;
}
  
void Ball::render(sf::RenderWindow &window, sf::Color color) const {
    sf::CircleShape shape(this->shape.get_radius());
    shape.setFillColor(color);
    shape.setPosition(this->shape.get_pos());
    window.draw(shape);
}

void Ball::render(sf::RenderWindow &window) const {
    sf::CircleShape shape(this->shape.get_radius());
    shape.setFillColor(sf::Color::White);
    shape.setPosition(this->shape.get_pos());
    window.draw(shape);
}
