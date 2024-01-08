#include "Ball.h"
#include "Collision.h"
#include "Polygone.h"
#include "Rectangle.h"
#include "Vector2D.h"
#include "Wall.h"
#include "Input.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 800), "Flipper");
    sf::Clock clock;

    Ball ball(Vector2D(100, 500), 8);

    Polygone p(Vector2D(10, 10));
    p.add_point(Vector2D(0, 0));
    p.add_point(Vector2D(250, 500));
    p.add_point(Vector2D(270, 650));
    p.add_point(Vector2D(100, 400));

    Wall wall(p.get_pos(), "resources/Test.jpg");

    Input input;

    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();
        window.clear(sf::Color::Black);
        input.update(window);

        ball.move(dt);

        sf::Color c = sf::Color::Green;
        if (Collision::are_colliding(ball.get_shape(), &p)) {
            c = sf::Color::Red;
        }
        wall.draw(window);
        p.render(window, c);
        ball.render(window, c);

        if(input.left_flipper) { std::cout << "left "; }
        if(input.right_flipper) { std::cout << "right "; }
        std::cout << "\n------------------\n";

        window.display();
    }
    return 0;
}
