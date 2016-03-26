//
// Created by Luris on 3/22/16.
//

#ifndef ECE368_SPACE_TANK_TANK_OBJECT_H
#define ECE368_SPACE_TANK_TANK_OBJECT_H

#include<SFML/Graphics.hpp>
#include<string>
#include "Planet_object.h"


class Tank {
private:
    int x;
    int y;
    int x_center;
    int y_center;
    int rotation;
    int tank_number;
    Planet* planet_on;
    sf::Texture tankTexture;

public:
    sf::Sprite shape;
    void setPosition(int x, int y);
    int getX();
    int getY();
    int getCenterX();
    int getCenterY();
    void createSprite(std::string);
    void setPlanet(Planet*);
    Tank(Planet*, std::string);
    friend class Barrel;
};


#endif //ECE368_SPACE_TANK_TANK_OBJECT_H
