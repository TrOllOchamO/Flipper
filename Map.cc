#include <iostream>
#include <memory>

#include "Map.h"

void Map::make_entity(std::unique_ptr<Entity> new_entity) {
  elements.push_back(std::move(new_entity));
}

void Map::kill_entity(Entity* entity) {
  auto is_target_entity = [&](const std::unique_ptr<Entity>& e) { return e.get() == entity; };
  auto target_it = std::find_if(elements.begin(), elements.end(), is_target_entity);

  // the entity doesnt exist
  if (target_it == elements.cend()) {
    return;
  }

  // remove the entity
  std::iter_swap(target_it, elements.end() - 1);
  elements.pop_back();
}

std::vector<std::unique_ptr<Entity>>& Map::get_elements() {
  return elements;
}
