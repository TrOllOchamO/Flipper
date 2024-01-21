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
#include "Ball.h"
#include "Bumper.h"
#include "Vector2D.h"

#define WINDOWS_WIDTH 400
#define WINDOWS_HEIGHT 800

int main() {
  sf::RenderWindow window(sf::VideoMode(WINDOWS_WIDTH, WINDOWS_HEIGHT), "Flipper");
  sf::Clock clock;
  Inputs inputs;

  // on créer la map
  Map map;

  std::unique_ptr<Shape> bottom_bar = std::make_unique<Circle>(Vector2D(0, 600), WINDOWS_WIDTH/2);
  std::unique_ptr<Shape> upper_bar = std::make_unique<Rectangle>(Vector2D(0, 0), WINDOWS_WIDTH, 100);
  std::unique_ptr<Shape> left_bar = std::make_unique<Rectangle>(Vector2D(0, 0), 10, WINDOWS_HEIGHT);
  std::unique_ptr<Shape> right_bar = std::make_unique<Rectangle>(Vector2D(WINDOWS_WIDTH -10, 0), 10, WINDOWS_HEIGHT);

  // std::unique_ptr<Entity> bottom_wall = std::make_unique<Wall>(std::move(bottom_bar), "/home/riz/Bureau/flipper/Flipper/resources/Test.jpg");
  std::unique_ptr<Entity> upper_wall = std::make_unique<Wall>(std::move(upper_bar), "./resources/Test.jpg");
  std::unique_ptr<Entity> left_wall = std::make_unique<Wall>(std::move(left_bar), "./resources/Test.jpg");
  std::unique_ptr<Entity> right_wall = std::make_unique<Wall>(std::move(right_bar), "./resources/Test.jpg");
  std::unique_ptr<Entity> bumper = std::make_unique<Bumper>(std::move(bottom_bar), "./resources/ballTest.png");




  // map.make_entity(std::move(bottom_wall));
  map.make_entity(std::move(upper_wall));
  map.make_entity(std::move(left_wall));
  map.make_entity(std::move(right_wall));
  map.make_entity(std::move(bumper));

  // std::unique_ptr<Ball> ball1 = std::make_unique<Ball>(Vector2D(200, 400), 8, "");
  // ball1->set_acceleration(Vector2D::zero());
  // ball1->set_velocity(Vector2D(0, 0));
  // ball1->set_angular_velocity(1);
  // ball1->get_props()->bounciness = 1;
  // ball1->get_props()->mass = 1000000000;
  // map.make_entity(std::move(ball1));


  // std::unique_ptr<Ball> ball2 = std::make_unique<Ball>(Vector2D(500, 400), 8, "./resources/ballTest.png");
  // ball2->set_acceleration(Vector2D::zero());
  // ball2->set_velocity(Vector2D(-200, 0));
  // ball2->set_angular_velocity(2);
  // ball2->get_props()->bounciness = 1;
  // map.make_entity(std::move(ball2));

  for (int x = 50; x < 451; x += 50) {
    std::unique_ptr<Entity> ball = std::make_unique<Ball>(Vector2D(x, 400), 8, "./resources/ballTest.png");
    map.make_entity(std::move(ball));
  }

  Game game(std::move(map));
    
  while (window.isOpen()) {
  // for (size_t i = 0; i < 40; ++i) {
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
