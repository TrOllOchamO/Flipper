#include "Game.h"
#include "Physics.h"
#include <iostream>

void Game::set_map(Map new_map) { this->map = std::move(new_map); }

void Game::update(sf::RenderWindow& window, const Inputs& player_inputs, float dt) {
  // react to player inputs
  for (auto& element : map.get_elements()) {
    element->use_inputs(player_inputs);
  }

  // update velocity and position
  for (auto& element : map.get_elements()) {
    Physics::update(element->get_shape(), element->get_physics_props(), dt);
  }

  // resolve
  for (auto& element1 : map.get_elements()) {
    if (!element1->is_resolvable()) { continue; }
    for (auto& element2 : map.get_elements()) {
      if (!element2->is_resolvable()) { continue; }
      if (element1 == element2) { continue; }
      Physics::solve(element1->get_shape(), element1->get_physics_props(),
                     element2->get_shape(), element2->get_physics_props(),
                     dt);
    }
  }

  // render
  for (auto& element : map.get_elements()) {
    element->render(window);
  }
}
