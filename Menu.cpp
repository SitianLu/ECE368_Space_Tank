//
//  Menu.cpp
//  test2
//
//  Created by Maxim Baldakov on 4/24/16.
//  Copyright (c) 2016 Maxim Baldakov. All rights reserved.
//

#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

void StartMenu() {
	sf::Music MenuMusic;
	MenuMusic.openFromFile("Sound/MainMenu.wav");
	MenuMusic.play();

	sf::RenderWindow window;
	sf::Sprite Menu;
	sf::Texture MenuTexture;
	MenuTexture.loadFromFile("Sprites/Menu.jpg");
	if (!MenuTexture.loadFromFile("SpritesMenu.jpg")) {
		printf("Load error");
	}

	Menu.setTexture(MenuTexture);
	window.create(sf::VideoMode(1800, 1200), "Menu", sf::Style::Default);
	window.setActive();
	sf::Event MenuEvent;
	while (window.isOpen()) {
		while (window.pollEvent(MenuEvent)) {
			window.draw(Menu);
			window.display();
			if (MenuEvent.KeyPressed) {
				if (MenuEvent.key.code == sf::Keyboard::Space) {
					MenuMusic.stop();
					window.close();
				}
			}
		}
	}
}
