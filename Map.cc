#include <iostream>
#include <memory>

#include "Map.h"

void Map::make_entity(std::unique_ptr<Entity> new_entity) {
  elements.push_back(std::move(new_entity));
}

void Map::remove_killed_entitys() {
  auto pred = [](std::unique_ptr<Entity>& e) { return e->has_to_be_killed(); };
  auto end_it = std::remove_if(elements.begin(), elements.end(), pred);
  elements.erase(end_it, elements.end());
}

std::vector<std::unique_ptr<Entity>>& Map::get_elements() {
  return elements;
}
