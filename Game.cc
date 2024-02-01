#include "Game.h"
#include "Physics.h"
#include <cstddef>
#include <iostream>
#include <utility>

Game::Game(Map map) {
  set_map(std::move(map));
}

void Game::set_map(Map new_map) { 
  for (auto& element : new_map.get_elements()) {
    element->set_game(this);
  }
  this->map = std::move(new_map); 
  this->ball_handle = nullptr;
}

void Game::make_entity(std::unique_ptr<Entity> new_element) {
  new_element->set_game(this);
  this->map.make_entity(std::move(new_element));
}

void Game::update(sf::RenderWindow& window, const Inputs& player_inputs, float dt) {
  auto& elements = map.get_elements();
  // react to player inputs
  for (auto& element : elements) {
    element->update(player_inputs);
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

void Game::make_ball(std::unique_ptr<Ball> new_ball) {
  assert(ball_handle == nullptr);
  ball_handle = new_ball.get();
  map.make_entity(std::move(new_ball));
}

void Game::kill_ball() {
  if (this->ball_handle == nullptr) {
    return;
  }
  
  map.kill_entity(ball_handle);
  this->ball_handle = nullptr;
}
