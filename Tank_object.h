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

	int x_edge;
	int y_edge;
	Planet* planet_on;
	sf::Texture tankTexture;
	double rotation;
	int hp;


public:
	sf::Sprite shape;
	sf::Text text;
	void setPosition(int x, int y);
	double getPlanetRadius();
	int getEdgeX();
	int getEdgeY();
	void createSprite(std::string);
	void setPlanet(Planet*);
	Tank(Planet*, std::string, sf::Font*);
	friend class Barrel;
	void Move_Clock(double radius);
	void Move_ConterClock(double radius);

	void setHp(int a);
	int getHp();
	void damageHp(int a);

	void createHP(sf::Font *hp_Font);
	void updateHP_Text();

};


#endif //ECE368_SPACE_TANK_TANK_OBJECT_H
