#include <iostream>
#include <memory>

#include "Map.h"

void Map::make_entity(std::unique_ptr<Entity> new_entity) {
  elements.push_back(std::move(new_entity));
}

std::vector<std::unique_ptr<Entity>>& Map::get_elements() {
  return elements;
}
