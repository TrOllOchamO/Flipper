#include "Flipper.h"
#include "Polygone.h"
#include "Vector2D.h"

void Flipper::upate(bool left_value, bool right_value){
    left.clear();
    if (left_value){
        left.add_point(Vector2D(40, 720));
        left.add_point(Vector2D(40, 740));
        left.add_point(Vector2D(160, 740));
        left.add_point(Vector2D(160, 720));
    }else{
        left.add_point(Vector2D(40, 720));
        left.add_point(Vector2D(40, 740));
        left.add_point(Vector2D(160, 780));
        left.add_point(Vector2D(160, 760));
    }
    right.clear();
    if (right_value){
        right.add_point(Vector2D(240, 720));
        right.add_point(Vector2D(240, 740));
        right.add_point(Vector2D(360, 740));
        right.add_point(Vector2D(360, 720));
    }else{
        right.add_point(Vector2D(240, 760));
        right.add_point(Vector2D(240, 780));
        right.add_point(Vector2D(360, 740));
        right.add_point(Vector2D(360, 720));
    }
}

void Flipper::render(sf::RenderWindow &window, sf::Color color){
    left.render(window,color);
    right.render(window,color);
}