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
    check_if_outside();
    pos += velocity * dt;
}

void Ball::apply_gravity(float dt){
    velocity -= gravity * dt;
}

void Ball::bounceX(){
    velocity.y = -velocity.y;
    velocity *= 0.66;
}

void Ball::bounceY(){
    velocity.x = -velocity.x;
    velocity *= 0.66;
}

void Ball::check_if_outside(){
    if(pos.x<0){
        pos.x=0;
        bounceY();
    }

    if(pos.y<0){
        pos.y=0;
        bounceX();
    }
    
    if(pos.x+2*radius>400){
        pos.x=400-2*radius;
        bounceY();
    }
    
    if(pos.y+2*radius>800){
        pos.y=800-2*radius;
        bounceX();
    }
}