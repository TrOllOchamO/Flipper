#include <iostream>
#include "Vector2D.h"
#include <SFML/Graphics.hpp>

#ifndef BALL_H_
#define BALL_H_

class Ball{
private:
  Vector2D pos; // top left corner
  float radius;
  Vector2D velocity;
  Vector2D gravity;

public:
  //CONSTRUCTEUR A MODIFIER A CAUSE DE L4EXEMPLE                         Vector2D::zero()
  Ball(Vector2D pos, float radius) : pos(pos), radius(radius), velocity(Vector2D(150,-750)), gravity(Vector2D::down()*750) {};
  
  void render(sf::RenderWindow &window);
  void move(float dt);
  void apply_gravity(float dt);
  
  Vector2D get_center_position();
};

#endif /* !BALL_H_ */
