#include "Game.h"
#include "Physics.h"
#include "Score.h"

#include <cstddef>
#include <iostream>
#include <utility>

Game::Game(Map map) {
  set_map(std::move(map));
  score = 0.0;
  multiplicateur = 1.0;
  vie = 3;
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
    if (!element->is_resolvable()) { continue; }
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
      auto res = Physics::solve(element1->get_shape(), element1->get_physics_props(),
                     element2->get_shape(), element2->get_physics_props(),
                     dt);
      if (res) {
        multiplicateur += element1->get_mult();
        multiplicateur += element2->get_mult();
        score += element1->get_points_to_add() * multiplicateur;
        score += element2->get_points_to_add() * multiplicateur;
      }
    }
  }

  // render
  for (auto& element : map.get_elements()) {
    element->render(window);
  }

  if(vie==0){
    end();
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

float Game::get_score(){
  return score;
}

void Game::update_score(float add) {
  score += add;
}

void Game::loose_life(){
  vie -= 1;
}  

int Game::get_life(){
  return vie;
}

float Game::get_multiplicateur(){
  return multiplicateur;
}

void Game::end(){
//   float best = Score::load_best_score(map.get_name());
//   if (score > best){
//     Score::store_best_score(score,map.get_name());
//   }  
}