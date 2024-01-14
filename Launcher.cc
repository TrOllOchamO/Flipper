#include "Launcher.h"
#include "Polygone.h"
#include "Vector2D.h"

void Launcher::upate(bool up, bool down, bool enter){
    if(up && can_move_up){
        can_move_up = false;
        update_value(1);
    }
    if(down && can_move_down){
        can_move_down = false;
        update_value(-1);
    }
    if(enter && can_launch){
        can_launch = false;
        launch();
    }
    if(!up){
        can_move_up = true;
    }
    if(!down){
        can_move_down = true;
    }
    if(!enter){
        can_launch = true;
    }
}

void Launcher::update_value(int value){
    if (force+value*3>30 || force+value*3<0) return;

    force += value*3;
    launcher.clear();
    launcher.add_point( {Vector2D(370, 750+force), Vector2D(390, 750+force), Vector2D(390, 790), Vector2D(370, 790)} );
}

void Launcher::launch(){
    force = 0;
    launcher.clear();
    launcher.add_point( {Vector2D(370, 750), Vector2D(390, 750), Vector2D(390, 790), Vector2D(370, 790)} );
}

void Launcher::render(sf::RenderWindow &window, sf::Color color){
    launcher.render(window,color);
}