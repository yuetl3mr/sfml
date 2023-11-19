#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <bits/stdc++.h>
using namespace sf;

int main(){
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Texture", sf::Style::Close);
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        std::cout << "Error loading font file!" << std::endl;
        return EXIT_FAILURE;
    }
    sf::Texture pixelTexture;
    pixelTexture.loadFromFile("../Texture/PixelArtTutorial.png");
    sf::RectangleShape pixel(Vector2f(100.f, 100.f));
    pixel.setTexture(&pixelTexture);    
    sf::String userInput;
    sf::Text userText("", font, 20);
    userText.setPosition(60, 300);
    userText.setFillColor(Color::White);
    sf::Text isClicker("Yes", font, 20);
    isClicker.setPosition(90, 300);
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
            if (event.type == sf::Event::TextEntered){
                if (event.text.unicode < 128 && event.text.unicode != 8){
                    userInput +=event.text.unicode;
                    userText.setString(userInput);
                }else if (event.text.unicode == 8 && userInput.getSize() > 0){
                    userInput.erase(userInput.getSize() - 1);
                    userText.setString(userInput);
                }
            }
            if(event.type == Event::MouseButtonPressed){
                if (event.mouseButton.button == Mouse::Left){
                    Vector2f mousePos = window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));    
                    if (!pixel.getGlobalBounds().contains(mousePos)){
                        isClicker.setString("No");
                    } else isClicker.setString("Yes");
                }
            }
            
        }
        window.clear();
        window.draw(isClicker);
        window.draw(pixel);
        window.display();
    }
}