//
// Created by Luris on 3/20/16.
//
#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>

#ifndef ECE368_SPACE_TANK_CLASS_DECLARATION_H
#define ECE368_SPACE_TANK_CLASS_DECLARATION_H
#endif //ECE368_SPACE_TANK_CLASS_DECLARATION_H


class Planet {
private:
    int x_coord;
    int y_coord;
    double mass;
    double radius;
    sf::Texture planetTexture;

public:
    sf::CircleShape shape;
    void setPosition(int, int);
    void setMass(double);
    void setRadius(double);
    void createShape();
    void createSprite(std::string);
    int getX();
    int getY();
    double getMass();
    double getRadius();
    double getCircumference();
    double getArea();
    struct Force getGravity(int, int);
};
