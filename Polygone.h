#include <iostream>
#include "Vector2D.h"
#include "Shape.h"
#include <math.h> 

#ifndef POLYGONE_H_
#define POLYGONE_H_

class Polygone: public Shape {
private:
    std::vector<Vector2D> points;
    std::vector<Polygone> concave_points;
    bool convex = true;

public:
    Polygone(): Shape(Vector2D::zero()) {};
    bool is_convex() const;
    Vector2D get_center() const override ;
    Vector2D get_futhest_point(const Vector2D &direction) const override;

    // CONSTRUIRE LES POLYGONES DANS LE SENS HORRAIRES !!!!!
    // CONSTRUIRE LES POLYGONES DANS LE SENS HORRAIRES !!!!!
    // CONSTRUIRE LES POLYGONES DANS LE SENS HORRAIRES !!!!!
    // CONSTRUIRE LES POLYGONES DANS LE SENS HORRAIRES !!!!!
    void add_point(Vector2D point);
    void add_points(std::vector<Vector2D> point);

    void clear();
    void render(sf::RenderWindow &window, sf::Color color) const override;
    void print();
    void rotate(float angle, Vector2D rotation_point, float dt = 1);

    std::vector<Polygone> triangulate();

    static bool is_ear(const std::vector<Vector2D>& polygon, int index);
    static bool point_inside_triangle(Vector2D a, Vector2D b, Vector2D c, Vector2D point);
    static bool is_outside(Vector2D a, Vector2D b, Vector2D c);
};

#endif /* !POLYGONE_H_ */


