#include <iostream>
#include "Vector2D.h"
#include "Shape.h"
#include <math.h> 

#ifndef POLYGONE_H_
#define POLYGONE_H_

class Polygone: public Shape {
private:
    std::vector<Vector2D> points;

public:
    Polygone(Vector2D pos): Shape(pos) {};
    bool add_point(Vector2D point);
    bool is_convex();

    Vector2D get_center() const override ;
    Vector2D get_futhest_point(const Vector2D &direction) const override;
};

#endif /* !POLYGONE_H_ */
