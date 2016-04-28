//
// Created by Luris on 4/28/16.
//

#ifndef ECE368_SPACE_TANK_ALLOCATION_H
#define ECE368_SPACE_TANK_ALLOCATION_H

#include "Barrel_object.h"
#include "Planet_list.h"

void allocation_objects(int map_choice, std::string tank1_color, std::string tank2_color, sf::Font* font, Tank** tank1, Tank** tank2, Barrel** barrel1, Barrel** barrel2, Planet_list* planet_list);

#endif //ECE368_SPACE_TANK_ALLOCATION_H
