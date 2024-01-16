#include "Ball.h"
#include "Collision.h"
#include "Input.h"
#include "Physics.h"
#include "Polygone.h"
#include "Rectangle.h"
#include "Vector2D.h"
#include "Wall.h"
#include "Bumper.h"
#include "Input.h"
#include "Flipper.h"
#include "Launcher.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <iostream>
#include <memory>
#include <vector>

#define WINDOWS_WIDTH 400
#define WINDOWS_HEIGHT 800

int main() {
  sf::RenderWindow window(sf::VideoMode(WINDOWS_WIDTH, WINDOWS_HEIGHT), "Flipper");
  sf::Clock clock;
  Input input;

  std::vector<Renderable*> elements_to_render;
  std::vector<Resolvable*> elements_with_pysics;

  for (int x = 50; x < 451; x += 50) {
    Ball *ball = new Ball(Vector2D(x, 30), 8);
    elements_to_render.push_back(ball);
    elements_with_pysics.push_back(ball);
  }

  std::unique_ptr<Shape> bottom_bar = std::make_unique<Rectangle>(Rectangle(Vector2D(0, WINDOWS_HEIGHT - 10), WINDOWS_WIDTH, 10));
  std::unique_ptr<Shape> upper_bar = std::make_unique<Rectangle>(Rectangle(Vector2D(0, 0), WINDOWS_WIDTH, 10));
  std::unique_ptr<Shape> left_bar = std::make_unique<Rectangle>(Rectangle(Vector2D(0, 0), 10, WINDOWS_HEIGHT));
  std::unique_ptr<Shape> right_bar = std::make_unique<Rectangle>(Rectangle(Vector2D(WINDOWS_WIDTH -10, 0), 10, WINDOWS_HEIGHT));

  Wall *bottom_wall = new Wall(std::move(bottom_bar), "Test.jpg");
  elements_to_render.push_back(bottom_wall);
  elements_with_pysics.push_back(bottom_wall);
  Wall *upper_wall = new Wall(std::move(upper_bar), "Test.jpg");
  elements_to_render.push_back(upper_wall);
  elements_with_pysics.push_back(upper_wall);
  Wall *left_wall = new Wall(std::move(left_bar), "Test.jpg");
  elements_to_render.push_back(left_wall);
  elements_with_pysics.push_back(left_wall);
  Wall *right_wall = new Wall(std::move(right_bar), "Test.jpg");
  elements_to_render.push_back(right_wall);
  elements_with_pysics.push_back(right_wall);

  std::unique_ptr<Shape> circle1 = std::make_unique<Circle>(Circle(Vector2D(0, WINDOWS_HEIGHT*3/4), WINDOWS_WIDTH/3));
  Bumper* bumper1 = new Bumper(std::move(circle1), "Test.jpg");
  elements_to_render.push_back(bumper1);
  elements_with_pysics.push_back(bumper1);

  std::unique_ptr<Shape> circle2 = std::make_unique<Circle>(Circle(Vector2D(WINDOWS_WIDTH/2, WINDOWS_HEIGHT*3/4), WINDOWS_WIDTH/3));
  Bumper* bumper2 = new Bumper(std::move(circle2), "Test.jpg");
  elements_to_render.push_back(bumper2);
  elements_with_pysics.push_back(bumper2);

  while (window.isOpen()) {
    float dt = clock.restart().asSeconds();
    input.update(window);
    window.clear(sf::Color::Black);

    // apply movement
    for (Resolvable* element : elements_with_pysics) {
      Physics::update(element->get_shape(), element->get_physics_props(), dt);
    }

    // resolve
    for (Resolvable *element1 : elements_with_pysics) {
      for (Resolvable *element2 : elements_with_pysics) {
        if (element1 == element2) {
          continue;
        }
        Physics::solve(element1->get_shape(), element1->get_physics_props(),
                       element2->get_shape(), element2->get_physics_props(),
                       dt);
      }
    }

    // render
    for (Renderable *element : elements_to_render) {
      element->render(window);
    }

    window.display();
  }

  // TODO
  // FIXME je désaloue pas pour la démo mais il faudra qu'on réfléchisse a
  // comment on va free les éléments de jeu

  return 0;
}
// =======
//     Ball ball(Vector2D(200, 200), 8);

//     Polygone concave;
//     concave.add_point( {Vector2D(50,480), Vector2D(90,440), Vector2D(85,510), Vector2D(150,465), 
//     Vector2D(85,520), Vector2D(140,520), Vector2D(160,530), Vector2D(75,530), Vector2D(75,480)} );


//     Polygone p;
//     p.add_point( {Vector2D(220,200), Vector2D(280,200), Vector2D(280,210), Vector2D(220,210)} );

//     Input input;
//     Flipper flipper;
//     Launcher launcher;

//     while (window.isOpen()) {
//         //update the game
//         float dt = clock.restart().asSeconds();
//         window.clear(sf::Color::Black);
//         input.update(window);

//         //update controllable things
//         flipper.upate(input.left_flipper, input.right_flipper);
//         launcher.upate(input.up_launcher, input.down_launcher, input.enter_launcher);

//         //move things
//         concave.rotate(1, Vector2D(80, 525), dt);
//         p.rotate(-3, Vector2D(230, 205), dt);
//         // ball.move(dt);

//         //change color if collide
//         sf::Color c = sf::Color::Green;
//         if (Collision::are_colliding(ball.get_shape(), &p)) {
//             c = sf::Color::Red;
//         }

//         //render things
//         flipper.render(window, sf::Color::Yellow);
//         launcher.render(window, sf::Color::Magenta);
//         concave.render(window, sf::Color::White);
//         p.render(window, c);
//         ball.render(window, c);

//         //display everything
//         window.display();
//     }
//     return 0;
// }
