#include "Inputs.h"
#define WINDOWS_WIDTH 400
#define WINDOWS_HEIGHT 800
#define LEFT_FLIPPER sf::Keyboard::Q
#define RIGHT_FLIPPER sf::Keyboard::D
#define DOWN_LAUNCHER sf::Keyboard::Up
#define UP_LAUNCHER sf::Keyboard::Down
#define ENTER_LAUNCHER sf::Keyboard::Enter
#define SPACE_LAUNCHER sf::Keyboard::Space


MenuState Inputs::update(sf::RenderWindow &window, MenuState &currentState) {
     sf::Texture mapSelectionTexture;
    mapSelectionTexture.loadFromFile("resources/Selection_de_niveau.png");
    sf::Sprite mapSelectionSprite(mapSelectionTexture);
    mapSelectionSprite.setPosition(WINDOWS_WIDTH / 2 - mapSelectionTexture.getSize().x / 2, 300);

     sf::Texture homeBackgroundTexture;
    homeBackgroundTexture.loadFromFile("resources/Home_Background.png");
    sf::Sprite homeBackgroundSprite(homeBackgroundTexture);
    homeBackgroundSprite.setPosition(0, 0);
    
    sf::Texture quitTexture;
    quitTexture.loadFromFile("resources/quitButton.png");
    sf::Sprite quitSprite(quitTexture);
    quitSprite.setPosition(WINDOWS_WIDTH / 2 - quitTexture.getSize().x / 2, 400);

    sf::Texture resumeTexture;
    resumeTexture.loadFromFile("resources/resumebutton.png");
    sf::Sprite resumeSprite(resumeTexture);
    resumeSprite.setPosition(WINDOWS_WIDTH / 2 - resumeTexture.getSize().x / 2, 300);

    sf::Texture mainMenuTexture;
    mainMenuTexture.loadFromFile("resources/mainmenubutton.png");
    sf::Sprite mainMenuSprite(mainMenuTexture);
    mainMenuSprite.setPosition(WINDOWS_WIDTH / 2 - mainMenuTexture.getSize().x / 2, 400);

    sf::Event event;
    if (currentState == MenuState::MainMenu){
        window.draw(homeBackgroundSprite);
        window.draw(mapSelectionSprite);
        window.draw(quitSprite);

    }else if(currentState == MenuState::GameMenu ){
        window.draw(resumeSprite);
        window.draw(mainMenuSprite);
    }
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed){
            window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (currentState == MenuState::MainMenu) {
                if (quitSprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                    window.close();
                } else if (mapSelectionSprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                    currentState = MenuState::MapSelection;
                }
            } else if (currentState == MenuState::GameMenu) {
                if (resumeSprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                    currentState = MenuState::GameRunning;
                } else if (mainMenuSprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                    currentState = MenuState::MainMenu;
                }
            }
        }
    
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        switch (event.type) {
            case sf::Event::KeyPressed:
                key_down(event.key.code);
                break;

            case sf::Event::KeyReleased:
                key_up(event.key.code);
                break;

            default:
                break;
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            if (currentState == MenuState::GameRunning) {
                return MenuState::GameMenu;
            }
        }
    }
    return currentState;
}



 MapSelection Inputs::MapSelector(sf::RenderWindow &window){
    sf::Texture button1Texture;
    button1Texture.loadFromFile("resources/1.png");
    sf::Sprite button1Sprite(button1Texture);
    button1Sprite.setPosition(50, 50);
    sf::Texture button2Texture;
    button2Texture.loadFromFile("resources/2.png");
    sf::Sprite button2Sprite(button2Texture);
    button2Sprite.setPosition(150, 50);
    sf::Texture button3Texture;
    button3Texture.loadFromFile("resources/3.png");
    sf::Sprite button3Sprite(button3Texture);
    button3Sprite.setPosition(250, 50);
    window.draw(button1Sprite);
    window.draw(button2Sprite);
    window.draw(button3Sprite);
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
    sf::Sprite spritehovered;
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    if (button1Sprite.getGlobalBounds().contains(sf::Vector2f(mousePosition.x, mousePosition.y))) {
        window.draw(map1Sprite);
    } else if(button2Sprite.getGlobalBounds().contains(sf::Vector2f(mousePosition.x, mousePosition.y))){
        window.draw(map2Sprite);
    }else if(button3Sprite.getGlobalBounds().contains(sf::Vector2f(mousePosition.x, mousePosition.y))){
        window.draw(map3Sprite);
    }
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (button1Sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                return MapSelection::Map1;    
            } else if (button2Sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                return MapSelection::Map2;
            } else if (button3Sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
               return MapSelection::Map3;
            }
        }   
           
    }
    return MapSelection::None;
}
void Inputs::key_down(sf::Keyboard::Key key){
    switch (key) {
        case LEFT_FLIPPER:
            left_flipper = true;
            break;

        case RIGHT_FLIPPER:
            right_flipper = true;
            break;

        case DOWN_LAUNCHER:
            down_launcher = true;
            break;

        case UP_LAUNCHER:
            up_launcher = true;
            break;

        case ENTER_LAUNCHER:
            enter_launcher = true;
            break;

        case SPACE_LAUNCHER:
            space_launcher = true;
            break;

        default:
            break;
    }
}

void Inputs::key_up(sf::Keyboard::Key key){
    switch (key) {
        case LEFT_FLIPPER:
            left_flipper = false;
            break;

        case RIGHT_FLIPPER:
            right_flipper = false;
            break;

        case DOWN_LAUNCHER:
            down_launcher = false;
            break;

        case UP_LAUNCHER:
            up_launcher  = false;
            break;

        case ENTER_LAUNCHER:
            enter_launcher = false;
            break;

        case SPACE_LAUNCHER:
            space_launcher = false;
            break;

        default:
            break;
    }
}
