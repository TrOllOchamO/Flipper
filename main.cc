#include "Ball.h"
#include "Collision.h"
#include "Polygone.h"
#include "Rectangle.h"
#include "Vector2D.h"
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

  Rectangle r(Vector2D(50, 300), 400, 50);

  while (window.isOpen()) {
    float dt = clock.restart().asSeconds();

    sf::Event event;
    window.clear(sf::Color::Black);
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
    ball.move(dt);
    sf::Color c = sf::Color::Green;
    if (Collision::are_colliding(ball.get_shape(), &p)) {
      c = sf::Color::Red;
    }
    p.render(window, c);
    ball.render(window, c);
    // p.render(window, c);
    window.display();
  }

  return 0;
}
