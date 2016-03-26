//
// Created by Young on 3/22/16.
//

#include "Barrel_object.h"
#include "Tank_object.h"

void Barrel::setPosition(int a, int b) {
	x = a;
	y = b;
	x_center = x + barrelTexture.getSize().x;
	y_center = y + barrelTexture.getSize().y;
	shape.setPosition(x, y);
}

int Barrel::getX() {
	return x;
}

int Barrel::getY() {
	return y;
}

void Barrel::createSprite(std::string path) {

	if (!barrelTexture.loadFromFile(path))
	{
		std::cout << "Error could not load barrel image" << std::endl;
	}

	shape.setTexture(barrelTexture);

}

void Barrel::setTank(Tank* tank) {

	tank_on = tank;
	
	setPosition(tank_on->x - barrelTexture.getSize().x / 4 - 8, tank_on->y + barrelTexture.getSize().y/4);
	
}

Barrel::Barrel(Tank* tank, std::string path) {

	createSprite(path);
	setTank(tank);

}