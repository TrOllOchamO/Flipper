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
    Polygone(): Shape(Vector2D(0,0)) {};
    bool is_convex();

    Vector2D get_center() const override ;
    Vector2D get_futhest_point(const Vector2D &direction) const override;

    // CONSTRUIRE LES POLYGONES DANS LE SENS HORRAIRES !!!!!
    // CONSTRUIRE LES POLYGONES DANS LE SENS HORRAIRES !!!!!
    // CONSTRUIRE LES POLYGONES DANS LE SENS HORRAIRES !!!!!
    // CONSTRUIRE LES POLYGONES DANS LE SENS HORRAIRES !!!!!
    void add_point(Vector2D point);
    
    void clear();
    void print();    
    void render(sf::RenderWindow &window, sf::Color color);
    void rotate(float angle, Vector2D rotation_point, float dt = 1);

    std::vector<Polygone> triangulate();

    static bool is_ear(std::vector<Vector2D> polygon, int index);
    static bool point_inside_triangle(Vector2D a, Vector2D b, Vector2D c, Vector2D point);
    static bool is_outside(Vector2D a, Vector2D b, Vector2D c);
};

#endif /* !POLYGONE_H_ */
