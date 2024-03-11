#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <iostream>
#include <memory>
#include <vector>
#include <ctime>

#include "Inputs.h"
#include "Game.h"
#include "Map.h"
#include "Loader.h"
#include "MapSelection.h"

#define WINDOWS_WIDTH 400
#define WINDOWS_HEIGHT 800


int main() {
    sf::Texture mapSelectionTexture;
    mapSelectionTexture.loadFromFile("resources/Selection_de_niveau.png");
    sf::Sprite mapSelectionSprite(mapSelectionTexture);
    mapSelectionSprite.setPosition(WINDOWS_WIDTH / 2 - mapSelectionTexture.getSize().x / 2, 600);
    
    sf::Texture quitTexture;
    quitTexture.loadFromFile("resources/quitButton.png");
    sf::Sprite quitSprite(quitTexture);
    quitSprite.setPosition(WINDOWS_WIDTH / 2 - quitTexture.getSize().x / 2, 700);


    sf::Texture homeBackgroundTexture;
    homeBackgroundTexture.loadFromFile("resources/Background_menu_principal.png");
    sf::Sprite homeBackgroundSprite(homeBackgroundTexture);
    homeBackgroundSprite.setPosition(0, 0);

    sf::Texture MapSelectionBackgroundTexture;
    MapSelectionBackgroundTexture.loadFromFile("resources/Background_selection_map.png");
    sf::Sprite MapSelectionBackgroundSprite(MapSelectionBackgroundTexture);
    MapSelectionBackgroundSprite.setPosition(0, 0);

    sf::Texture PauseBackgroundTexture;
    PauseBackgroundTexture.loadFromFile("resources/Background_pause.png");
    sf::Sprite PauseBackgroundSprite(PauseBackgroundTexture);
    PauseBackgroundSprite.setPosition(0, 0);

    sf::Texture resumeTexture;
    resumeTexture.loadFromFile("resources/resumebutton.png");
    sf::Sprite resumeSprite(resumeTexture);
    resumeSprite.setPosition(WINDOWS_WIDTH / 2 - resumeTexture.getSize().x / 2, 300);

    sf::Texture mainMenuTexture;
    mainMenuTexture.loadFromFile("resources/mainmenubutton.png");
    sf::Sprite mainMenuSprite(mainMenuTexture);
    mainMenuSprite.setPosition(WINDOWS_WIDTH / 2 - mainMenuTexture.getSize().x / 2, 400);


    sf::Texture button1Texture;
    button1Texture.loadFromFile("resources/1.png");
    sf::Sprite button1Sprite(button1Texture);
    button1Sprite.setPosition(50, 100);
    sf::Texture button2Texture;
    button2Texture.loadFromFile("resources/2.png");
    sf::Sprite button2Sprite(button2Texture);
    button2Sprite.setPosition(150, 100);
    sf::Texture button3Texture;
    button3Texture.loadFromFile("resources/3.png");
    sf::Sprite button3Sprite(button3Texture);
    button3Sprite.setPosition(250, 100);
    
    sf::Texture map1Texture;
    map1Texture.loadFromFile("resources/map1.png");
    sf::Sprite map1Sprite(map1Texture);
    map1Sprite.setPosition(WINDOWS_WIDTH / 2 - map1Texture.getSize().x / 2, 200);
    sf::Texture map2Texture;
    map2Texture.loadFromFile("resources/map2.png");
    sf::Sprite map2Sprite(map2Texture);
    map2Sprite.setPosition(WINDOWS_WIDTH / 2 - map2Texture.getSize().x / 2, 200);
    sf::Texture map3Texture;
    map3Texture.loadFromFile("resources/map3.png");
    sf::Sprite map3Sprite(map3Texture);
    map3Sprite.setPosition(WINDOWS_WIDTH / 2 - map3Texture.getSize().x / 2, 200);
    srand(time(0));
    
    sf::RenderWindow window(sf::VideoMode(WINDOWS_WIDTH, WINDOWS_HEIGHT), "Flipper");
    sf::Clock clock;
    Inputs inputs;
    MenuState menuState = MenuState::MainMenu;

    // on crée la map
    Map map;
    Loader::load_map_1(map);
    MapSelection MapSelected;
    // load map
    Game game(std::move(map));
    while (window.isOpen()) {

    sf::Vector2i mousePosition = inputs.mousePosition;
    sf::Vector2i mousePositionClicked = inputs.mousePositionClicked;



  

      float dt = clock.restart().asSeconds();;
      
      window.clear(sf::Color::Black);
      inputs.update(window);
     switch (menuState) {
        case MenuState::GameRunning:
            game.update(window, inputs, dt);
            if(inputs.escape){
                menuState = MenuState::GameMenu;   
            }
            break;
        case MenuState::MainMenu:
            window.draw(homeBackgroundSprite);
            window.draw(mapSelectionSprite);
            window.draw(quitSprite);
            game.kill_ball();
            game.reset();
            if (quitSprite.getGlobalBounds().contains(sf::Vector2f(mousePositionClicked.x, mousePositionClicked.y))) {
                    window.close();
                } else if (mapSelectionSprite.getGlobalBounds().contains(sf::Vector2f(mousePositionClicked.x, mousePositionClicked.y))) {
                    menuState = MenuState::MapSelection;
                }
            break;
        case MenuState::GameMenu:
            window.draw(PauseBackgroundSprite);
            window.draw(resumeSprite);
            window.draw(mainMenuSprite);
            if (resumeSprite.getGlobalBounds().contains(sf::Vector2f(mousePositionClicked.x, mousePositionClicked.y))) {
                    menuState = MenuState::GameRunning;
            } else if (mainMenuSprite.getGlobalBounds().contains(sf::Vector2f(mousePositionClicked.x, mousePositionClicked.y))) {
                menuState = MenuState::MainMenu;
            }
            break;

        case MenuState::MapSelection:
            window.draw(MapSelectionBackgroundSprite);
            window.draw(button1Sprite);
            window.draw(button2Sprite);
            window.draw(button3Sprite);
            if (button1Sprite.getGlobalBounds().contains(sf::Vector2f(mousePosition.x, mousePosition.y))) {
                window.draw(map1Sprite);
            } else if(button2Sprite.getGlobalBounds().contains(sf::Vector2f(mousePosition.x, mousePosition.y))){
                window.draw(map2Sprite);
            }else if(button3Sprite.getGlobalBounds().contains(sf::Vector2f(mousePosition.x, mousePosition.y))){
                window.draw(map3Sprite);
            }
            if (button1Sprite.getGlobalBounds().contains(sf::Vector2f(mousePositionClicked.x, mousePositionClicked.y))) {
                MapSelected =  MapSelection::Map1;    
            } else if (button2Sprite.getGlobalBounds().contains(sf::Vector2f(mousePositionClicked.x, mousePositionClicked.y))) {
                MapSelected =  MapSelection::Map2;
            } else if (button3Sprite.getGlobalBounds().contains(sf::Vector2f(mousePositionClicked.x, mousePositionClicked.y))) {
               MapSelected =  MapSelection::Map3;
            }
                switch (MapSelected) {
                    case MapSelection::Map1:
                        Loader::load_map_1(map);
                        game.set_map(std::move(map));
                        menuState = MenuState::GameRunning;
                        MapSelected=MapSelection::None;
                        break;
                    case MapSelection::Map2:
                        Loader::load_map_2(map);
                        game.set_map(std::move(map));
                        menuState = MenuState::GameRunning;
                        MapSelected=MapSelection::None;
                        break;
                    case MapSelection::Map3:
                        Loader::load_map_3(map);
                        game.set_map(std::move(map));
                        menuState = MenuState::GameRunning;
                        MapSelected=MapSelection::None;
                        break;
                    default:
                        break;
                }
            break;

        default:
          break;
      }
      window.display();
    }

    return 0;
}
