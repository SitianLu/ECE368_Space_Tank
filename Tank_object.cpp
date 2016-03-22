//
// Created by Luris on 3/22/16.
//

#include "Tank_object.h"
#include <iostream>

void Tank::setPosition(int a, int b) {
    x = a;
    y = b;
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




