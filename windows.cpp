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

    sf::Vertex line[] = { Vertex(Vector2f(100.f, 400.f), Vector2f(100.f, 100.f)) };

    // create an empty shape
    sf::ConvexShape convex;

    convex.sf::ConvexShape::setPosition(Vector2f(400.f, 50.f));

    // resize it to 5 points
    convex.setPointCount(5);

    // define the points
    convex.setPoint(0, sf::Vector2f(0, 0));
    convex.setPoint(1, sf::Vector2f(150, 10));
    convex.setPoint(2, sf::Vector2f(120, 90));
    convex.setPoint(3, sf::Vector2f(30, 100));
    convex.setPoint(4, sf::Vector2f(0, 50));

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
        window.clear();
        triangle.move(0.5f, 0.5f);
        triangle.rotate(0.5f);
        window.draw(triangle);
        //window.draw(line, 2, sf::Lines);
        //window.draw(convex);
        window.display();
        // Draw
    }
    return 0;
}