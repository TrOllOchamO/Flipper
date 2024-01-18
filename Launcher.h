#include <SFML/Graphics.hpp>
#include "Polygone.h"
#include "Interfaces.h"


#ifndef LAUNCHER_H_
#define LAUNCHER_H_

class Launcher : public Entity {
private:
    Polygone launcher;
    float force = 0;

    bool can_move_up = true;
    bool can_move_down = true;
    bool can_launch = true;

    void update_value(int value);
    void launch();

public:
    Launcher();

    void upate(bool up, bool down, bool enter);
    void render(sf::RenderWindow &window, sf::Color color) const override;
    void render(sf::RenderWindow &window) const override;
};

#endif /* !LAUNCHER_H_ */
