#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
//juste un test pour voir si SFML+Cmake marche
int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("resources/gragas_2.wav")){
         std::cerr << "Erreur lors du chargement du fichier audio" << std::endl;
        return 1;
    }
    
    sf::Sound sound;
    sound.setBuffer(buffer);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                // Jouer le son lorsque l'utilisateur clique
                sound.play();
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
