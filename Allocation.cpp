//
// Created by Luris on 4/28/16.
//
#include "Allocation.h"

void allocation_objects(int map_choice, std::string tank1_color, std::string tank2_color, sf::Font* font, Tank** tank1, Tank** tank2, Barrel** barrel1, Barrel** barrel2, Planet_list* planet_list) {

    Planet* tank1_on = NULL;
    Planet* tank2_on = NULL;
    if (map_choice == 1) {
        tank1_on = new Planet(300, 500, 200000, 100, "sprites/planets/red.png", font);
        tank2_on = new Planet(1600, 500, 200000, 100, "sprites/planets/pink.png", font);

        planet_list -> addPlanet(tank1_on);
        planet_list -> addPlanet(tank2_on);
        planet_list -> addPlanet(new Planet(900, 400, 2000000, 300, "sprites/planets/earth.png", font));

        *tank1 = new Tank(tank1_on, "sprites/tanks/tank" + tank1_color + ".png", font);
        *tank2 = new Tank(tank2_on, "sprites/tanks/tank" + tank2_color + ".png", font);

        *barrel1 = new Barrel(*tank1, "sprites/tanks/barrel" + tank1_color + ".png", "sprites/explosions/smoke_140_64.png");
        *barrel2 = new Barrel(*tank2, "sprites/tanks/barrel" + tank2_color + ".png", "sprites/explosions/smoke_140_64.png");
    }

    if (map_choice == 2) {
        tank1_on = new Planet(400, 380, 2000000, 125, "sprites/planets/earth.png", font);
        tank2_on = new Planet(1300, 380, 2000000, 125, "sprites/planets/hell.png", font);

        planet_list -> addPlanet(tank1_on);
        planet_list -> addPlanet(tank2_on);
        planet_list -> addPlanet(new Planet(750, 380, 2000000, 75, "sprites/planets/blue.png", font));
        planet_list -> addPlanet(new Planet(1750, 380, 2000000, 75, "sprites/planets/red.png", font));

        *tank1 = new Tank(tank1_on, "sprites/tanks/tank" + tank1_color + ".png", font);
        *tank2 = new Tank(tank2_on, "sprites/tanks/tank" + tank2_color + ".png", font);

        *barrel1 =  new Barrel(*tank1, "sprites/tanks/barrel" + tank1_color + ".png", "sprites/explosions/smoke_140_64.png");
        *barrel2 =  new Barrel(*tank2, "sprites/tanks/barrel" + tank2_color + ".png", "sprites/explosions/smoke_140_64.png");
    }

    if (map_choice == 3) {
        tank1_on = new Planet(400, 380, 2000000, 125, "sprites/planets/earth.png", font);
        tank2_on = new Planet(1400, 380, 2000000, 125, "sprites/planets/pink.png", font);

        planet_list -> addPlanet(tank1_on);
        planet_list -> addPlanet(tank2_on);
        planet_list -> addPlanet(new Planet(1168, 713, 200000, 75, "sprites/planets/hell2.png", font));
        planet_list -> addPlanet(new Planet(420, 720, 200000, 75, "sprites/planets/hell3.png", font));
        planet_list -> addPlanet(new Planet(700, 200, 200000, 75, "sprites/planets/hell4.png", font));
        planet_list -> addPlanet(new Planet(880, 50, 200000, 75, "sprites/planets/hell5.png", font));
        planet_list -> addPlanet(new Planet(1050, 200, 200000, 75, "sprites/planets/hell4.png", font));
        planet_list -> addPlanet(new Planet(1000, 400, 200000, 75, "sprites/planets/hell3.png", font));
        planet_list -> addPlanet(new Planet(820, 780, 200000, 75, "sprites/planets/hell2.png", font));
        planet_list -> addPlanet(new Planet(750, 600, 200000, 75, "sprites/planets/hell5.png", font));

        *tank1 = new Tank(tank1_on, "sprites/tanks/tank" + tank1_color + ".png", font);
        *tank2 = new Tank(tank2_on, "sprites/tanks/tank" + tank2_color + ".png", font);

        *barrel1 =  new Barrel(*tank1, "sprites/tanks/barrel" + tank1_color + ".png", "sprites/explosions/smoke_140_64.png");
        *barrel2 =  new Barrel(*tank2, "sprites/tanks/barrel" + tank2_color + ".png", "sprites/explosions/smoke_140_64.png");
    }


}
