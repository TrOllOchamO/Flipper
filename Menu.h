#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

class Menu {
public:
    Menu(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    bool launchClicked(const sf::Vector2f& mousePos);
    bool quitClicked(const sf::Vector2f& mousePos);

private:
    sf::RectangleShape launchButton;
    sf::RectangleShape quitButton;
    sf::RectangleShape Homebutton;
    sf::Font font;
};

#endif // MENU_H
