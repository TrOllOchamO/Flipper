/*#include "MapSelector.h"
#include "Loader.h"

MapSelector::MapSelector() : selectedMapIndex(0) {
    // Charger les cartes disponibles
    Loader::load_map_1(map1);
    Loader::load_map_2(map2);
    Loader::load_map_3(map3);

    // Ajouter les cartes à la liste des cartes disponibles
    maps.push_back(map1);
    maps.push_back(map2);
    maps.push_back(map3);
}

void MapSelector::nextMap() {
    selectedMapIndex = (selectedMapIndex + 1) % maps.size();
}

void MapSelector::previousMap() {
    selectedMapIndex = (selectedMapIndex + maps.size() - 1) % maps.size();
}

Map& MapSelector::getSelectedMap() {
    return maps[selectedMapIndex];
}

int MapSelector::getSelectedMapIndex() {
    return selectedMapIndex;
}
*/