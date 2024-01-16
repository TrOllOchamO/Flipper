#include "Map.h"
#include <iostream>

void Map::make_entity(std::unique_ptr<Entity> new_entity, const struct EntityProperties &entity_props) {
  elements.push_back((Entity*) new_entity.get());

  if (entity_props.is_renderable) {
    std::cout << "au cas ou pour etre sur?" << std::endl;
    elements_to_render.push_back((Renderable*) new_entity.get());
    std::cout << "taille : " << elements_to_render.size() << std::endl;
  }

  if (entity_props.is_resolvable) {
    elements_to_resolve.push_back((Resolvable*) new_entity.get());
  }

  if (entity_props.is_interactable) {
    elements_who_needs_player_inputs.push_back((Interactable*) new_entity.get());
  }
}

const std::vector<Entity*>& Map::get_elements() const {
  return elements;
}
const std::vector<Renderable*>& Map::get_elements_to_render() const {
  std::cout << elements_to_render.size() << std::endl;
  return elements_to_render;
}
const std::vector<Resolvable*>& Map::get_elements_to_resolve() const {
  return elements_to_resolve;
}
const std::vector<Interactable*>& Map::get_elements_who_needs_player_inputs() const {
  return elements_who_needs_player_inputs;
}
