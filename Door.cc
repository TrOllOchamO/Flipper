#include "Door.h"
#include "Vector2D.h"
#include <SFML/Graphics/Color.hpp>
#include <iostream>

Door::Door(const std::string& texturePath) : shape(Polygone()) {
    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "Error loading texture from file: " << texturePath << std::endl;
    }

    shape.add_points({Vector2D(340,100), Vector2D(350,100), Vector2D(350, 250), Vector2D(340, 250)});

    props.should_be_affected_by_others = false;
    props.mass = 10000000000;
    props.velocity = Vector2D::zero();
    props.acceleration = Vector2D::zero();
    props.bounciness = 0.7;
}

bool Door::is_resolvable() {
  if (game->get_ball_handle()!=nullptr && game->get_ball_handle()->get_shape()->get_pos().x > 330){
    return false;
  } 
  return true;
}

void Door::render(sf::RenderWindow &window, sf::Color color) const {
  if (game->get_ball_handle()!=nullptr && game->get_ball_handle()->get_shape()->get_pos().x < 350){
    shape.render(window, color);
  }
}

void Door::render(sf::RenderWindow &window) const {
  if (game->get_ball_handle()!=nullptr && game->get_ball_handle()->get_shape()->get_pos().x < 350){
    shape.render(window, texture);
  }
}
