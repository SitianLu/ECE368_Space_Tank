#pragma once
//
// Created by Young on 3/26/16.
//

#include<SFML/Graphics.hpp>
#include<string>
#include "Planet_object.h"
#include "Tank_object.h"


class Barrel {
private:
	int x_origin;
	int y_origin;
	Tank* tank_on;
	sf::Texture barrelTexture;
    sf::Texture smoke_Texture;


public:
	sf::Sprite shape;
	sf::Sprite smoke_shape;
	int smokeSpriteCounter;
	float rotation;
	float limitation;
	void setPosition(int x, int y);
	int getX();
	int getY();
	void createSprite(std::string);
	void setTank(Tank*);
	int getHeight();
	int getWidth();
	void Move_Clock(double radius);
	void Move_ConterClock(double radius);
	sf::Vector2f getLaunchPoint();
	sf::Vector2f getInitialDirection();
	void createSmokeSprite(std::string path);
	void setSmokePosition(float x, float y);

	Barrel(Tank*, std::string barrel_path, std::string smoke_path);
};
