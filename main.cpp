
#include<SFML/Graphics.hpp>
#include<iostream>
#include "Planet_object.h"
#include "map_object.h"
#include<string>

int main()
{



<<<<<<< HEAD

    map map1(4000,2000,"Space Tank","sprites/sky/stars.png");

    Planet planet1(500,500,2000000,150,"sprites/planets/hell.png");
    Planet planet2(1000,800,2000000,250,"sprites/planets/earth.png");
    Planet planet3(2000,300,2000000,400,"sprites/planets/pink.png");




    enum Direction{Down, Left, Right, Up};
    sf::Vector2i source(1, Down); //Tell where the animation start
/* Resize window
    sf::Vector2u size(400, 400);

    std::cout << size.x << " " << size.y << std::endl;

    Window.setSize(sf::Vector2u(400,400));
    Window.setTitle("Looks good!");
    Window.setPosition(sf::Vector2i(100,100));
*/
    sf::Clock clock;
    sf::Time time;


    std::string message = "Hello my name is your mother";
    std::string display = "";

    sf::Texture tankTexture, backgroundTexture, personTexture, planetTexture;

    sf::Sprite tankImage, backgroundImage, personImage, planet;



    if (!tankTexture.loadFromFile(("tank1.png")))
    {
        std::cout << "Error could not load tank image" << std::endl;
    }
    if (!personTexture.loadFromFile(("person.png")))
    {
        std::cout << "Error could not load person image" << std::endl;
    }
    //if (!planetTexture.loadFromFile(("Textures_of_planets/Hell(planet).png")))
    //{
    //    std::cout << "Error could not load person image" << std::endl;
    //}

    tankImage.setTexture(tankTexture);

    //backgroundImage.setTexture(backgroundTexture);

    personImage.setTexture(personTexture);

    //planet1.shape.setTexture(&planetTexture);


    tankImage.setPosition(120,220);

    int index = 0;

    map1.window.setKeyRepeatEnabled(false);

    while (map1.window.isOpen())
    {
        sf::Event Event;
        while(map1.window.pollEvent(Event))
        {

            switch(Event.type) {
                case sf::Event::Closed:
                {
                    map1.window.close();
                    break;
                }
                case sf::Event::KeyPressed:
                {
                    if (Event.key.code == sf::Keyboard::Up)
                    {
                        source.y = Up;
                    }
                    else if (Event.key.code == sf::Keyboard::Down)
                    {
                        source.y = Down;
                    }
                    else if (Event.key.code == sf::Keyboard::Left)
                    {
                        source.y = Left;
                    }
                    else if (Event.key.code == sf::Keyboard::Right)
                    {
                        source.y = Right;
                    }
                    break;
                }



                /*Text Event
                case sf::Event::TextEntered:
                {
                    std::cout << (char)Event.text.unicode << std::endl;
                }
                */
                /* Window Event
                case sf::Event::GainedFocus:
                {
                    std::cout<<"Window Active"<<std::endl;
                    break;
                }
                case sf::Event::LostFocus:
                {
                    std::cout<<"Window Not Active" <<std::endl;
                    break;
                }
                case sf::Event::Resized:
                {
                    std::cout<<"width: "<< Event.size.width<<"  Height: "<<Event.size.height<<std::endl;
                    break;
                }
                */
                /* Mouse Event
                case sf::Event::MouseEntered:
                {
                    std::cout << "Mouse within screen bounds" << std::endl;
                    break;
                }
                case sf::Event::MouseLeft:
                {
                    std::cout << "Mouse Not in screen bounds" << std::endl;
                    break;
                }
                case sf::Event::MouseMoved:
                {
                    std::cout<<"X: "<<Event.mouseMove.x << "  "<< "Y: "<< Event.mouseMove.y<<std::endl;
                    break;
                }
                case sf::Event::MouseButtonPressed:
                {
                    if(Event.mouseButton.button == sf::Mouse::Left)
                    {
                        std::cout<<"Left Button Pressed at x" << Event.mouseButton.x << "  Y:" << Event.mouseButton.y<<std::endl;
                    }
                }
                case sf::Event::MouseWheelMoved:
                {
                    std::cout << "delta: " << Event.mouseWheel.delta<<std::endl;
                }
                */


            }

            /* Keyboard event
            if (Event.type == sf::Event::KeyPressed)
            {
                if(Event.key.code == sf::Keyboard::Return && Event.key.control)
                {
                    display += message[index];
                    index++;
                    std::cout<<display<<"\n";
                }

            }
            //time = clock.getElapsedTime();
            //time = clock.restart();
            //std::cout << time.asSeconds() << std::endl;
            //clock.restart();//Reset the time and return the current lap time
            */
        }

        source.x ++;
        if (source.x * 32 >= personTexture.getSize().x)
        {
            source.x = 0;
        }
        map1.window.draw(map1.background);
        map1.window.draw(planet1.shape);
        map1.window.draw(planet2.shape);
        map1.window.draw(planet3.shape);
        map1.window.draw(tankImage);
        personImage.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32, 32));
        map1.window.draw(personImage);
        map1.window.display();
        map1.window.clear();
    }

}
