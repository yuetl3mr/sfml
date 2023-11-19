#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <windows.h>
#include <iostream>

using namespace sf;

int main() {
    RenderWindow window(VideoMode(900, 900), "Texture", Style::Close);
    HWND hwnd = window.getSystemHandle();
    LONG_PTR style = GetWindowLongPtr(hwnd, GWL_STYLE);
    style |= WS_BORDER;
    SetWindowLongPtr(hwnd, GWL_STYLE, style);

    Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        std::cout << "Error loading font file!" << std::endl;
        return EXIT_FAILURE;
    }

    Texture loginscrTexture;
    loginscrTexture.loadFromFile("../Texture/loginscr.jpg");
    Sprite loginScreen(loginscrTexture);
    
    Texture loginbtTexture;
    loginbtTexture.loadFromFile("../Texture/loginbutton.png");
    Sprite loginButton(loginbtTexture);
    loginButton.setPosition(385, 580); // Đặt vị trí cho button

    String userInput;
    Text userText("", font, 20);
    userText.setPosition(60, 300);
    userText.setFillColor(Color::White);


    while(window.isOpen()) {
        Event event;
        while(window.pollEvent(event)) {
            if(event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::TextEntered) {
                if (event.text.unicode < 128 && event.text.unicode != 8) {
                    userInput += event.text.unicode;
                    userText.setString(userInput);
                } else if (event.text.unicode == 8 && userInput.getSize() > 0) {
                    userInput.erase(userInput.getSize() - 1);
                    userText.setString(userInput);
                }
            }
            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    Vector2f mousePos = window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
                    if (loginButton.getGlobalBounds().contains(mousePos)) {
                        std::cout << "Login\n";
                    } else {
                        std::cout << "No\n";
                    }
                }
            }
        }
        
        sf::Text mousePositionText("", font, 20);
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

        std::string mousePositionString = "Mouse Position: (" + std::to_string(mousePosition.x) + ", " + std::to_string(mousePosition.y) + ")";
        mousePositionText.setString(mousePositionString);


        window.clear();
        window.draw(loginScreen);
        //window.draw(mousePositionText);
        window.draw(loginButton); 
        window.display();
    }
    return 0;
}
