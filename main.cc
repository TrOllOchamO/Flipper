#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ball.h"
#include "Vector2D.h"
#include "Polygone.h"
#include "Rectangle.h"
#include "Collision.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 800), "Flipper");

    sf::Clock clock;
    Ball ball(Vector2D(100, 500), 8);
    
    Polygone p(Vector2D(10,10));

    p.add_point(Vector2D(0,0));
    p.add_point(Vector2D(250,500));
    p.add_point(Vector2D(250,600));
    p.add_point(Vector2D(100,400));

    sf::Color c = sf::Color::Green; 

    Rectangle r(Vector2D(50,300),200,50);

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
        c = sf::Color::Green;
        if(Collision::is_colliding(ball.get_shape(),&r)){
            std::cout << "oui\n";
            c=sf::Color::Red;
        }
        r.render(window, c);
        ball.render(window, c);
        // p.render(window, c);
        window.display();
    }

    return 0;
}
