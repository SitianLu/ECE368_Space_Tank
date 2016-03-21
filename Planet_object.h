//
// Created by Luris on 3/20/16.
//
#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include"Force_struct.h"

#ifndef ECE368_SPACE_TANK_CLASS_DECLARATION_H
#define ECE368_SPACE_TANK_CLASS_DECLARATION_H
#endif //ECE368_SPACE_TANK_CLASS_DECLARATION_H


class Planet {
private:
    int x_coord;
    int y_coord;
    double mass;
    float radius;
    sf::Texture planetTexture;

public:
    sf::CircleShape shape;
    Planet(int x, int y, double mass, float radius, std::string);
    void setPosition(int, int);
    void setMass(double);
    void setRadius(float);
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
