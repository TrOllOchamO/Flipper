#include "Flipper.h"
#include "Polygone.h"
#include "Vector2D.h"

#define ROTATE 0.01
#define ROTATE_LIMITE 0.5

void Flipper::upate(bool left_value, bool right_value){
    if (right_value && right_rotation<ROTATE_LIMITE){
        right.rotate(ROTATE, Vector2D(315,740));
        right_rotation += ROTATE;
    } 
    if (!right_value && right_rotation>0.0){
        right.rotate(-ROTATE, Vector2D(315,740));
        right_rotation -= ROTATE;
    }

    if (left_value && left_rotation<ROTATE_LIMITE){
        left.rotate(-ROTATE, Vector2D(85,740));
        left_rotation += ROTATE;
    } 
    if (!left_value && left_rotation>0.0){
        left.rotate(ROTATE, Vector2D(85,740));
        left_rotation -= ROTATE;
    } 
}

void Flipper::render(sf::RenderWindow &window, sf::Color color){
    left.render(window,color);
    right.render(window,color);
}
