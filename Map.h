#include <memory>
#include <iostream>

#include "Interfaces.h"

#ifndef MAP_H_
#define MAP_H_

class Map {
private:
  std::vector<std::unique_ptr<Entity>> elements;

public:
  Map() = default;
  Map(Map&&) noexcept = default;

  Map& operator=(const Map&) = delete;
  Map& operator=(Map&&) noexcept = default;

  void make_entity(std::unique_ptr<Entity> new_entity);

  std::vector<std::unique_ptr<Entity>>& get_elements();
};

#endif /* !MAP_H_ */
