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

public:
	sf::Sprite shape;
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
	Barrel(Tank*, std::string);
};



