#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ball.h"
#include "Vector2D.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 800), "SFML works!");

    sf::Clock clock;
    Ball ball(Vector2D(100, 500), 8);
 
    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();

        sf::Event event;
        window.clear(sf::Color::Black);
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        ball.move(dt);
        ball.render(window);
        window.display();
    }

    return 0;
}
