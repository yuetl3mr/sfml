#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 400), "SFML!", sf::Style::Close | sf::Style::Resize);
    window.setFramerateLimit(60);

    while (window.isOpen())
    {   
        Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed){
                if(event.key.scancode == sf::Keyboard::Scan::Enter){
                    // do sth
                    window.close();
                }
                if (Keyboard::isKeyPressed(Keyboard::Space)){
                    window.close();
                }
            }
        }
        window.clear();
        window.display();
    }

    return 0;
}