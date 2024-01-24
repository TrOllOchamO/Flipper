#include <iostream>
#include <memory>

#include "Map.h"

void Map::make_entity(std::unique_ptr<Entity> new_entity) {
  elements.push_back(std::move(new_entity));
}

const std::vector<std::unique_ptr<Entity>>& Map::get_elements() const {
  return elements;
}