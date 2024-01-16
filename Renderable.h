#include <assert.h>
#include <SFML/Graphics.hpp>

#ifndef RENDERABLE_H_
#define RENDERABLE_H_

class Renderable {
public:
  virtual void render(sf::RenderWindow &window, sf::Color color) const { assert(false); };
  virtual void render(sf::RenderWindow &window) const { assert(false); };
};

#endif
