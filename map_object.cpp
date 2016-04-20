//
// Created by Luris on 3/21/16.
//


#include "map_object.h"
#include <iostream>
#include <sstream>


void map::createWindow(int x, int y, std::string name) {

    window.create(sf::VideoMode(unsigned(x), unsigned(y)), name, sf::Style::Default);

}

void map::createSprite(std::string path) {
    if (!backgroundTexture.loadFromFile(path))
    {
        std::cout << "Error could not load background image" << std::endl;
    }

    background.setTexture(backgroundTexture);
}

std::string map::randomMap() {
	int seed = arc4random() % 7;
	std::stringstream ss;
	ss << seed;
	std::string str = ss.str();
	std::string mapPath = "sprites/sky/stars" + str + ".png";

	return mapPath;
}

map::map(int width, int height, std::string name) {
    createWindow(width, height, name);
    createSprite(randomMap());
    x_limit = width;
    y_limit = height;
}
