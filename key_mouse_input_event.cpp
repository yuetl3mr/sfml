#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML!", sf::Style::Close | sf::Style::Resize);
    window.setFramerateLimit(60);

    // while (window.isOpen())
    // {   
    //     Event event;
    //     while(window.pollEvent(event)){
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //         if (event.type == sf::Event::KeyPressed){
    //             if(event.key.scancode == sf::Keyboard::Scan::Enter){
    //                 // do sth
    //                 window.close();
    //             }
    //             if (Keyboard::isKeyPressed(Keyboard::Space)){
    //                 window.close();
    //             }
    //         }
    //     }
    //     window.clear();
    //     window.display();
    // }

    sf::CircleShape triangle(10.f);
    triangle.sf::CircleShape::setRadius(50.f);
    triangle.sf::CircleShape::setPointCount(4);
    triangle.setOutlineThickness(5.f);
    triangle.setOutlineColor(sf::Color::Cyan);
    triangle.move(500.f,0.0f);

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return EXIT_FAILURE;
    }

    sf::Text mousePositionText("", font, 20);
    mousePositionText.setFillColor(sf::Color::White);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

        std::string mousePositionString = "Mouse Position: (" + std::to_string(mousePosition.x) + ", " + std::to_string(mousePosition.y) + ")";
        mousePositionText.setString(mousePositionString);

        window.clear();
        window.draw(mousePositionText);
        window.draw(triangle);
        window.display();
    }
    return 0;
}