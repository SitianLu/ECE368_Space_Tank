
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

	bool edge = false;

	//Build the window/map/background
	map map1(1800, 800, "Space Tank");

	Planet planet1(500,500,2000000,150,"sprites/planets/red.png");
	Planet planet2(900, 400, 2000000, 150, "sprites/planets/earth.png");
	//Planet planet3(1300,300,2000000,300,"sprites/planets/pink.png");

	Tank tank1(&planet1, "sprites/tanks/tank3.png");
	Barrel barrel1(&tank1, "sprites/tanks/barrel3.png");

	sf::Vector2f speed(-20, 20);
	Bullet bullet1(700, 10, 10, speed, "sprites/missile/missile_2_no_margin.png", "sprites/explosions/explosion_1fix.png");

	Planet_list planet_list;

	planet_list.addPlanet(&planet1);
	planet_list.addPlanet(&planet2);


	enum Direction { Down, Left, Right, Up };
	float frameCounter = 0, switchFrame = 10, frameSpeed = 500;
	sf::Vector2i source(1, Down); //Tell where the animation start


	int bulletSpriteCounter = 0;
	int explosionSpriteCounter = 0;
	bool bulletFired = false;


	sf::Clock clock;
	sf::Time time;
	int index = 0;


	while (map1.window.isOpen())
	{
		sf::Event Event;

		while (map1.window.pollEvent(Event))
		{
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
					bulletFired = true;
				}
			}

			case sf::Event::MouseButtonPressed:
			{
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

			// Bullet Animation
			bullet1.collision_detect(tank1, barrel1, planet_list.head);

			if (!bullet1.explosion_detected)
			{
				bullet1.inc_bullet(planet_list.head);
				bulletSpriteCounter++;
				bulletSpriteCounter %= 4;
				bullet1.bullet_shape.setTextureRect(sf::IntRect(bulletSpriteCounter * 60, 0, 60, 15));

			}
			else if (explosionSpriteCounter <= 16)
			{
				std::cout << "Collision Detected!!" << std::endl;
				bullet1.explosion_shape.setTextureRect(sf::IntRect(explosionSpriteCounter * 65, 0, 65, 65));
				explosionSpriteCounter++;
			}


		}

		map1.window.draw(map1.background);
		map1.window.draw(planet1.shape);
		map1.window.draw(planet2.shape);
		if ((bullet1.explosion_detected) && (bullet1.explosion_detected <= 16)) {
			map1.window.draw(bullet1.explosion_shape);
		}
		else if (!bullet1.explosion_detected) {
			map1.window.draw(bullet1.bullet_shape);
		}
		else {
			//draw nothing
		}
		map1.window.draw(barrel1.shape);
		map1.window.draw(tank1.shape);
		map1.window.display();
		map1.window.clear();
	}


}
