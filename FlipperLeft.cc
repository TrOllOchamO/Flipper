#include "FlipperLeft.h"
#include "Polygone.h"
#include "Vector2D.h"
#include <SFML/Graphics/Color.hpp>

#define ROTATE 0.01
#define ROTATE_LIMITE_ACTIVATED 0.5
#define ROTATE_LIMITE_DESACTIVATED 0.0
#define DEFAULT_BOUNCINESS 0.2
#define BOUNCINESS_WHEN_ACTIVATED 1.3

FlipperLeft::FlipperLeft(const std::string &texturePath) : shape(Polygone()) {
  if (!texture.loadFromFile(texturePath)) {
    std::cerr << "Error loading texture from file: " << texturePath
              << std::endl;
  }
  texture.setRepeated(true);

  props.should_react_with_other = false;
  props.mass = 10000000000;
  props.velocity = Vector2D::zero();
  props.acceleration = Vector2D::zero();
  props.bounciness = 1.3;

    shape.add_points( {Vector2D(135, 735), Vector2D(155, 740), Vector2D(135, 745), Vector2D(55, 750), Vector2D(50, 745), Vector2D(50, 735), Vector2D(55, 730)} );
    shape.rotate(0.3, Vector2D(60,740));
};

void FlipperLeft::use_inputs([[maybe_unused]] const Inputs &player_inputs) {
  props.bounciness = DEFAULT_BOUNCINESS;
  if (player_inputs.left_flipper && rotation < ROTATE_LIMITE_ACTIVATED) {
    props.bounciness = BOUNCINESS_WHEN_ACTIVATED;
    shape.rotate(-ROTATE, Vector2D(60,740));
    rotation += ROTATE;
  }
  if (!player_inputs.left_flipper && rotation > ROTATE_LIMITE_DESACTIVATED) {
    props.bounciness = BOUNCINESS_WHEN_ACTIVATED;
    shape.rotate(ROTATE, Vector2D(60,740));
    rotation -= ROTATE;
  }
};

void FlipperLeft::render(sf::RenderWindow &window, sf::Color color) const {
  shape.render(window, color);
}

void FlipperLeft::render(sf::RenderWindow &window) const {
  shape.render(window, texture);
}
