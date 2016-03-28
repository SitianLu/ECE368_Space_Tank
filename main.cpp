
#include <SFML/Graphics.hpp>
#include <iostream>
#include "bullet_object.h"
#include "map_object.h"
#include "Tank_object.h"
#include "Barrel_object.h"
#include <string>

int main()
{

    map map1(1800, 800, "Space Tank");
    
    Planet planet1(1,500,500,2000000,150,"sprites/planets/red.png");
    Planet planet2(2,300,300,2000000,250,"sprites/planets/earth_no_margin.png");
    Planet planet3(3,1300,300,2000000,300,"sprites/planets/pink.png");
    
    
    //planet1.shape.setOrigin(planet1.getCenterX(),planet1.getCenterY());
    
    Tank tank1(&planet2, "sprites/tanks/tank1.png");
    Barrel barrel1(&tank1, "sprites/tanks/barrel1.png");

	planet_node *head = new planet_node;
	head->value = &planet1;
	head->next = new planet_node;
	head->next->value = &planet2;
	head->next->next = new planet_node;
	head->next->next->value = &planet3;
	head->next->next->next = NULL;
	map1.head = head;


    
    
    
    enum Direction{Down, Left, Right, Up};
    float frameCounter = 0, switchFrame = 10, frameSpeed = 500;
    sf::Vector2i source(1, Down); //Tell where the animation start

    sf::Clock clock;
    sf::Time time;

    barrel1.setTank(&tank1);


    int index = 0;
    
    map1.window.setKeyRepeatEnabled(false);
    
    while (map1.window.isOpen())
    {
        sf::Event Event;
        while(map1.window.pollEvent(Event))
        {
            
            switch(Event.type) {
                case sf::Event::Closed: {
                    map1.window.close();
                    break;
                }
            }

        }

        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            source.y = Up;
            //tank1.shape.move(0, -1);
            barrel1.shape.rotate(1.0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            source.y = Down;
            //tank1.shape.move(0, 1);
            barrel1.shape.rotate(-1.0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            source.y = Left;
            tank1.shape.move(-1, 0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            source.y = Right;
            tank1.shape.move(1, 0);
        }

        frameCounter += frameSpeed * clock.restart().asSeconds();
        if (frameCounter >= switchFrame) {
            frameCounter = 0;

            // Any Anomation update goes here
			planet1.shape.rotate(1);
        }
        
        
        map1.window.draw(map1.background);
        map1.window.draw(planet1.shape);
        map1.window.draw(planet2.shape);
        map1.window.draw(planet3.shape);
        map1.window.draw(barrel1.shape);
        map1.window.draw(tank1.shape);
        map1.window.display();
        map1.window.clear();
    }
    
    
}
