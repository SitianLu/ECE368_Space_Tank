//
// Created by Luris on 4/24/16.
//

#include "End_Menu.h"
#include <SFML/Audio.hpp>


void End_menu(int turn, sf::Font* font) {

    sf::Music EndMusic;
    EndMusic.openFromFile("Sound/end01.wav");
    EndMusic.play();

    sf::RenderWindow window;
    sf::Sprite Menu;
    sf::Texture MenuTexture;
    sf::Text statement;
    sf::Event MenuEvent;


    statement.setFont(*font);
    statement.setCharacterSize(80);
    statement.setStyle(sf::Text::Bold);
    statement.setString("Player " + std::to_string(turn + 1) + "  wins the battle!!");
    statement.setColor(sf::Color::Red);
    statement.setPosition(200, 100);

    if (!MenuTexture.loadFromFile("sprites/End_Menu.png")) {
        printf("Load error: Can not load Ending menu image");
    }

    Menu.setTexture(MenuTexture);
    window.create(sf::VideoMode(1400, 800), "Victory", sf::Style::Default);
    window.setActive();

    while (window.isOpen()) {
        while (window.pollEvent(MenuEvent)) {
            window.draw(Menu);
            window.display();

            if (MenuEvent.KeyPressed) {
                if (MenuEvent.key.code == sf::Keyboard::Space) {
                    EndMusic.stop();
                    window.close();
                    break;
                }
            }
            if (MenuEvent.type == sf::Event::Closed) {
                window.close();
                EndMusic.stop();
                break;
            }
        }

        window.draw(Menu);
        window.draw(statement);
        window.display();

    }
}

