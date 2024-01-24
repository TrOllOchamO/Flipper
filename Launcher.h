#include <SFML/Graphics.hpp>
#include "Polygone.h"


#ifndef LAUNCHER_H_
#define LAUNCHER_H_

class Launcher {
private:
    Polygone launcher;
    float force = 0;

    bool can_move_up = true;
    bool can_move_down = true;
    bool can_launch = true;

    void update_value(int value);
    void launch();

public:
    Launcher() : launcher(Polygone()) {
        launcher.add_point( {Vector2D(370, 750), Vector2D(390, 750), Vector2D(390, 790), Vector2D(370, 790)} );
    };

    void upate(bool up, bool down, bool enter);
    void render(sf::RenderWindow &window, sf::Color color);
};

#endif /* !LAUNCHER_H_ */
