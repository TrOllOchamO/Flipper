#include "Menu.h"
#include <iostream>


   
Menu::Menu(sf::RenderWindow& window) { 
    if (!font.loadFromFile("resources/arial.ttf")) {
        std::cerr << "Error loading font file" << std::endl;
    }
    launchButton.setSize(sf::Vector2f(100, 50));
    launchButton.setPosition(150, 200);
    launchButton.setFillColor(sf::Color::Green);

    quitButton.setSize(sf::Vector2f(100, 50));
    quitButton.setPosition(150, 300);
    quitButton.setFillColor(sf::Color::Red);
}

void Menu::draw(sf::RenderWindow& window) {
    window.draw(launchButton);
    window.draw(quitButton);
}

bool Menu::launchClicked(const sf::Vector2f& mousePos) {
    return launchButton.getGlobalBounds().contains(mousePos);
}

bool Menu::quitClicked(const sf::Vector2f& mousePos) {
    return quitButton.getGlobalBounds().contains(mousePos);
}