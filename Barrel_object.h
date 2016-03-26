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
	int x;
	int y;
	int x_center;
	int y_center;
	int rotation;
	int barrel_number;
	Tank* tank_on;
	sf::Texture barrelTexture;

public:
	sf::Sprite shape;
	void setPosition(int x, int y);
	int getX();
	int getY();
	void createSprite(std::string);
	void setTank(Tank*);
	Barrel(Tank*, std::string);
};



