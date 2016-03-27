//
// Created by Luris on 3/20/16.
//
#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include"Force_struct.h"

#ifndef ECE368_SPACE_TANK_CLASS_DECLARATION_H
#define ECE368_SPACE_TANK_CLASS_DECLARATION_H


class Planet {
private:
    int x_coord;
    int y_coord;
    int x_center;
    int y_center;
    double mass;
    float radius;
    int number;
    sf::Texture planetTexture;

public:
    sf::CircleShape shape;
    Planet(int number, int x, int y, double mass, float radius, std::string);
    void setNumber(int);
    void setPosition(int, int);
    void setMass(double);
    void setRadius(float);
    void createShape();
    void createSprite(std::string);
    int getX();
    int getY();
    int getCenterX();
    int getCenterY();
    double getMass();
    double getRadius();
    double getCircumference();
    double getArea();
    struct Force getGravity(int, int);
    friend class Tank;
    friend class Barrel;
};


typedef struct planet_nodes {
	Planet* value;
	struct planet_nodes* next;
}planet_node;

#endif //ECE368_SPACE_TANK_CLASS_DECLARATION_H
