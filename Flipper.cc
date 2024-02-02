#include "Flipper.h"
#include "Polygone.h"
#include "Vector2D.h"
#include <SFML/Graphics/Color.hpp>

#define ROTATE 0.01
#define ROTATE_LIMITE_ACTIVATED 0.5
#define ROTATE_LIMITE_DESACTIVATED 0.0
#define DEFAULT_BOUNCINESS 0.6

Flipper::Flipper(const std::string &texturePath, FLIPPER_ORIENTATION orientation) : shape(Polygone()), orientation(orientation) {
  if (!texture.loadFromFile(texturePath)) {
    std::cerr << "Error loading texture from file: " << texturePath << std::endl;
  }
  texture.setRepeated(true);

  props.should_be_affected_by_others = false;
  props.velocity = Vector2D::zero();
  props.acceleration = Vector2D::zero();
  props.bounciness = DEFAULT_BOUNCINESS;

  switch (orientation) {
    case LEFT:
      shape.add_points( {Vector2D(135, 735), Vector2D(155, 740), Vector2D(135, 745), Vector2D(55, 750), Vector2D(50, 745), Vector2D(50, 735), Vector2D(55, 730)} );
      shape.rotate(0.3, Vector2D(60,740));
      break;
    case RIGHT:
      shape.add_points({Vector2D(195, 740), Vector2D(215, 735), Vector2D(295, 730), Vector2D(300, 735), Vector2D(300, 745), Vector2D(295, 750), Vector2D(215, 745)});
      shape.rotate(-0.3, Vector2D(290, 740));
      break;
  }
};

void Flipper::update(const Inputs &player_inputs) {
  props.should_affect_others = true;
  
  switch (orientation) {
    case LEFT:
      if (player_inputs.left_flipper && rotation < ROTATE_LIMITE_ACTIVATED) {
        props.should_affect_others = false;
        shape.rotate(-ROTATE, Vector2D(60,740));
        rotation += ROTATE;
      }
      if (!player_inputs.left_flipper && rotation > ROTATE_LIMITE_DESACTIVATED) {
        props.should_affect_others = false;
        shape.rotate(ROTATE, Vector2D(60,740));
        rotation -= ROTATE;
      }
      break;
    case RIGHT:
      if (player_inputs.right_flipper && rotation < ROTATE_LIMITE_ACTIVATED) {
        props.should_affect_others = false;
        shape.rotate(ROTATE, Vector2D(290, 740));
        rotation += ROTATE;
      }
      if (!player_inputs.right_flipper && rotation > ROTATE_LIMITE_DESACTIVATED) {
        props.should_affect_others = false;
        shape.rotate(-ROTATE, Vector2D(290, 740));
        rotation -= ROTATE;
      }
    break;
  }
};

void Flipper::render(sf::RenderWindow &window, sf::Color color) const {
  shape.render(window, color);
}

void Flipper::render(sf::RenderWindow &window) const {
  shape.render(window, texture);
}
