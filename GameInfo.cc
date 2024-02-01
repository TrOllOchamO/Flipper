#include "GameInfo.h"
#include "Game.h"
#include "Vector2D.h"
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>

GameInfo::GameInfo() {
    if (!font.loadFromFile("resources/arial.ttf")){
        std::cerr << "Error loading font from file: resources/arial.ttf" << std::endl;
    }
}


void GameInfo::render(sf::RenderWindow &window) const {
    std::ostringstream score;
    score << "Score : " << game->get_score();
    
    std::ostringstream vie;
    vie << "Vie : " << game->get_life();
    
    std::ostringstream multiplicateur;
    multiplicateur << "Multiplicateur : x" << game->get_multiplicateur();

    std::ostringstream pb;
    pb << "Meilleur score : 0";

    std::ostringstream niveau;
    niveau << "Carte : " << game->get_name();

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(16); 
    text.setFillColor(sf::Color::White);
    text.setPosition(Vector2D(10,3));
    text.setString(niveau.str() + "\n" + score.str() + "\n" + multiplicateur.str() + "\n" + pb.str() + "\n" + vie.str());
    window.draw(text);
}
