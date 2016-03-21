
#include<SFML/Graphics.hpp>
#include<iostream>
#include "Planet_object.h"
#include<string>

int main()
{
    sf::RenderWindow Window;
    Window.create(sf::VideoMode(1200, 775), "Space Tank", sf::Style::Default);

    enum Direction{Down, Left, Right, Up};

    Planet planet1;

    planet1.setMass(2000000);
    planet1.setRadius(50);
    planet1.createShape();
    planet1.shape.setPosition(500,500);
    planet1.createSprite("Textures_of_planets/Hell(planet).png");


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
    if (!backgroundTexture.loadFromFile(("Space_background.png")))
    {
        std::cout << "Error could not load background image" << std::endl;
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

    backgroundImage.setTexture(backgroundTexture);

    personImage.setTexture(personTexture);

    //planet1.shape.setTexture(&planetTexture);


    tankImage.setPosition(120,220);

    int index = 0;

    Window.setKeyRepeatEnabled(false);

    while (Window.isOpen())
    {
        sf::Event Event;
        while(Window.pollEvent(Event))
        {

            switch(Event.type) {
                case sf::Event::Closed:
                {
                    Window.close();
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
        Window.draw(backgroundImage);
        Window.draw(planet1.shape);
        Window.draw(tankImage);
        personImage.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32, 32));
        Window.draw(personImage);
        Window.display();
        Window.clear();
    }

}
