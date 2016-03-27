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
    x_coord = a;
    y_coord = b;

    x_center = x_coord + (int)radius;
    y_center = y_coord + (int)radius;

    shape.setPosition(x_coord, y_coord);
}

void Planet::setMass(double m) {
    mass = m;
}

void Planet::setRadius(float r) {
    radius = r;
}

int Planet::getX() {
    return x_coord;
}

int Planet::getY() {
    return y_coord;
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

struct Force Planet::getGravity(int bullet_x, int bullet_y) {
    int distance_x = x_coord - bullet_x;
    int distance_y = y_coord - bullet_y;
    struct Force gravity_force;

    gravity_force.x = G * BULLET_MASS * mass / distance_x;
    gravity_force.y = G * BULLET_MASS * mass / distance_y;

    return(gravity_force);
}

void Planet::createShape() {
    sf::CircleShape base_circle(radius);
    shape = base_circle;
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
