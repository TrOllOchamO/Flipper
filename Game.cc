#include "Game.h"

// FIXME leak ?
void Game::set_map(Map new_map) { this->map = new_map; }

void Game::update(sf::RenderWindow& window, const Inputs& player_inputs, float dt) {
  for (Interactable* element : map.get_elements_who_needs_player_inputs()) {
    element->use_inputs(player_inputs);
  }

  // update velocity and position
  for (Resolvable *element : map.get_elements_to_resolve()) {
    Physics::update(element->get_shape(), element->get_physics_props(), dt);
  }

  // resolve
  for (Resolvable *element1 : map.get_elements_to_resolve()) {
    for (Resolvable *element2 : map.get_elements_to_resolve()) {
      if (element1 == element2) {
        continue;
      }
      Physics::solve(element1->get_shape(), element1->get_physics_props(),
                     element2->get_shape(), element2->get_physics_props(), dt);
    }
  }

  // render
  for (Renderable *element : map.get_elements_to_render()) {
    element->render(window);
  }
}
