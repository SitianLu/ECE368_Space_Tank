//
// Created by Luris on 3/20/16.
//
#ifndef ECE368_SPACE_TANK_CLASS_DECLARATION_H
#define ECE368_SPACE_TANK_CLASS_DECLARATION_H

#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include"Force_struct.h"

class Planet {
private:
	int x_center;
	int y_center;
	double mass;
	float radius;
	sf::Texture planetTexture;


public:
	sf::CircleShape shape;
	sf::Text Mass_text;
	bool Mass_display;
	Planet(int x, int y, double mass, float radius, std::string, sf::Font* font);
	void setPosition(int, int);
	void setMass(double);
	void setRadius(float);
	void createShape();
	void createSprite(std::string);
	int getCenterX();
	int getCenterY();
	double getMass();
	double getRadius();
	double getCircumference();
	double getArea();
	void createText(sf::Font* font);
	void move(int xmove, int ymove);
	void orbit(double angle, int,int);
	sf::Vector2f getGravity(float, float);
	double getAngle(double edge_distance);
	friend class Tank;
	friend class Barrel;
};

typedef struct planet_nodes {
	Planet* value;
	struct planet_nodes* next;
}planet_node;

#endif //ECE368_SPACE_TANK_CLASS_DECLARATION_H
