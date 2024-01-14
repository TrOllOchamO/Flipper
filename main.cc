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

    Ball ball(Vector2D(200, 200), 8);

    Polygone concave;
    concave.add_point( {Vector2D(50,480), Vector2D(90,440), Vector2D(85,510), Vector2D(150,465), 
    Vector2D(85,520), Vector2D(140,520), Vector2D(160,530), Vector2D(75,530), Vector2D(75,480)} );


    Polygone p;
    p.add_point( {Vector2D(220,200), Vector2D(280,200), Vector2D(280,210), Vector2D(220,210)} );

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
        concave.rotate(1, Vector2D(80, 525), dt);
        p.rotate(-3, Vector2D(230, 205), dt);
        // ball.move(dt);

        //change color if collide
        sf::Color c = sf::Color::Green;
        if (Collision::are_colliding(ball.get_shape(), &p)) {
            c = sf::Color::Red;
        }

        //render things
        flipper.render(window, sf::Color::Yellow);
        launcher.render(window, sf::Color::Magenta);
        concave.render(window, sf::Color::White);
        p.render(window, c);
        ball.render(window, c);

        //display everything
        window.display();
    }
    return 0;
}