/*#ifndef MAPSELECTOR_H_
#define MAPSELECTOR_H_

#include <SFML/Graphics.hpp>
#include <vector>
#include "Map.h"

class MapSelector {
public:
    MapSelector();

    void nextMap();
    void previousMap();
    Map& getSelectedMap();
    int getSelectedMapIndex();

private:
    Map map1;
    Map map2;
    Map map3;

    std::vector<Map> maps;
    int selectedMapIndex;
};

#endif // MAP_SELECTOR_H
*/