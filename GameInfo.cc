#include "GameInfo.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

GameInfo::GameInfo() {
    if (!font.loadFromFile("resources/arial.ttf")){
        std::cerr << "Error loading font from file: resources/arial.ttf" << std::endl;
    }
}


void GameInfo::render(sf::RenderWindow &window) const {
    sf::Text text;
    text.setFont(font);
    text.setString("Score : 0");
    // Ca marche pas encore ca
    // text.setString("Score : " + game->get_score());
    text.setCharacterSize(24); 
    text.setFillColor(sf::Color::White);
    window.draw(text);
}
