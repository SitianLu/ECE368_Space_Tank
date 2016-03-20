//
// Created by Luris on 3/20/16.
//

#ifndef ECE368_SPACE_TANK_OBJECT_H
#define ECE368_SPACE_TANK_OBJECT_H

#endif //ECE368_SPACE_TANK_OBJECT_H
struct planet {
    double x_coord;
    double y_coord;
    double mass;
    double raidus;
};

struct planet_node {
    struct planet* current;
    struct planet_node* next;
    struct planet_node* prev;
};

struct map {
    struct planet_node* header;
    double gravity;
};
