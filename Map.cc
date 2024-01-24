#include <iostream>
#include <memory>

#include "Map.h"

void Map::make_entity(std::unique_ptr<Entity> new_entity) {
      std::cout << "a\n"; 

  elements.push_back(std::move(new_entity));
    std::cout << "b\n"; 

}

std::vector<std::unique_ptr<Entity>>& Map::get_elements() {
  return elements;
}