#include "Ball.h"
#include "Collision.h"
#include "Polygone.h"
#include "Rectangle.h"
#include "Vector2D.h"
#include "Wall.h"
#include "Input.h"
#include "Flipper.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 800), "Flipper");
    sf::Clock clock;

    Ball ball(Vector2D(100, 500), 8);

    Polygone p(Vector2D(90, 500), Vector2D(100, 525));
    p.add_point(Vector2D(10, 10));
    p.add_point(Vector2D(25, 50));
    p.add_point(Vector2D(27, 65));
    p.add_point(Vector2D(10, 40));

    // Wall wall(p.get_pos(), "resources/Test.jpg");

    Input input;
    Flipper flipper;

    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();
        window.clear(sf::Color::Black);
        input.update(window);

        flipper.upate(input.left_flipper, input.right_flipper);
        flipper.render(window, sf::Color::Red);

        // ball.move(dt);
        p.rotate(1,dt);

        sf::Color c = sf::Color::Green;
        if (Collision::are_colliding(ball.get_shape(), &p)) {
            c = sf::Color::Red;
        }


        // wall.draw(window);
        p.render(window, c);
        ball.render(window, c);

        window.display();
    }
    return 0;
}
