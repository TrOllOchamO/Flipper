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
#include "FlipperLeft.h"
#include "FlipperRight.h"
#include "Launcher.h"
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

  // shape
  std::unique_ptr<Circle> bumper_1_shape = std::make_unique<Circle>(Vector2D(40, 300), 16);
  std::unique_ptr<Circle> bumper_2_shape = std::make_unique<Circle>(Vector2D(150, 300), 16);
  std::unique_ptr<Circle> bumper_3_shape = std::make_unique<Circle>(Vector2D(260, 300), 16);

  std::unique_ptr<Circle> bumper_4_shape = std::make_unique<Circle>(Vector2D(40, 500), 16);
  std::unique_ptr<Circle> bumper_5_shape = std::make_unique<Circle>(Vector2D(150, 500), 16);
  std::unique_ptr<Circle> bumper_6_shape = std::make_unique<Circle>(Vector2D(260, 500), 16);

  std::unique_ptr<Circle> bumper_7_shape = std::make_unique<Circle>(Vector2D(80, 400), 16);
  std::unique_ptr<Circle> bumper_8_shape = std::make_unique<Circle>(Vector2D(215, 400), 16);
  
  std::unique_ptr<Rectangle> bottom_wall_shape = std::make_unique<Rectangle>(Rectangle(Vector2D(0, WINDOWS_HEIGHT - 10), WINDOWS_WIDTH, 10));
  std::unique_ptr<Rectangle> top_wall_shape = std::make_unique<Rectangle>(Rectangle(Vector2D(0, 0), WINDOWS_WIDTH, 10));
  std::unique_ptr<Rectangle> left_wall_shape = std::make_unique<Rectangle>(Rectangle(Vector2D(0, 0), 10, WINDOWS_HEIGHT));
  std::unique_ptr<Rectangle> right_wall_shape = std::make_unique<Rectangle>(Rectangle(Vector2D(WINDOWS_WIDTH -10, 0), 10, WINDOWS_HEIGHT));
  
  std::unique_ptr<Rectangle> separation_wall_shape = std::make_unique<Rectangle>(Rectangle(Vector2D(340, 150), 10, 750));

  std::unique_ptr<Polygone> left_angle_shape = std::make_unique<Polygone>(Polygone());
  left_angle_shape->add_points({Vector2D(0,0), Vector2D(100,0), Vector2D(0,100)});
  std::unique_ptr<Polygone> right_angle_shape = std::make_unique<Polygone>(Polygone());
  right_angle_shape->add_points({Vector2D(300,0), Vector2D(400,0), Vector2D(400,100)});


  // entity
  std::unique_ptr<Bumper> bumper_1 = std::make_unique<Bumper>(std::move(bumper_1_shape), "");
  std::unique_ptr<Bumper> bumper_2 = std::make_unique<Bumper>(std::move(bumper_2_shape), "");
  std::unique_ptr<Bumper> bumper_3 = std::make_unique<Bumper>(std::move(bumper_3_shape), "");
  std::unique_ptr<Bumper> bumper_4 = std::make_unique<Bumper>(std::move(bumper_4_shape), "");
  std::unique_ptr<Bumper> bumper_5 = std::make_unique<Bumper>(std::move(bumper_5_shape), "");
  std::unique_ptr<Bumper> bumper_6 = std::make_unique<Bumper>(std::move(bumper_6_shape), "");
  std::unique_ptr<Bumper> bumper_7 = std::make_unique<Bumper>(std::move(bumper_7_shape), "");
  std::unique_ptr<Bumper> bumper_8 = std::make_unique<Bumper>(std::move(bumper_8_shape), "");

  std::unique_ptr<Wall> bottom_wall = std::make_unique<Wall>(std::move(bottom_wall_shape), "resources/Test.jpg");
  std::unique_ptr<Wall> top_wall = std::make_unique<Wall>(std::move(top_wall_shape), "resources/Test.jpg");
  std::unique_ptr<Wall> left_wall = std::make_unique<Wall>(std::move(left_wall_shape), "resources/Test.jpg");
  std::unique_ptr<Wall> right_wall = std::make_unique<Wall>(std::move(right_wall_shape), "resources/Test.jpg");

  std::unique_ptr<Wall> separation_wall = std::make_unique<Wall>(std::move(separation_wall_shape), "resources/Test.jpg");

  std::unique_ptr<Wall> left_angle = std::make_unique<Wall>(std::move(left_angle_shape), "resources/Test.jpg");
  std::unique_ptr<Wall> right_angle = std::make_unique<Wall>(std::move(right_angle_shape), "resources/Test.jpg");

  std::unique_ptr<Ball> ball = std::make_unique<Ball>(Vector2D(362, 730), 8, "./resources/ballTest.png");

  ball->set_velocity(Vector2D(0, -2000));

  std::unique_ptr<Launcher> launcher = std::make_unique<Launcher>("");
  std::unique_ptr<FlipperLeft> left_flipper = std::make_unique<FlipperLeft>("");
  std::unique_ptr<FlipperRight> right_flipper = std::make_unique<FlipperRight>("");

  // make entity
  map.make_entity(std::move(bumper_1));
  map.make_entity(std::move(bumper_2));
  map.make_entity(std::move(bumper_3));
  map.make_entity(std::move(bumper_4));
  map.make_entity(std::move(bumper_5));
  map.make_entity(std::move(bumper_6));
  map.make_entity(std::move(bumper_7));
  map.make_entity(std::move(bumper_8));

  map.make_entity(std::move(bottom_wall));
  map.make_entity(std::move(top_wall));
  map.make_entity(std::move(left_wall));
  map.make_entity(std::move(right_wall));

  map.make_entity(std::move(separation_wall));

  map.make_entity(std::move(left_angle));
  map.make_entity(std::move(right_angle));

  map.make_entity(std::move(ball));
  map.make_entity(std::move(launcher));
  map.make_entity(std::move(left_flipper));
  map.make_entity(std::move(right_flipper));


  // load map
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
