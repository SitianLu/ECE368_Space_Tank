//
// Created by Luris on 4/16/16.
//

#ifndef ECE368_SPACE_TANK_PLANET_LIST_H
#define ECE368_SPACE_TANK_PLANET_LIST_H
#include "Planet_object.h"

class Planet_list {

public:
    planet_node* head;
    planet_node* tail;

    Planet_list(void);
    void addPlanet (Planet*);

};


#endif //ECE368_SPACE_TANK_PLANET_LIST_H
