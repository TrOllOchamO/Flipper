#ifndef GAME_INFO_H_
#define GAME_INFO_H_

#include "Game.h"
#include <SFML/Graphics.hpp>

class GameInfo: public Entity {
    private:
        sf::Font font;

    public:
        GameInfo();
        void render(sf::RenderWindow &window) const override;
        bool is_resolvable() override { return false; } 
};

#endif /* !GAME_INFO_H_ */