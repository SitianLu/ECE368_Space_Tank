//
// Created by Young on 3/22/16.
//

#include <math.h>
#include "Barrel_object.h"
#include "Tank_object.h"
#include "Global_constant.h"

void Barrel::setPosition(int a, int b) {
    x_origin = a;
    y_origin = b;

    shape.setPosition(x_origin,y_origin);

}

int Barrel::getX() {
	return x_origin;
}

int Barrel::getY() {
	return y_origin;
}

void Barrel::createSprite(std::string path) {

	if (!barrelTexture.loadFromFile(path))
	{
		std::cout << "Error could not load barrel image" << std::endl;
	}

	shape.setTexture(barrelTexture);

	shape.setOrigin(barrelTexture.getSize().x - BARREL_CENTER_OFFSET, barrelTexture.getSize().y / 2);

}

void Barrel::setTank(Tank* tank) {

	tank_on = tank;

    setPosition(tank_on -> x_edge, tank_on -> y_edge - BARREL_Y_OFFSET);

}

Barrel::Barrel(Tank* tank, std::string path) {

	createSprite(path);
	setTank(tank);

    rotation = 0;
}

int Barrel::getHeight() {
    return(barrelTexture.getSize().y);
}

int Barrel::getWidth() {
    return(barrelTexture.getSize().x);
}

void Barrel::Move_Clock(double radius) {

		shape.move((float) ((tank_on->getPlanetRadius() + BARREL_Y_OFFSET) *
							(sin(tank_on->rotation) - sin(tank_on->rotation - radius))), (-1) * (float) (
				(tank_on->getPlanetRadius() + BARREL_Y_OFFSET) *
				(cos(tank_on->rotation) - cos(tank_on->rotation - radius))));

		shape.rotate((float) (radius * 180 / PI));
}

void Barrel::Move_ConterClock(double radius) {

    shape.move((float) ((-1) * (tank_on -> getPlanetRadius() + BARREL_Y_OFFSET)  * (sin(tank_on -> rotation + radius) - sin(tank_on -> rotation))), (float) ((tank_on -> getPlanetRadius() + BARREL_Y_OFFSET) * (cos(tank_on -> rotation + radius) - cos(tank_on -> rotation))));

    shape.rotate((float) ((-1) * radius * 180 / PI));

}
