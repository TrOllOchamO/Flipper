#include <iostream>
#include "Vector2D.h"

#ifndef BALL_H_
#define BALL_H_

class Ball{
private:
  Vector2D pos; // the center of the ball
  float radius;

public:
  Ball(Vector2D pos, float radius) : pos(pos), radius(radius) {};
};

#endif /* !BALL_H_ */
