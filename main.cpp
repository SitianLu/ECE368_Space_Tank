
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
	//Initialization for Global use variables
	sf::Font hp_font;
	sf::Texture Bullet_Texture;
	sf::Texture Explosion_Texture;
	Bullet* bullet_current = NULL;
	Planet_list planet_list;
	sf::Clock clock;
	bool bulletFired = false;
	float power = 10.f;
	int index = 0;
	float frameCounter = 0, switchFrame = 10, frameSpeed = 500;


	if (!hp_font.loadFromFile("Word_font/OpenSans-Regular.ttf")) {
		std::cout << "Error could not load font" << std::endl;
	}

	if (!Bullet_Texture.loadFromFile("sprites/missile/missile_2_no_margin.png"))
	{
		std::cout << "Error could not load bullet image" << std::endl;
	}

	if (!Explosion_Texture.loadFromFile("sprites/explosions/explosion_1fix.png"))
	{
		std::cout << "Error could not load explosion image" << std::endl;
	}

	//Build the window/map/background
	map map1(1800, 800, "Space Tank");

	Planet planet1(500, 500, 2000000, 150, "sprites/planets/red.png");
	Planet planet2(900, 400, 2000000, 150, "sprites/planets/earth.png");
	Planet planet3(1500, 500, 2000000, 200, "sprites/planets/pink.png");

	planet_list.addPlanet(&planet1);
	planet_list.addPlanet(&planet2);
	planet_list.addPlanet(&planet3);

	Tank tank1(&planet1, "sprites/tanks/tank3.png", &hp_font);
	Tank tank2(&planet3, "sprites/tanks/tank3.png", &hp_font);
	Barrel barrel1(&tank1, "sprites/tanks/barrel3.png", "sprites/explosions/smoke_140_64.png");
	Barrel barrel2(&tank2, "sprites/tanks/barrel3.png", "sprites/explosions/smoke_140_64.png");



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

					if (Event.key.code == sf::Keyboard::Down)
					{
						if (barrel1.limitation > -6) {
							barrel1.rotation += -1;
							barrel1.limitation += -1;
							barrel1.shape.rotate((float)-1.0);
						}
					}

					if (Event.key.code == sf::Keyboard::Up)
					{
						if (barrel1.limitation < 178) {
							barrel1.rotation += 1;
							barrel1.limitation += 1;
							barrel1.shape.rotate(1.0);
						}
					}

					if (Event.key.code == sf::Keyboard::Right)
					{
                        if (!bulletFired) {
                            tank1.Move_Clock(0.05);
                            barrel1.Move_Clock(0.05);
                        }
					}

					if (Event.key.code == sf::Keyboard::Left)
					{
                        if (!bulletFired) {
                            tank1.Move_ConterClock(0.05);
                            barrel1.Move_ConterClock(0.05);
                        }
					}
					if (Event.key.code == sf::Keyboard::Space)
					{
						if (!bulletFired) {

							barrel1.setSmokePosition(barrel1.getLaunchPoint().x, barrel1.getLaunchPoint().y);
							barrel1.smokeSpriteCounter = 0;

							bullet_current = new Bullet(barrel1.getLaunchPoint(), 10, barrel1.getInitialDirection() * power, &Bullet_Texture, &Explosion_Texture);
							bullet_current->setDamage(BULLET_DAMAGE);

							power = 5.f;

							bulletFired = true;
						}
					}
					if (Event.key.code == sf::Keyboard::Return) {

						if (power <= 100) {

							power += 5.f;

							std::cout << "Power: " << power << std::endl;

						}
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

				// Barrel Smoke Animation
				if (barrel1.smokeSpriteCounter <= 16) {

					barrel1.smoke_shape.setTextureRect(sf::IntRect(barrel1.smokeSpriteCounter * 140, 0, 140, 64));
					barrel1.smokeSpriteCounter++;
				}

				// Bullet Animation
				bullet_current->collision_detect(&tank1, planet_list.head, &map1);

				if (!(bullet_current->explosion_detected)) {

					bullet_current->inc_bullet(planet_list.head);
					bullet_current->bulletSpriteCounter++;
					bullet_current->bulletSpriteCounter %= 4;
					bullet_current->bullet_shape.setTextureRect(sf::IntRect(bullet_current->bulletSpriteCounter * 60, 0, 60, 15));

				}
				else if (bullet_current->explosionSpriteCounter <= 16) {

					//std::cout << "Collision Detected!!" << std::endl;
					bullet_current->explosion_shape.setTextureRect(sf::IntRect(bullet_current->explosionSpriteCounter * 65, 0, 65, 65));
					bullet_current->explosionSpriteCounter++;

					if (bullet_current->explosionSpriteCounter == 1) {
						if (bullet_current->tankHit)
						{
							tank1.updateHP_Text();
							std::cout << "got hit tank hp: " << tank1.getHp() << std::endl;

						}
					}
				}
			}
		}

		map1.window.draw(map1.background);
		map1.window.draw(planet1.shape);
		map1.window.draw(planet2.shape);
		map1.window.draw(planet3.shape);
		map1.window.draw(barrel1.shape);
		map1.window.draw(tank1.shape);
		map1.window.draw(tank1.text);
		map1.window.draw(barrel2.shape);
		map1.window.draw(tank2.shape);
		map1.window.draw(tank2.text);

		if (bulletFired) {
			if (barrel1.smokeSpriteCounter <= 16)
			{
				map1.window.draw(barrel1.smoke_shape);
			}
			if ((bullet_current->explosion_detected) && (bullet_current->explosionSpriteCounter <= 16)) {
				map1.window.draw(bullet_current->explosion_shape);
			}
			else if (!bullet_current->explosion_detected) {
				map1.window.draw(bullet_current->bullet_shape);
			}
			else { //If the explosion ends
				bulletFired = false;
				delete(bullet_current);
			}
		}

		map1.window.display();
		map1.window.clear();
	}


}
