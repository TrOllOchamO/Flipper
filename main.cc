#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <iostream>
#include <memory>
#include <vector>

#include "Inputs.h"
#include "Game.h"
#include "Map.h"
#include "Wall.h"
#include "Rectangle.h"

#define WINDOWS_WIDTH 400
#define WINDOWS_HEIGHT 800

int main() {
  sf::RenderWindow window(sf::VideoMode(WINDOWS_WIDTH, WINDOWS_HEIGHT), "Flipper");
  sf::Clock clock;
  Inputs inputs;

  // on créer la map
  Map map;
  std::unique_ptr<Shape> bar = std::make_unique<Rectangle>(Vector2D(0, WINDOWS_HEIGHT - 10), WINDOWS_WIDTH, 10);
  std::unique_ptr<Entity> wall = std::make_unique<Wall>(std::move(bar), "Test.jpg");

  map.make_entity(std::move(wall));
  Game game(std::move(map));
    
  while (window.isOpen()) {
    float dt = clock.restart().asSeconds();
    inputs.update(window);
    window.clear(sf::Color::Black);

    game.update(window, inputs, dt);

    window.display();
  }
}


  // for (int x = 50; x < 451; x += 50) {
  //   Ball *ball = new Ball(Vector2D(x, 30), 8);
  //   elements_to_render.push_back(ball);
  //   elements_with_pysics.push_back(ball);
  // }

  // std::unique_ptr<Shape> bottom_bar = std::make_unique<Rectangle>(Rectangle(Vector2D(0, WINDOWS_HEIGHT - 10), WINDOWS_WIDTH, 10));
  // std::unique_ptr<Shape> upper_bar = std::make_unique<Rectangle>(Rectangle(Vector2D(0, 0), WINDOWS_WIDTH, 10));
  // std::unique_ptr<Shape> left_bar = std::make_unique<Rectangle>(Rectangle(Vector2D(0, 0), 10, WINDOWS_HEIGHT));
  // std::unique_ptr<Shape> right_bar = std::make_unique<Rectangle>(Rectangle(Vector2D(WINDOWS_WIDTH -10, 0), 10, WINDOWS_HEIGHT));

  // Wall *bottom_wall = new Wall(std::move(bottom_bar), "Test.jpg");
  // elements_to_render.push_back(bottom_wall);
  // elements_with_pysics.push_back(bottom_wall);
  // Wall *upper_wall = new Wall(std::move(upper_bar), "Test.jpg");
  // elements_to_render.push_back(upper_wall);
  // elements_with_pysics.push_back(upper_wall);
  // Wall *left_wall = new Wall(std::move(left_bar), "Test.jpg");
  // elements_to_render.push_back(left_wall);
  // elements_with_pysics.push_back(left_wall);
  // Wall *right_wall = new Wall(std::move(right_bar), "Test.jpg");
  // elements_to_render.push_back(right_wall);
  // elements_with_pysics.push_back(right_wall);

  // std::unique_ptr<Shape> circle1 = std::make_unique<Circle>(Circle(Vector2D(0, WINDOWS_HEIGHT*3/4), WINDOWS_WIDTH/3));
  // Bumper* bumper1 = new Bumper(std::move(circle1), "Test.jpg");
  // elements_to_render.push_back(bumper1);
  // elements_with_pysics.push_back(bumper1);

  // std::unique_ptr<Shape> circle2 = std::make_unique<Circle>(Circle(Vector2D(WINDOWS_WIDTH/2, WINDOWS_HEIGHT*3/4), WINDOWS_WIDTH/3));
  // Bumper* bumper2 = new Bumper(std::move(circle2), "Test.jpg");
  // elements_to_render.push_back(bumper2);
  // elements_with_pysics.push_back(bumper2);
