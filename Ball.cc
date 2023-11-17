#include "Ball.h"
#include "Vector2D.h"
#include <stdio.h>

void Ball::render(sf::RenderWindow &window){
    sf::CircleShape shape(radius);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(pos.to_sfml());
    window.draw(shape);
}

Vector2D Ball::get_center_position(){
    return Vector2D(pos.x+radius, pos.y+radius);
}

void Ball::move(float dt){
    apply_gravity(dt);
    pos += velocity * dt;
}

void Ball::apply_gravity(float dt){
    velocity -= gravity * dt;
}