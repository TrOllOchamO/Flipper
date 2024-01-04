#ifndef WALL_H_
#define WALL_H_

#include "Shape.h"
#include <SFML/Graphics.hpp>

class Wall : public Shape {
private:
    sf::Texture texture;
    sf::Sprite sprite;

public:
    Wall(Vector2D pos, const std::string& texturePath);

    Vector2D get_center() const override;
    Vector2D get_futhest_point(const Vector2D &direction) const override;

    void draw(sf::RenderWindow& window) const;
};

#endif /* !WALL_H_ */
