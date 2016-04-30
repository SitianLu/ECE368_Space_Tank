//
// Created by Luris on 3/20/16.
//

#include "Planet_object.h"
#include "Global_constant.h"
#include <cmath>


Planet::Planet(int x, int y, double mass, float radius, std::string path, sf::Font* font) {

	setMass(mass);
	setRadius(radius);
	createShape();
	createSprite(path);
	setPosition(x, y);
	createText(font);
}

void Planet::setPosition(int a, int b) {

	x_center = a;
	y_center = b;

	shape.setPosition(x_center, y_center);
}

void Planet::setMass(double m) {
	mass = m;
}

void Planet::setRadius(float r) {
	radius = r;
}

double Planet::getMass() {
	return mass;
}

double Planet::getRadius() {
	return radius;
}

double Planet::getCircumference() {
	return (radius * 2 * PI);
}

double Planet::getArea() {
	return (radius * radius * PI);
}


sf::Vector2f Planet::getGravity(float bullet_x, float bullet_y) {
	float distance_x = x_center - bullet_x;
	float distance_y = y_center - bullet_y;
	float distance = sqrt(pow(distance_x, 2) + pow(distance_y, 2));
	float force_mag = G*mass*BULLET_MASS / distance;
	sf::Vector2f r_hat(distance_x / distance, distance_y / distance); //Unit vector of distance/force
	sf::Vector2f gravity_force(0, 0);
	gravity_force.x = force_mag*r_hat.x;
	gravity_force.y = force_mag*r_hat.y;
	return(gravity_force);
}

void Planet::createShape() {
	sf::CircleShape base_circle(radius);
	shape = base_circle;
	shape.setOrigin(sf::Vector2f(radius, radius));
}

void Planet::createSprite(std::string path) {

	if (!planetTexture.loadFromFile(path))
	{
		std::cout << "Error could not load planet image" << std::endl;
	}
	planetTexture.setSmooth(true);
	shape.setTexture(&planetTexture);

}

int Planet::getCenterX() {
	return x_center;
}

int Planet::getCenterY() {
	return y_center;
}

double Planet::getAngle(double edge_distance) {
	return(360.0 * (edge_distance / getCircumference()));
}

void Planet::createText(sf::Font *font) {

		Mass_text.setFont(*font);
		Mass_text.setCharacterSize(MASS_TEXTSIZE);
		Mass_text.setString("Mass: " + std::to_string((int)mass) + "KG");
		Mass_text.setColor(sf::Color::White);
		Mass_text.setStyle(sf::Text::Bold);

		Mass_text.setOrigin(70, 20);

		Mass_text.setPosition(x_center,y_center);

}

void Planet::move(int xmove, int ymove)
{
	x_center += xmove;
	y_center += ymove;
	shape.move(xmove, ymove);
}

void Planet::orbit(double angle, int xpos, int ypos)
{
	int delta_y = y_center - ypos;
	int delta_x = x_center - xpos;
	double length = sqrt(delta_y*delta_y + delta_x*delta_x);
	double ang = atan2(delta_x, delta_y);
	ang += angle;
	x_center = xpos + length * sin(ang);
	y_center = ypos + length * cos(ang);
	shape.setPosition(x_center, y_center);
}


