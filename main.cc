#include "Ball.h"
#include "Collision.h"
#include "Polygone.h"
#include "Rectangle.h"
#include "Vector2D.h"
#include "Wall.h"
#include "Input.h"
#include "Flipper.h"
#include "Launcher.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 800), "Flipper");
    sf::Clock clock;

    Ball ball(Vector2D(100, 500), 8);

    Polygone p;
    p.add_point(Vector2D(100, 510));
    p.add_point(Vector2D(115, 550));
    p.add_point(Vector2D(117, 565));
    p.add_point(Vector2D(100, 540));

    // Wall wall(p.get_pos(), "resources/Test.jpg");

    Input input;
    Flipper flipper;
    Launcher launcher;

    while (window.isOpen()) {
        //update the game
        float dt = clock.restart().asSeconds();
        window.clear(sf::Color::Black);
        input.update(window);

        //update controllable things
        flipper.upate(input.left_flipper, input.right_flipper);
        launcher.upate(input.up_launcher, input.down_launcher, input.enter_launcher);

        //move things
        p.rotate(1, Vector2D(100, 525), dt);
        // ball.move(dt);

        //change color if collide
        sf::Color c = sf::Color::Green;
        if (Collision::are_colliding(ball.get_shape(), &p)) {
            c = sf::Color::Red;
        }

        //render things
        flipper.render(window, sf::Color::Yellow);
        launcher.render(window, sf::Color::Magenta);
        p.render(window, c);
        ball.render(window, c);

        //display everything
        window.display();
    }
    return 0;
}
