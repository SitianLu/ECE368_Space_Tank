#include "bullet_object.h"

void Bullet::setPosition(int x, int y)
{
	x_coord = x;
	y_coord = y;
}

sf::Vector2i Bullet::getPosition()
{
	return sf::Vector2i(x_coord,y_coord);
}

void Bullet::createShape()
{
	sf::CircleShape base_circle(50.f);//Size of the bullet(subject to change)
	shape = base_circle;
}

void Bullet::createSprite(std::string path)
{
	if (!bulletTexture.loadFromFile(path))
	{
		std::cout << "Error could not load bullet image" << std::endl;
	}
	bulletTexture.setSmooth(true);
	shape.setTexture(&bulletTexture);
}

sf::Vector2f Bullet::getAccel( planet_node * head)
{
	sf::Vector2f force(0.0,0.0);
	planet_node* inc = head;
	while (inc->next != NULL)
	{
		force = force + inc->value->getGravity(x_coord,y_coord);
		inc = inc->next;
	}
	force.x /= mass;// It's not actually force at this point
	force.y /= mass;// it's acceleration
	return force;
}



void Bullet::veloChange(sf::Vector2f acceleration)
{
	velocity += acceleration;
}

void Bullet::inc_bullet(planet_node* list_head)
{

}
