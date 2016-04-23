//
// Created by Luris on 3/22/16.
//

#include "Tank_object.h"
#include <math.h>
#include "Global_constant.h"

void Tank::setPosition(int a, int b) {
	x_edge = a;
	y_edge = b;

	shape.setPosition(x_edge, y_edge);
}

void Tank::setHp(int a)
{
	hp = a;
}

int Tank::getHp()
{
	return hp;
}



void Tank::damageHp(int a)
{
	hp = hp - a;
}

/*void Tank::setText(sf::Font font)
{
	std::string c = std::to_string(getHp());
	text.setFont(font);
	text.setString("HP: "+c);
	text.setColor(sf::Color::Green);
	text.setPosition(300, 300);
}*/



void Tank::createSprite(std::string path) {

	if (!tankTexture.loadFromFile(path))
	{
		std::cout << "Error could not load tank image" << std::endl;
	}

	shape.setTexture(tankTexture);

	shape.setOrigin(tankTexture.getSize().x / 2, tankTexture.getSize().y);

}

void Tank::setPlanet(Planet* planet) {

	planet_on = planet;
	setPosition(planet_on->x_center, planet_on->y_center - (int)planet_on->radius);

}

Tank::Tank(Planet* planet, std::string path) {

	createSprite(path);
	setPlanet(planet);

	rotation = 0.0;
	setHp(INITIALHP);

}

int Tank::getEdgeX() {
	return x_edge;
}

int Tank::getEdgeY() {
	return y_edge;
}

double Tank::getPlanetRadius() {
	return planet_on->getRadius();
}

void Tank::Move_Clock(double radius) {

	rotation += radius;

	shape.move((float)(getPlanetRadius() * (sin(rotation) - sin(rotation - radius))),
		(-1) * (float)(getPlanetRadius() * (cos(rotation) - cos(rotation - radius))));

	shape.rotate((float)(radius * 180 / PI));

}

void Tank::Move_ConterClock(double radius) {

	rotation -= radius;

	shape.move((-1) * (float)(getPlanetRadius() * (sin(rotation + radius) - sin(rotation))),
		(float)(getPlanetRadius() * (cos(rotation + radius) - cos(rotation))));

	shape.rotate((float)((-1) * radius * 180 / PI));

}
