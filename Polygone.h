#include <iostream>
#include "Vector2D.h"
#include "Shape.h"
#include <math.h> 

#ifndef POLYGONE_H_
#define POLYGONE_H_

class Polygone: public Shape {
private:
    std::vector<Vector2D> points;
    Vector2D rotation_point;

public:
    Polygone(Vector2D rotation_p): Shape(Vector2D::zero()), rotation_point(rotation_p) {};
    void add_point(Vector2D point);
    bool is_convex() const;

    Vector2D get_center() const override ;
    Vector2D get_futhest_point(const Vector2D &direction) const override;

    void clear();
    void render(sf::RenderWindow &window, sf::Color color) const override;
    void rotate(float angle, float dt = 1);
};

#endif /* !POLYGONE_H_ */
