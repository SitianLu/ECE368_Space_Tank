
#include<SFML/Graphics.hpp>
#include<iostream>

int main()
{
    sf::RenderWindow Window;
    Window.create(sf::VideoMode(800,600), "Space Tank");

    while (Window.isOpen())
    {
        sf::Event Event;
        while(Window.pollEvent(Event))
        {
            if (Event.type == sf::Event::Closed)
            {
                Window.close();
            }
            Window.display();
        }
    }

}


