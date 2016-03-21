//
// Created by Luris on 3/21/16.
//

#ifndef ECE368_SPACE_TANK_MAP_H
#define ECE368_SPACE_TANK_MAP_H

#include <SFML/Graphics.hpp>
#include <string>

class map {
private:
    sf::Texture backgroundTexture;

public:
    sf::Sprite background;
    sf::RenderWindow window;
    map(int width, int length, std::string name, std::string path);
    void createWindow(int x, int y, std::string name);
    void createSprite(std::string);

};


#endif //ECE368_SPACE_TANK_MAP_H
