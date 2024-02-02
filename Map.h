#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Interfaces.h"

#ifndef MAP_H_
#define MAP_H_

class Map {
private:
  const char * level;

public:
  std::vector<std::unique_ptr<Entity>> elements; 
  Map() = default;
  Map(Map&&) noexcept = default;

  Map& operator=(const Map&) = delete;
  Map& operator=(Map&&) noexcept = default;

  void make_entity(std::unique_ptr<Entity> new_entity);
  void kill_entity(Entity* entity); // WARNING killing an entity invalidate indexes in elements array
  void remove_killed_entitys();

  std::vector<std::unique_ptr<Entity>>& get_elements();

  void set_name(const char * s) {level = s;}
  const char * get_name() {return level;}
};

#endif /* !MAP_H_ */
