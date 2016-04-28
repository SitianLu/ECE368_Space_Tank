
#include <SFML/Graphics.hpp>
#include <iostream>
#include "bullet_object.h"
#include "map_object.h"
#include "Planet_list.h"
#include "Barrel_object.h"
#include "Global_constant.h"
#include <string>
#include <math.h>
#include "Menu.h"
#include "End_Menu.h"
#include <SFML/Audio.hpp>
#include "Allocation.h"

int main()
{
	/* Initialization for Global use variables */
	sf::Font hp_font;
	sf::Font power_font;
	sf::Text HUD_PWR;
	sf::Text HUD_TURN;
	sf::Texture Bullet_Texture;
	sf::Texture Explosion_Texture;
	Bullet* bullet_current = NULL;
	sf::Clock clock;
	sf::Time time;

	sf::Sound smokeSound;
	sf::SoundBuffer smBuffer;

	sf::Sound missileSound;
	sf::SoundBuffer mBuffer;

	Tank* tank1 = NULL;
	Tank* tank2 = NULL;
	Barrel* barrel1 =  NULL;
	Barrel* barrel2 =  NULL;
	Planet_list planet_list;


	int turn = 0;
	bool bulletFired = false;
	float power = 5.f;
	int index = 0;
	float frameCounter = 0, switchFrame = 10, frameSpeed = 500;
	bool End = false;
	int winner = -1;
	int power_roll = -1;
	bool scroll_flag = false;

	int window_W = 1800;
	int window_H = 800;

	/* Loading multimedia and texture */

	if (!smBuffer.loadFromFile("Sound/shot01.wav"))
	{
		std::cout << "Error could not load sound Bomb03.wav" << std::endl;
	}

	if (!mBuffer.loadFromFile("Sound/Bomb03.wav"))
	{
		std::cout << "Error could not load sound Bomb03.wav" << std::endl;
	}

	if (!power_font.loadFromFile("Word_font/OpenSans-bold.ttf")) {
		std::cout << "Error could not load font" << std::endl;
	}

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

	/* Build the window/map/background */
	map map1(window_W, window_H, "Space Tank");

	/*
	Planet planet1(500, 500, 1500000, 150, "sprites/planets/red.png", &hp_font);
	Planet planet2(900, 400, 2000000, 150, "sprites/planets/earth.png", &hp_font);
	Planet planet3(1500, 500, 3000000, 200, "sprites/planets/pink.png", &hp_font);

	planet_list.addPlanet(&planet1);
	planet_list.addPlanet(&planet2);
	planet_list.addPlanet(&planet3);

	Tank tank1(&planet1, "sprites/tanks/tank3.png", &hp_font);
	Tank tank2(&planet3, "sprites/tanks/tank4.png", &hp_font);
	Tank tank_list[2] = { tank1, tank2 };

	Barrel barrel1(&tank_list[0], "sprites/tanks/barrel3.png", "sprites/explosions/smoke_140_64.png");
	Barrel barrel2(&tank_list[1], "sprites/tanks/barrel4.png", "sprites/explosions/smoke_140_64.png");
	Barrel barrel_list[2] = { barrel1, barrel2 };

	*/
	GameSettings settings;
	settings = StartMenu();

	allocation_objects(settings.Map, settings.Player1, settings.Player2, &hp_font, &tank1, &tank2, &barrel1, &barrel2, &planet_list);

	Tank tank_list[2] = {*tank1, *tank2};
	Barrel barrel_list[2] = {*barrel1, *barrel2};

	tank1 -> text.setStyle(sf::Text::Bold);

	HUD_PWR.setFont(power_font);
	HUD_PWR.setPosition(0, window_H - PWR_TEXTSIZE * 2);

	HUD_TURN.setFont(power_font);
	HUD_TURN.setPosition(0, window_H - PWR_TEXTSIZE - TURN_TEXTSIZE - 50);


	smokeSound.setBuffer(smBuffer);
	missileSound.setBuffer(mBuffer);

	sf::Music BattleMusic;
	BattleMusic.openFromFile("Sound/Battle.wav");
	BattleMusic.play();

	while (map1.window.isOpen()) {
		sf::Event Event;
		if (turn == 0)
		{
			HUD_PWR.setColor(sf::Color::White);
			HUD_TURN.setColor(sf::Color::White);
		}
		if (turn == 1)
		{
			HUD_PWR.setColor(sf::Color(143, 27, 45));
			HUD_TURN.setColor(sf::Color(143, 27, 45));
		}
		HUD_PWR.setString("Power: " + std::to_string((int)power - 5) + " %");
		HUD_TURN.setString("Turn: Player " + std::to_string(turn + 1));

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
						if (barrel_list[turn].limitation > -6) {
							barrel_list[turn].rotation += -3;
							barrel_list[turn].limitation += -3;
							barrel_list[turn].shape.rotate((float)-3.0);
						}
					}

					if (Event.key.code == sf::Keyboard::Up)
					{
						if (barrel_list[turn].limitation < 178) {
							barrel_list[turn].rotation += 3;
							barrel_list[turn].limitation += 3;
							barrel_list[turn].shape.rotate(3.0);
						}
					}

					if (Event.key.code == sf::Keyboard::Right)
					{
						if (!bulletFired) {
							tank_list[turn].Move_Clock(0.05);
							barrel_list[turn].Move_Clock(0.05);
						}
					}

					if (Event.key.code == sf::Keyboard::Left)
					{
						if (!bulletFired) {
							tank_list[turn].Move_ConterClock(0.05);
							barrel_list[turn].Move_ConterClock(0.05);
						}
					}
					if (Event.key.code == sf::Keyboard::Space)
					{
						if (!bulletFired && power_roll == 2) {

							barrel_list[turn].setSmokePosition(barrel_list[turn].getLaunchPoint().x, barrel_list[turn].getLaunchPoint().y);
							barrel_list[turn].smokeSpriteCounter = 0;
							smokeSound.play();
							bullet_current = new Bullet(barrel_list[turn].getLaunchPoint(), 10, barrel_list[turn].getInitialDirection() * power, &Bullet_Texture, &Explosion_Texture);
							bullet_current->setDamage(BULLET_DAMAGE);

							power = 5.f;

							bulletFired = true;

						}
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {

						if (!bulletFired) {

							if (power_roll == -1) {
								power_roll = 1;
							}
							else {
								power_roll = 2;
							}
						}
						/*
						if (power < 105) {

							power += 1.f;

						}
						 */
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
			//planet1.shape.rotate(0.08);
			//planet2.shape.rotate(float(-0.07));
			//planet3.shape.rotate(0.09);

			if (power_roll == 1) {
				if (power < 105 && !scroll_flag) {
					power += 1.f;
				}
				else {
					scroll_flag = true;
					power -= 1.f;
					if (power == 5) {
						scroll_flag = false;
					}
				}
			}

			if (bulletFired) {

				// Barrel Smoke Animation
				if (barrel_list[turn].smokeSpriteCounter <= 16) {

					barrel_list[turn].smoke_shape.setTextureRect(sf::IntRect(barrel_list[turn].smokeSpriteCounter * 140, 0, 140, 64));
					barrel_list[turn].smokeSpriteCounter++;
				}

				// Bullet Animation
				bullet_current->collision_detect(tank_list, planet_list.head, &map1);

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
						//bullet_current->playExpMusic();
						missileSound.play();
						if (bullet_current->tankHit)
						{

							tank_list[0].updateHP_Text();
							tank_list[1].updateHP_Text();
							//std::cout << "got hit tank hp: " << tank1.getHp() << std::endl;

						}
					}
				}
			}
		}

		map1.window.draw(map1.background);
		for (planet_node* current = planet_list.head; current != NULL; current = current -> next) {
			map1.window.draw(current -> value -> shape);
			map1.window.draw(current -> value -> Mass_text);
		}
		map1.window.draw(HUD_PWR);
		map1.window.draw(HUD_TURN);
		for (int i = 0; i < 2; i++) {
			if (tank_list[i].getHp() > 0) {
				map1.window.draw(barrel_list[i].shape);
				map1.window.draw(tank_list[i].shape);
				map1.window.draw(tank_list[i].text);

			} else {

				if (i == 0) {
					winner = 1;
				}
				else {
					winner = 0;
				}
			}
		}


		if (bulletFired) {
			if (barrel_list[turn].smokeSpriteCounter <= 16)
			{
				map1.window.draw(barrel_list[turn].smoke_shape);
			}
			if ((bullet_current->explosion_detected) && (bullet_current->explosionSpriteCounter <= 16)) {
				map1.window.draw(bullet_current->explosion_shape);

			}
			else if (!bullet_current->explosion_detected) {
				map1.window.draw(bullet_current->bullet_shape);
			}
			else { //If the explosion ends
				if (winner != -1) {
					map1.window.close();
					break;
				}

				bulletFired = false;
				delete(bullet_current);
				power_roll = -1;
				scroll_flag = false;

				tank_list[turn].text.setStyle(sf::Text::Regular);

				if (turn == 0) {
					turn = 1;
				}
				else {
					turn = 0;
				}

				tank_list[turn].text.setStyle(sf::Text::Bold);
			}
		}

		map1.window.display();
		map1.window.clear();
	}

	if (winner != -1) {
		End_menu(winner, &hp_font);

	}


}
