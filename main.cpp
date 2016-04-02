
#include <SFML/Graphics.hpp>
#include <iostream>
#include "bullet_object.h"
#include "map_object.h"
//#include "Tank_object.h"
#include "Barrel_object.h"
#include "Global_constant.h"
#include <string>
#include <math.h>

bool collision_detect(Bullet b, Tank tank, Barrel barrel, std::vector<Planet*> pln);

int main()
{

	bool edge = false;

	//Build the window/map/background
	map map1(1800, 800, "Space Tank");

	Planet planet1(500,500,2000000,150,"sprites/planets/red.png");
	Planet planet2(900, 400, 2000000, 150, "sprites/planets/earth.png");
	//Planet planet3(1300,300,2000000,300,"sprites/planets/pink.png");

	Tank tank1(&planet2, "sprites/tanks/tank3.png");
	Barrel barrel1(&tank1, "sprites/tanks/barrel3.png");

	sf::Vector2f speed(5, 57);
	Bullet bullet1(600, 400, 10, speed, "sprites/missile/missile_2_no_margin.png");
	std::vector<Planet*> planet_vector;
	planet_vector.push_back(&planet1);
	planet_vector.push_back(&planet2);

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
			//bullet1.shape.rotate(1);

			if (!collision_detect(bullet1, tank1, barrel1, planet_vector))
			{
				bullet1.inc_bullet(map1.head);
				bullet1.createSprite("sprites/missile/missile_2_no_margin.png");
				bulletSpriteCounter++;
				bulletSpriteCounter %= 4;
				bullet1.shape.setTextureRect(sf::IntRect(bulletSpriteCounter * 60, 0, 60, 15));
				edge = false;

			}
			else
			{

				if (!edge)
				{
					std::cout << "Collision Detected!!" << std::endl;
					bullet1.createSprite("sprites/explosions/explosion_1fix.png");
					bulletSpriteCounter++;
					bulletSpriteCounter %= 17;

					bullet1.shape.setTextureRect(sf::IntRect(bulletSpriteCounter * 65, 0, 65, 65));
					if (bulletSpriteCounter == 16)
					{
						edge = true;
					}

				}

			}


		}
		map1.window.draw(map1.background);
		map1.window.draw(planet1.shape);

		map1.window.draw(planet2.shape);
		map1.window.draw(bullet1.shape);
		map1.window.draw(barrel1.shape);
		map1.window.draw(tank1.shape);
		map1.window.display();
		map1.window.clear();
	}


}

bool collision_detect(Bullet b, Tank tank, Barrel barrel, std::vector<Planet*> pln)
{
	int e = b.getPosition().x - barrel.getX();
	int r = b.getPosition().y - barrel.getY();

	//float t = (b.getPosition().x + b.shape.getTextureRect().width / 2) - tank.shape.getPosition().x+tank.shape.getTextureRect().width/2;
	//float l = (b.getPosition().y + b.shape.getTextureRect().height / 2) - tank.shape.getPosition().y+tank.shape.getTextureRect().height/2;


	bool bullet_barrel_detection = b.shape.getGlobalBounds().intersects(barrel.shape.getGlobalBounds());
	bool bullet_tank_detection = b.shape.getGlobalBounds().intersects(tank.shape.getGlobalBounds());
	//int bullet_tank_distance = sqrt(pow(t, 2) + pow(l, 2));
	for (int i = 0; i < pln.size(); i++)
	{
		//planet_co = b.shape.getGlobalBounds().intersects(pln[i]->shape.getGlobalBounds());

		bool bul_pln_distance = sqrt(pow(pln[i]->shape.getPosition().x - b.shape.getPosition().x, 2)
			+ pow(pln[i]->shape.getPosition().y - b.shape.getPosition().y, 2)) >= pln[i]->getRadius() + 32;

		if (!bul_pln_distance || bullet_barrel_detection || (bullet_tank_detection))
		{
			return true;
		}

	}

	//int q = b.getPosition().x - p.getCenterX();
	//int w = b.getPosition().y - p.getCenterY();

	//int bullet_planet_distance = sqrt(pow(q, 2) + pow(w, 2));

	return false;
}
