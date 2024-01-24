#include "Game.h"
#include "Physics.h"
#include <cstddef>
#include <iostream>

void Game::set_map(Map new_map) { 
  this->map = std::move(new_map); 
  for (auto& element : this->map.get_elements()) {
    element->set_game(this);
  }
}

void Game::update(sf::RenderWindow& window, const Inputs& player_inputs, float dt) {
  auto& elements = map.get_elements();
  // react to player inputs
  for (auto& element : elements) {
    element->use_inputs(player_inputs);
  }

  // update velocity and position
  for (auto& element : elements) {
    Physics::update(element->get_shape(), element->get_physics_props(), dt);
  }

  // resolve
  for (size_t i = 0; i < elements.size(); ++i) {
    auto& element1 = elements[i];
    if (!element1->is_resolvable()) { continue; }
    for (size_t j = i + 1; j < elements.size(); ++j ) {
      auto& element2 = elements[j];
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
