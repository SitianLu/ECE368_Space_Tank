//
// Created by Luris on 3/22/16.
//

#include "Tank_object.h"
//#include <iostream>
//#include "Global_constant.h"


void Tank::setPosition(int a, int b) {
    x = a;
    y = b;
    x_center = x + tankTexture.getSize().x;
    y_center = y + tankTexture.getSize().y;
    shape.setPosition(x,y);
}

int Tank::getX() {
    return x;
}

int Tank::getY() {
    return y;
}

void Tank::createSprite(std::string path) {

    if (!tankTexture.loadFromFile(path))
    {
        std::cout << "Error could not load tank image" << std::endl;
    }

    shape.setTexture(tankTexture);

}

void Tank::setPlanet(Planet* planet) {

    planet_on = planet;
    setPosition(planet_on->x_center - tankTexture.getSize().x / 2, planet_on->y_coord - (tankTexture.getSize()).y);


}

Tank::Tank(Planet* planet, std::string path) {

    createSprite(path);
    setPlanet(planet);

}
