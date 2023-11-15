#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 400), "SFML!", sf::Style::Close | sf::Style::Resize);
    window.setFramerateLimit(60);
    //sf::Circletriangle triangle(50.f);

    sf::CircleShape triangle(10.f);
    triangle.sf::CircleShape::setRadius(50.f);
    triangle.sf::CircleShape::setPointCount(4);
    triangle.setOutlineThickness(5.f);
    triangle.setOutlineColor(sf::Color::Cyan);
    triangle.move(500.f,0.0f);
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
                triangle.rotate(45.f);
            if (event.type == sf::Event::MouseButtonReleased)
                window.close();
                
        }

        // Update
        window.clear();
        //triangle.move(0.5f, 0.5f);
        //triangle.rotate(0.5f);
        window.draw(triangle);
        window.display();
    }
    return 0;
}