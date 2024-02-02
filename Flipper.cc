#include "Flipper.h"
#include "Polygone.h"
#include "Vector2D.h"
#include <SFML/Graphics/Color.hpp>

#define ROTATION_STEP 25
#define ROTATE_LIMITE_ACTIVATED 0.5
#define ROTATE_LIMITE_DESACTIVATED 0.0
#define DEFAULT_BOUNCINESS 0.6
#define DEFAULT_ROTATION 0.3

#define LEFT_FLIPPER_POINTS {Vector2D(135, 735), Vector2D(155, 740), Vector2D(135, 745), Vector2D(55, 750), Vector2D(50, 745), Vector2D(50, 735), Vector2D(55, 730)}
#define RIGHT_FLIPPER_POINTS {Vector2D(195, 740), Vector2D(215, 735), Vector2D(295, 730), Vector2D(300, 735), Vector2D(300, 745), Vector2D(295, 750), Vector2D(215, 745)}
#define LEFT_ROTATION_POINT Vector2D(60,740) 
#define RIGHT_ROTATION_POINT Vector2D(290,740) 

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
      shape.add_points(LEFT_FLIPPER_POINTS);
      rotation_direction = CLOCKWISE;
      rotation_point = LEFT_ROTATION_POINT;
      is_activated = &Inputs::left_flipper;
      break;
    case RIGHT:
      shape.add_points(RIGHT_FLIPPER_POINTS);
      rotation_direction = COUNTERCLOCKWISE;
      rotation_point = RIGHT_ROTATION_POINT;
      is_activated = &Inputs::right_flipper;
      break;
  }

  shape.rotate(rotation_direction * DEFAULT_ROTATION, rotation_point);
};

void Flipper::update(const Inputs &player_inputs, float dt) {
  props.should_affect_others = true;
  
  const bool flipper_activated = player_inputs.*is_activated;
  if (flipper_activated && rotation < ROTATE_LIMITE_ACTIVATED) {
    props.should_affect_others = false;
    shape.rotate(-rotation_direction * ROTATION_STEP, rotation_point, dt);
    rotation += ROTATION_STEP * dt;
  }
  else if (!flipper_activated && rotation > ROTATE_LIMITE_DESACTIVATED) {
    props.should_affect_others = false;
    shape.rotate(rotation_direction * ROTATION_STEP, rotation_point, dt);
    rotation -= ROTATION_STEP * dt;
  }
};

void Flipper::render(sf::RenderWindow &window, sf::Color color) const {
  shape.render(window, color);
}

void Flipper::render(sf::RenderWindow &window) const {
  shape.render(window, texture);
}
