//
// Created by Luris on 3/20/16.
//

#include "Planet_object.h"
#include "Global_constant.h"
#include <cmath>


Planet::Planet(int number, int x, int y, double mass, float radius, std::string path) {

    setNumber(number);
    setMass(mass);
    setRadius(radius);
    createShape();
    createSprite(path);
    setPosition(x,y);
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


sf::Vector2f Planet::getGravity(int bullet_x, int bullet_y) {
    float distance_x = 900 - bullet_x;
    float distance_y = 400 - bullet_y;
	float distance = sqrt(pow(distance_x, 2) + pow(distance_y, 2));
	float force_mag = G*mass*BULLET_MASS / distance;
	sf::Vector2f r_hat(distance_x / distance, distance_y / distance);
	sf::Vector2f gravity_force(0,0);
	gravity_force.x = force_mag*r_hat.x;
	gravity_force.y = force_mag*r_hat.y;
	printf("FUNCTION IS CALLED\n FORCE X %f FORCE Y %f\n DISTANCE X %d DISTANCE Y %d\n UNIT VECTOR <%d",gravity_force.x,gravity_force.y,distance_x,distance_y);

    return(gravity_force);
}

void Planet::createShape() {
    sf::CircleShape base_circle(radius);
    shape = base_circle;
    shape.setOrigin(sf::Vector2f(radius,radius));
}

void Planet::createSprite(std::string path) {

    if (!planetTexture.loadFromFile(path))
    {
        std::cout << "Error could not load planet image" << std::endl;
    }
    planetTexture.setSmooth(true);
    shape.setTexture(&planetTexture);

}

void Planet::setNumber(int a) {
    number = a;

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

