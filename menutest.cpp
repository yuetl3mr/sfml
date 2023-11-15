#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Library Management System Menu");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font file!" << std::endl;
        return EXIT_FAILURE;
    }

    const int MENU_ITEMS = 3;
    sf::Text menu[MENU_ITEMS];

    menu[0].setFont(font);
    menu[0].setCharacterSize(24);
    menu[0].setFillColor(sf::Color::White);
    menu[0].setString("1. Add Book");
    menu[0].setPosition(sf::Vector2f(100, 100));

    menu[1].setFont(font);
    menu[1].setCharacterSize(24);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("2. Remove Book");
    menu[1].setPosition(sf::Vector2f(100, 150));

    menu[2].setFont(font);
    menu[2].setCharacterSize(24);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("3. Exit");
    menu[2].setPosition(sf::Vector2f(100, 200));

    int selectedItemIndex = 0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    if (selectedItemIndex > 0)
                        selectedItemIndex--;
                } else if (event.key.code == sf::Keyboard::Down) {
                    if (selectedItemIndex < MENU_ITEMS - 1)
                        selectedItemIndex++;
                } else if (event.key.code == sf::Keyboard::Return) {
                    // Xử lý lựa chọn được chọn
                    switch (selectedItemIndex) {
                        case 0:
                            // Xử lý chức năng thêm sách
                            std::cout << "Add Book selected" << std::endl;
                            break;
                        case 1:
                            // Xử lý chức năng xóa sách
                            std::cout << "Remove Book selected" << std::endl;
                            break;
                        case 2:
                            // Thoát chương trình
                            window.close();
                            break;
                    }
                }
            }
        }

        // Cập nhật màu sắc của các lựa chọn
        for (int i = 0; i < MENU_ITEMS; ++i) {
            if (i == selectedItemIndex) {
                menu[i].setFillColor(sf::Color::Red);
            } else {
                menu[i].setFillColor(sf::Color::White);
            }
        }

        window.clear();

        // Vẽ menu lên cửa sổ
        for (int i = 0; i < MENU_ITEMS; ++i) {
            window.draw(menu[i]);
        }

        window.display();
    }

    return 0;
}
