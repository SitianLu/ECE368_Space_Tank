//
//  Menu.cpp
//  test2
//
//  Created by Maxim Baldakov on 3/24/16.
//  Copyright (c) 2016 Maxim Baldakov. All rights reserved.
//

#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "bullet_object.h"
#include <iostream>
#include <sstream>


GameSettings StartMenu() {
	GameSettings Settings;
	Settings.Player1 = "5";
	Settings.Player2 = "4";
	Settings.Map = 1;

	sf::Music MenuMusic;
	MenuMusic.openFromFile("Sound/MainMenu.wav");
	MenuMusic.play();

	sf::Music Click;
	Click.openFromFile("Sound/shot01.wav");

	sf::RectangleShape rectangle(sf::Vector2f(320, 170));
	rectangle.setFillColor(sf::Color(100, 250, 50));
	rectangle.setPosition(490, 410);

	sf::Sprite Map1;
	sf::Sprite Map2;
	sf::Sprite Map3;
	sf::Texture Map1TX;
	sf::Texture Map2TX;
	sf::Texture Map3TX;
	Map1TX.loadFromFile("sprites/Menu/Map1.jpg");
	Map2TX.loadFromFile("sprites/Menu/Map2.jpg");
	Map3TX.loadFromFile("sprites/Menu/Map3.jpg");
	Map1.setTexture(Map1TX);
	Map2.setTexture(Map2TX);
	Map3.setTexture(Map3TX);
	Map1.setPosition(500, 420);
	Map2.setPosition(1000, 420);
	Map3.setPosition(730, 620);

	sf::RenderWindow window;
	sf::Sprite Menu;
	sf::Texture MenuTexture;
	sf::Sprite PlayButton;
	sf::Texture PlayButtonTexture;
	if (!MenuTexture.loadFromFile("sprites/Menu/Menu.jpg")) {
		printf("Load error: Can not load Menu image");
	}
	if (!PlayButtonTexture.loadFromFile("sprites/Menu/StartButton.png")) {
		printf("Load error: Can not load Menu image");
	}

	Menu.setTexture(MenuTexture);
	PlayButton.setTexture(PlayButtonTexture);
	PlayButton.setPosition(800, 170);

	sf::Texture Player1Container; 
	sf::Texture Player2Container;
	Player1Container.loadFromFile("sprites/Menu/Container1.png");
	Player2Container.loadFromFile("sprites/Menu/Container2.png");
	sf::Sprite Player1;
	sf::Sprite Player2;
	Player1.setTexture(Player1Container);
	Player2.setTexture(Player2Container);
	Player1.setPosition(100, 200);
	Player2.setPosition(1400, 200);

	sf::Sprite Player1Red;
	sf::Sprite Player1Blue;
	sf::Sprite Player1Yellow;
	sf::Texture Player1RedTexture;
	sf::Texture Player1BlueTexture;
	sf::Texture Player1YellowTexture;
	sf::Texture Player1RedPR;
	sf::Texture Player1BluePR;
	sf::Texture Player1YellowPR;
	Player1RedTexture.loadFromFile("sprites/Menu/RedButton.png");
	Player1BlueTexture.loadFromFile("sprites/Menu/BlueButton.png");
	Player1YellowTexture.loadFromFile("sprites/Menu/YellowButton.png");
	Player1RedPR.loadFromFile("sprites/Menu/Red_pr.png");
	Player1BluePR.loadFromFile("sprites/Menu/Blue_pr.png");
	Player1YellowPR.loadFromFile("sprites/Menu/Yellow_pr.png");
	Player1Red.setTexture(Player1RedTexture);
	Player1Blue.setTexture(Player1BlueTexture);
	Player1Yellow.setTexture(Player1YellowTexture);
	Player1Red.setPosition(150, 320);
	Player1Blue.setPosition(150, 400);
	Player1Yellow.setPosition(150, 480);

	sf::Sprite Player2Red;
	sf::Sprite Player2Blue;
	sf::Sprite Player2Yellow;
	sf::Texture Player2RedTexture;
	sf::Texture Player2BlueTexture;
	sf::Texture Player2YellowTexture;
	sf::Texture Player2RedPR;
	sf::Texture Player2BluePR;
	sf::Texture Player2YellowPR;
	Player2RedTexture.loadFromFile("sprites/Menu/RedButton.png");
	Player2BlueTexture.loadFromFile("sprites/Menu/BlueButton.png");
	Player2YellowTexture.loadFromFile("sprites/Menu/YellowButton.png");
	Player2RedPR.loadFromFile("sprites/Menu/Red_pr.png");
	Player2BluePR.loadFromFile("sprites/Menu/Blue_pr.png");
	Player2YellowPR.loadFromFile("sprites/Menu/Yellow_pr.png");
	Player2Red.setTexture(Player2RedTexture);
	Player2Blue.setTexture(Player2BlueTexture);
	Player2Yellow.setTexture(Player2YellowTexture);
	Player2Red.setPosition(1450, 320);
	Player2Blue.setPosition(1450, 400);
	Player2Yellow.setPosition(1450, 480);

	window.create(sf::VideoMode(1800, 800), "Menu", sf::Style::Default);
	window.setActive();
	sf::Event MenuEvent;
	while (window.isOpen()) {
		while (window.pollEvent(MenuEvent)) {
			if (MenuEvent.KeyPressed) {
				if (MenuEvent.key.code == sf::Keyboard::Space) {
					MenuMusic.stop();
					window.close();
					return Settings;
				}
			}
			if (MenuEvent.type == sf::Event::MouseButtonPressed) {
				Click.play();
				std::cout << "Left Button Pressed at X:" << MenuEvent.mouseButton.x << "  Y:" << MenuEvent.mouseButton.y << std::endl;
				if (MenuEvent.mouseButton.x > 800 && MenuEvent.mouseButton.x < 1000 && MenuEvent.mouseButton.y > 170 && MenuEvent.mouseButton.y < 220) {
					printf("StartGame");
					window.close();
					MenuMusic.stop();
					Click.stop();
					return Settings;
				}
				else if (MenuEvent.mouseButton.x > 150 && MenuEvent.mouseButton.x < 350 && MenuEvent.mouseButton.y > 320 && MenuEvent.mouseButton.y < 370) {
					printf("Player1Red/n");
					Settings.Player1 = "4";
					Player1Red.setTexture(Player1RedPR);
					Player1Blue.setTexture(Player1BlueTexture);
					Player1Yellow.setTexture(Player1YellowTexture);
				}
				else if (MenuEvent.mouseButton.x > 150 && MenuEvent.mouseButton.x < 350 && MenuEvent.mouseButton.y > 400 && MenuEvent.mouseButton.y < 450) {
					printf("Player1Blue/n");
					Settings.Player1 = "5";
					Player1Blue.setTexture(Player1BluePR);
					Player1Red.setTexture(Player1RedTexture);
					Player1Yellow.setTexture(Player1YellowTexture);
				}
				else if (MenuEvent.mouseButton.x > 150 && MenuEvent.mouseButton.x < 350 && MenuEvent.mouseButton.y > 480 && MenuEvent.mouseButton.y < 530) {
					printf("Player1Yellow/n");
					Settings.Player1 = "3";
					Player1Yellow.setTexture(Player1YellowPR);
					Player1Red.setTexture(Player1RedTexture);
					Player1Blue.setTexture(Player1BlueTexture);
				}
				else if (MenuEvent.mouseButton.x > 1450 && MenuEvent.mouseButton.x < 1650 && MenuEvent.mouseButton.y > 320 && MenuEvent.mouseButton.y < 370) {
					printf("Player2Yellow/n");
					Settings.Player2 = "4";
					Player2Red.setTexture(Player2RedPR);
					Player2Blue.setTexture(Player2BlueTexture);
					Player2Yellow.setTexture(Player2YellowTexture);
				}
				else if (MenuEvent.mouseButton.x > 1450 && MenuEvent.mouseButton.x < 1650 && MenuEvent.mouseButton.y > 400 && MenuEvent.mouseButton.y < 450) {
					printf("Player2Red/n");
					Settings.Player2 = "5";
					Player2Red.setTexture(Player2RedTexture);
					Player2Blue.setTexture(Player2BluePR);
					Player2Yellow.setTexture(Player2YellowTexture);
				}
				else if (MenuEvent.mouseButton.x > 1450 && MenuEvent.mouseButton.x < 1650 && MenuEvent.mouseButton.y > 480 && MenuEvent.mouseButton.y < 530) {
					printf("Player2Blue/n");
					Settings.Player2 = "3";
					Player2Red.setTexture(Player2RedTexture);
					Player2Blue.setTexture(Player2BlueTexture);
					Player2Yellow.setTexture(Player2YellowPR);
				}
				else if (MenuEvent.mouseButton.x > 500 && MenuEvent.mouseButton.x < 800 && MenuEvent.mouseButton.y > 420 && MenuEvent.mouseButton.y < 570) {
					printf("Map1");
					rectangle.setPosition(490, 410);
					Settings.Map = 1;
				}
				else if (MenuEvent.mouseButton.x > 1000 && MenuEvent.mouseButton.x < 1300 && MenuEvent.mouseButton.y > 420 && MenuEvent.mouseButton.y < 570) {
					printf("Map2");
					rectangle.setPosition(990, 410);
					Settings.Map = 2;
				}
				else if (MenuEvent.mouseButton.x > 730 && MenuEvent.mouseButton.x < 1030 && MenuEvent.mouseButton.y > 620 && MenuEvent.mouseButton.y < 770) {
					printf("Map3");
					rectangle.setPosition(720, 610);
					Settings.Map = 3;
				}
			}
			window.draw(Menu);
			window.draw(PlayButton);
			window.draw(Player1);
			window.draw(Player2);
			window.draw(Player1Red);
			window.draw(Player1Blue);
			window.draw(Player1Yellow);
			window.draw(Player2Red);
			window.draw(Player2Blue);
			window.draw(Player2Yellow);
			window.draw(rectangle);
			window.draw(Map1);
			window.draw(Map2);
			window.draw(Map3);
			window.display();
			if (MenuEvent.type == sf::Event::Closed) {
				window.clear();
				window.close();
				MenuMusic.stop();
				Click.stop();
				return Settings;
			}
		}
	}
}