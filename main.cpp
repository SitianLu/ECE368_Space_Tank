
#include <SFML/Graphics.hpp>
#include <iostream>
#include "bullet_object.h"
#include "map_object.h"
#include "Planet_list.h"
//#include "Tank_object.h"
#include "Barrel_object.h"
#include "Global_constant.h"
#include <string>
#include <math.h>

int main()
{

	//Build the window/map/background
	map map1(1800, 800, "Space Tank");

	Planet planet1(500,500,2000000,150,"sprites/planets/red.png");
	Planet planet2(900, 400, 2000000, 150, "sprites/planets/earth.png");
	Planet planet3(1500,500,2000000,200,"sprites/planets/pink.png");

	Tank tank1(&planet1, "sprites/tanks/tank3.png");
	Barrel barrel1(&tank1, "sprites/tanks/barrel3.png");

	//Defined Global use of Bullet Texture and Explosion Texture
	sf::Texture Bullet_Texture;
	sf::Texture Explosion_Texture;

	if (!Bullet_Texture.loadFromFile("sprites/missile/missile_2_no_margin.png"))
	{
		std::cout << "Error could not load bullet image" << std::endl;
	}

	if (!Explosion_Texture.loadFromFile("sprites/explosions/explosion_1fix.png"))
	{
		std::cout << "Error could not load bullet image" << std::endl;
	}
	//////////

	Bullet* bullet_current = NULL;

	sf::Vector2f speed(-40, 20);


	Planet_list planet_list;

	planet_list.addPlanet(&planet1);
	planet_list.addPlanet(&planet2);
	planet_list.addPlanet(&planet3);


	enum Direction { Down, Left, Right, Up };
	float frameCounter = 0, switchFrame = 10, frameSpeed = 500;
	sf::Vector2i source(1, Down); //Tell where the animation start


	int bulletSpriteCounter = 0;
	int explosionSpriteCounter = 0;
	bool bulletFired = false;


	sf::Clock clock;
	sf::Time time;
	int index = 0;


	while (map1.window.isOpen()) {
		sf::Event Event;

		while (map1.window.pollEvent(Event)) {

			map1.window.setKeyRepeatEnabled(true);

			switch (Event.type) {

				case sf::Event::Closed: {
					map1.window.close();
					break;
				}

				case sf::Event::KeyPressed: {

					if ((Event.key.code == sf::Keyboard::Down) && (barrel1.rotation >= -3))
					{
						barrel1.rotation += -1;
						barrel1.shape.rotate((float)-1.0);
					}

					if ((Event.key.code == sf::Keyboard::Up) && (barrel1.rotation <= 65))
					{
						barrel1.rotation += 1;
						barrel1.shape.rotate(1.0);
					}

					if (Event.key.code == sf::Keyboard::Right)
					{
						tank1.Move_Clock(0.05);
						barrel1.Move_Clock(0.05);
					}

					if (Event.key.code == sf::Keyboard::Left)
					{
						tank1.Move_ConterClock(0.05);
						barrel1.Move_ConterClock(0.05);
					}
					if (Event.key.code == sf::Keyboard::Space)
					{
						explosionSpriteCounter = 0;

						if (bullet_current != NULL){
							delete(bullet_current);
						}

						bullet_current = new Bullet(700, 10, 10, speed, &Bullet_Texture, &Explosion_Texture);

						bulletFired = true;
					}
				}

				case sf::Event::MouseButtonPressed: {

					if (Event.mouseButton.button == sf::Mouse::Left)
					{
						std::cout << "Left Button Pressed at X:" << Event.mouseButton.x << "  Y:" << Event.mouseButton.y << std::endl;
					}
				}
			}

		}


		frameCounter += frameSpeed * clock.restart().asSeconds();
		if (frameCounter >= switchFrame) {
			frameCounter = 0;

			// Any Anomation update goes here
			planet1.shape.rotate(0.2);
			planet2.shape.rotate(1);

			if (bulletFired) {
				// Bullet Animation
				bullet_current->collision_detect(tank1, barrel1, planet_list.head);

				if (!(bullet_current->explosion_detected)) {

					bullet_current->inc_bullet(planet_list.head);
					bulletSpriteCounter++;
					bulletSpriteCounter %= 4;
					bullet_current->bullet_shape.setTextureRect(sf::IntRect(bulletSpriteCounter * 60, 0, 60, 15));

				}
				else if (explosionSpriteCounter <= 16) {

					std::cout << "Collision Detected!!" << std::endl;
					bullet_current->explosion_shape.setTextureRect(sf::IntRect(explosionSpriteCounter * 65, 0, 65, 65));
					explosionSpriteCounter++;
				}
			}
		}

		map1.window.draw(map1.background);
		map1.window.draw(planet1.shape);
		map1.window.draw(planet2.shape);
		map1.window.draw(planet3.shape);
		map1.window.draw(barrel1.shape);
		map1.window.draw(tank1.shape);
		if (bulletFired) {
			if ((bullet_current->explosion_detected) && (bullet_current->explosion_detected <= 16)) {
				map1.window.draw(bullet_current->explosion_shape);
			}
			else if (!bullet_current->explosion_detected) {
				map1.window.draw(bullet_current->bullet_shape);
			}
			else { //If the explosion ends
				bulletFired = false;
			}
		}
		map1.window.display();
		map1.window.clear();
	}


}
