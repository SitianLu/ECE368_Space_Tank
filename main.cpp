
#include <SFML/Graphics.hpp>
#include <iostream>
#include "bullet_object.h"
#include "map_object.h"
#include "Tank_object.h"
#include "Barrel_object.h"
#include "Global_constant.h"
#include <string>
#include <math.h>
#include <vector>

bool collision_detect(std::vector<Bullet>b, Barrel barrel, Tank tank, Planet p);

int main()
{

	bool edge;
	map map1(1800, 800, "Space Tank");

	//Planet planet1(1,500,500,2000000,150,"sprites/planets/red.png");
	Planet planet2(2, 900, 400, 2000000, 150, "sprites/planets/earth.png");
	//Planet planet3(3,1300,300,2000000,300,"sprites/planets/pink.png");

	Tank tank1(&planet2, "sprites/tanks/tank3.png");
	Barrel barrel1(&tank1, "sprites/tanks/barrel3.png");

	sf::Vector2f speed(5, 57);
	Bullet bullet1(600, 400, 10, speed, "sprites/missile/missile_2_no_margin.png");
	std::vector<Bullet> b;
	b.push_back(bullet1);

	planet_node *head = new planet_node;
	head->value = &planet2;
	head->next = NULL;
	//head->next = new planet_node;
	//head->next->value = &planet1;
	//head->next->next = NULL;
	//head->next->next = new planet_node;
	//head->next->next->value = &planet3;
	//head->next->next->next = NULL;
	map1.head = head;





	enum Direction { Down, Left, Right, Up };
	float frameCounter = 0, switchFrame = 10, frameSpeed = 500;
	sf::Vector2i source(1, Down); //Tell where the animation start


	int bulletSpriteCounter = 0;
	bool bulletFired = false;


	sf::Clock clock;
	sf::Time time;
	int index = 0;

	barrel1.setTank(&tank1);


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

				if (Event.key.code == sf::Keyboard::Down)
				{
					barrel1.shape.rotate((float)-1.0);
				}

				if (Event.key.code == sf::Keyboard::Up)
				{
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
			planet2.shape.rotate(1);
			// Bullet Animation
			//bullet1.shape.rotate(1);
			if (!b.empty()) {


				if (!collision_detect(b, barrel1, tank1, planet2))
				{

					b[0].inc_bullet(map1.head);
					b[0].createSprite("sprites/missile/missile_2_no_margin.png");
					bulletSpriteCounter++;
					bulletSpriteCounter %= 4;
					b[0].shape.setTextureRect(sf::IntRect(bulletSpriteCounter * 60, 0, 60, 15));
					edge = false;

				}
				else
				{

					if (!edge)
					{
						std::cout << "Collision Detected!!" << std::endl;
						b[0].createSprite("sprites/explosions/explosion_1fix.png");
						bulletSpriteCounter++;
						bulletSpriteCounter %= 17;

						b[0].shape.setTextureRect(sf::IntRect(bulletSpriteCounter * 65, 0, 65, 65));
						if (bulletSpriteCounter == 16)
						{
							edge = true;
						}

						//b.clear();			// this causes vector iterator + error

					}

				}
			}

		}
		map1.window.draw(map1.background);
		//map1.window.draw(planet1.shape);
		map1.window.draw(planet2.shape);
		map1.window.draw(b[0].shape);
		map1.window.draw(barrel1.shape);
		map1.window.draw(tank1.shape);
		map1.window.display();
		map1.window.clear();
	}


}

bool collision_detect(std::vector<Bullet>b, Barrel barrel, Tank tank, Planet p)
{

		if ((b[0].shape.getGlobalBounds().intersects(p.shape.getGlobalBounds()))
			|| (b[0].shape.getGlobalBounds().intersects(tank.shape.getGlobalBounds()))
			|| (b[0].shape.getGlobalBounds().intersects(barrel.shape.getGlobalBounds())))
		{

			return true;
		}

	return false;
}
