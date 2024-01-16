#include <memory>
#include <iostream>

#include "Interfaces.h"

#ifndef MAP_H_
#define MAP_H_

struct EntityProperties {
  bool is_renderable = false;
  bool is_resolvable = false;
  bool is_interactable = false;
};

class Map {
private:
  std::vector<Entity*> elements;
  std::vector<Renderable*> elements_to_render;
  std::vector<Resolvable*> elements_to_resolve;
  std::vector<Interactable*> elements_who_needs_player_inputs;

public:
  void make_entity(std::unique_ptr<Entity> new_entity, const struct EntityProperties& entity_props);

  const std::vector<Entity*>& get_elements() const;
  const std::vector<Renderable*>& get_elements_to_render() const;
  const std::vector<Resolvable*>& get_elements_to_resolve() const;
  const std::vector<Interactable*>& get_elements_who_needs_player_inputs() const;
};

#endif /* !MAP_H_ */
