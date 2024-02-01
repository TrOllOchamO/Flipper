#include <memory>
#include <iostream>

#include "Interfaces.h"

#ifndef MAP_H_
#define MAP_H_

class Map {
private:

public:
  std::vector<std::unique_ptr<Entity>> elements; 
  Map() = default;
  Map(Map&&) noexcept = default;

  Map& operator=(const Map&) = delete;
  Map& operator=(Map&&) noexcept = default;

  void make_entity(std::unique_ptr<Entity> new_entity);
  void kill_entity(Entity* entity); // WARNING killing an entity invalidate indexes in elements array

  std::vector<std::unique_ptr<Entity>>& get_elements();
};

#endif /* !MAP_H_ */
