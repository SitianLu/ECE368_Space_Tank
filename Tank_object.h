//
// Created by Luris on 3/22/16.
//

#ifndef ECE368_SPACE_TANK_TANK_OBJECT_H
#define ECE368_SPACE_TANK_TANK_OBJECT_H

#include<SFML/Graphics.hpp>
#include<string>

class Tank {
private:
    int x;
    int y;
    int rotation;
    int tank_number;
    //Planet planet_on;
    sf::Texture tankTexture;

public:
    sf::Sprite shape;
    void setPosition(int x, int y);
    int getX();
    int getY();
    void createSprite(std::string);
    //void setPlanet(Planet);
};


#endif //ECE368_SPACE_TANK_TANK_OBJECT_H
