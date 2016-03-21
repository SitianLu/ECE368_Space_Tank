//
// Created by Luris on 3/21/16.
//


#include "map_object.h"
#include <iostream>


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

map::map(int width, int length, std::string name, std::string path) {
    createWindow(width, length, name);
    createSprite(path);
}