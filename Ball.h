#include <iostream>
#include "Vector2D.h"
#include "Circle.h"
#include <SFML/Graphics.hpp>

#ifndef BALL_H_
#define BALL_H_

class Ball{
private:
  Vector2D pos;
  float radius;
  Circle shape;
  Vector2D velocity;
  Vector2D gravity;

  void update_shape();

public:
  //CONSTRUCTEUR MODIFIER A CAUSE DE L'EXEMPLE                                  Vector2D::zero()
  Ball(Vector2D pos, float radius) : pos(pos), radius(radius), shape(pos, radius), velocity(Vector2D(150,-750)), gravity(Vector2D::down()*750) {};

  const Shape * get_shape() const;
  void render(sf::RenderWindow &window, sf::Color color);
  void move(float dt);
  void apply_gravity(float dt);
  void bounceX();
  void bounceY();
  void check_if_outside();


  Vector2D get_center_position();
};

#endif /* !BALL_H_ */
