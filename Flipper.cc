#include "Flipper.h"
#include "Polygone.h"
#include "Vector2D.h"

#define ROTATE 0.5

void Flipper::upate(bool left_value, bool right_value){
    if (left_value && !left_up){
        left.rotate(-ROTATE, Vector2D(85,740));
        left_up=true;
    } 
    if (!left_value && left_up){
        left.rotate(ROTATE, Vector2D(85,740));
        left_up=false;
    } 

    if (right_value && !right_up){
        right.rotate(ROTATE, Vector2D(315,740));
        right_up=true;
    } 
    if (!right_value && right_up){
        right.rotate(-ROTATE, Vector2D(315,740));
        right_up=false;
    } 
}

void Flipper::render(sf::RenderWindow &window, sf::Color color){
    left.render(window,color);
    right.render(window,color);
}