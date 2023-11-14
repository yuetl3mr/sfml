#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 400), "SFML!", sf::Style::Close | sf::Style::Resize);
    window.setFramerateLimit(60);
    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color::Blue);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
                window.close();
        }
        // Update
            shape.move(0.1f, 0.1f);
        window.clear(sf::Color::Red);
        window.draw(shape);
        window.display();
        // Draw
    }
    return 0;
}