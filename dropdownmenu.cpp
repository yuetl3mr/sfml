#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

const float MENU_SPEED = 5.0f;

int main() {
    sf::RenderWindow window(sf::VideoMode(200, 200), "Dropdown Menu");

    bool isMenuOpen = false;
    bool isMenuMoving = false;
    float menuHeight = 0.0f;
    float targetHeight = 0.0f;
    sf::Clock clock;

    std::vector<sf::Text> menuItems;

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Font file not found!" << std::endl;
        return -1;
    }

    sf::Text selectedItem;
    selectedItem.setFont(font);
    selectedItem.setCharacterSize(20);
    selectedItem.setFillColor(sf::Color::White);
    selectedItem.setString("Select an option");

    // Create menu items
    for (char c = 'A'; c <= 'D'; ++c) {
        sf::Text menuItem;
        menuItem.setFont(font);
        menuItem.setCharacterSize(20);
        menuItem.setFillColor(sf::Color::White);
        menuItem.setString(std::string(1, c));
        menuItem.setPosition(0, 30 * (c - 'A' + 1));
        menuItems.push_back(menuItem);
    }

    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                    // Toggle menu open/close
                    if (selectedItem.getGlobalBounds().contains(mousePos)) {
                        isMenuOpen = !isMenuOpen;
                        isMenuMoving = true;
                        if (isMenuOpen) {
                            targetHeight = static_cast<float>(menuItems.size() * 30);
                        } else {
                            targetHeight = 0.0f;
                        }
                    }

                    // Handle item selection
                    if (isMenuOpen && !isMenuMoving) {
                        for (size_t i = 0; i < menuItems.size(); ++i) {
                            if (menuItems[i].getGlobalBounds().contains(mousePos)) {
                                selectedItem.setString(menuItems[i].getString());
                                isMenuOpen = false;
                                targetHeight = 0.0f;
                                isMenuMoving = true;
                                break;
                            }
                        }
                    }
                }
            }
        }

        if (isMenuMoving) {
            float distance = targetHeight - menuHeight;
            if (std::abs(distance) > 1.0f) {
                menuHeight += distance * MENU_SPEED * deltaTime.asSeconds();
            } else {
                menuHeight = targetHeight;
                isMenuMoving = false;
            }
        }

        window.clear(sf::Color::Black);

        // Draw selected item
        selectedItem.setPosition(0, 0);
        window.draw(selectedItem);

        // Draw menu items
        for (size_t i = 0; i < menuItems.size(); ++i) {
            menuItems[i].setPosition(0, 30 * (i + 1) + menuHeight);
            window.draw(menuItems[i]);
        }

        window.display();
    }

    return 0;
}
