#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

int main() {
    sf::RenderWindow window(sf::VideoMode(200, 200), "Dropdown Menu");

    bool isMenuOpen = false;
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
                    }

                    // Handle item selection
                    if (isMenuOpen) {
                        for (size_t i = 0; i < menuItems.size(); ++i) {
                            if (menuItems[i].getGlobalBounds().contains(mousePos)) {
                                selectedItem.setString(menuItems[i].getString());
                                isMenuOpen = false;
                                break;
                            }
                        }
                    }
                }
            }
        }

        window.clear(sf::Color::Black);

        window.draw(selectedItem);

        if (isMenuOpen) {
            for (const auto& item : menuItems) {
                window.draw(item);
            }
        }

        window.display();
    }

    return 0;
}
