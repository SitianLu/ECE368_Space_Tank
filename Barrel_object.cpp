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

	shape.setPosition(x_origin, y_origin);

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

	setPosition(tank_on->x_edge, tank_on->y_edge - BARREL_Y_OFFSET);

}

Barrel::Barrel(Tank* tank, std::string barrel_path, std::string smoke_path) {

	createSprite(barrel_path);
	createSmokeSprite(smoke_path);
	setTank(tank);

	rotation = 0;
	limitation = 0;
	smokeSpriteCounter = 0;

}

int Barrel::getHeight() {
	return(barrelTexture.getSize().y);
}

int Barrel::getWidth() {
	return(barrelTexture.getSize().x);
}

void Barrel::Move_Clock(double radius) {

	shape.move((float)((tank_on->getPlanetRadius() + BARREL_Y_OFFSET) *
		(sin(tank_on->rotation) - sin(tank_on->rotation - radius))), (-1) * (float)(
		(tank_on->getPlanetRadius() + BARREL_Y_OFFSET) *
			(cos(tank_on->rotation) - cos(tank_on->rotation - radius))));

	shape.rotate((float)(radius * 180 / PI));

	rotation += (float)(radius * 180 / PI);

}

void Barrel::Move_ConterClock(double radius) {

	shape.move((float)((-1) * (tank_on->getPlanetRadius() + BARREL_Y_OFFSET)  * (sin(tank_on->rotation + radius) - sin(tank_on->rotation))), (float)((tank_on->getPlanetRadius() + BARREL_Y_OFFSET) * (cos(tank_on->rotation + radius) - cos(tank_on->rotation))));

	shape.rotate((float)((-1) * radius * 180 / PI));

	rotation += (float)((-1) * radius * 180 / PI);


}

sf::Vector2f Barrel::getLaunchPoint() {

	sf::Vector2f launchPoint;

	launchPoint.x = this->shape.getPosition().x - (float)cos((rotation / 180) * PI) * (this->getWidth() + LAUNCH_OFFSET);
	launchPoint.y = this->shape.getPosition().y - (float)sin((rotation / 180) * PI) * (this->getWidth() + LAUNCH_OFFSET);

	return launchPoint;
}

sf::Vector2f Barrel::getInitialDirection() {

	sf::Vector2f initialDirection; //Create the unit vector for initial direction that follows the barrel direction

	initialDirection.x = ((-1) * (float)cos((rotation / 180) * PI) * (this->getWidth() + LAUNCH_OFFSET)) / (this->getWidth());
	initialDirection.y = ((-1) * (float)sin((rotation / 180) * PI) * (this->getWidth() + LAUNCH_OFFSET)) / (this->getWidth());

	return(initialDirection);
}

void Barrel::createSmokeSprite(std::string path) {
	sf::IntRect box(0, 0, 65, 65);

	if (!smoke_Texture.loadFromFile(path))
	{
		std::cout << "Error could not load barrel image!!" << std::endl;
	}

	smoke_shape.setTexture(smoke_Texture);
	smoke_shape.setTextureRect(box);

	smoke_shape.setOrigin(float(EXPLOSION_SPRITE_OFFSET * 2), EXPLOSION_SPRITE_OFFSET);
	smoke_shape.rotate(180);
}

void Barrel::setSmokePosition(float x, float y) {

	smoke_shape.setPosition(x, y);
	smoke_shape.setRotation(180 + rotation);
}



