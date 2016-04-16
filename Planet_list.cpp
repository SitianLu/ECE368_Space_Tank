//
// Created by Luris on 4/16/16.
//

#include "Planet_list.h"

Planet_list::Planet_list(void) {
    head = NULL;
    tail = NULL;
}


void Planet_list::addPlanet(Planet *planet) {
    if (head == NULL) {
        head = new planet_node;
        head -> value = planet;
        head -> next = NULL;
        tail = head;
    }
    else {
        tail -> next = new planet_node;
        tail -> next -> value = planet;
        tail -> next -> next = NULL;
        tail = tail -> next;
    }

}
