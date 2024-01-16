#include <assert.h>
#include <SFML/Graphics.hpp>

#ifndef RENDERABLE_H_
#define RENDERABLE_H_

class Renderable {
public:
  virtual void render([[maybe_unused]] sf::RenderWindow &window, [[maybe_unused]] sf::Color color) const { assert(false); };
  virtual void render([[maybe_unused]] sf::RenderWindow &window) const { assert(false); };
};

#endif
