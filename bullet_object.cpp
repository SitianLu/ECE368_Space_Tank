#include <math.h>
#include "bullet_object.h"
#include "Global_constant.h"

Bullet::Bullet(int x, int y, float mass_in, sf::Vector2f velocity_in, std::string path)
{
	mass = mass_in;
	velocity = velocity_in;

	createSprite(path);
	setPosition(x, y);
}


void Bullet::setPosition(int x, int y)
{
	x_coord = x;
	y_coord = y;
	shape.setPosition(float(x), float(y));
}


sf::Vector2i Bullet::getPosition()
{
	return sf::Vector2i(x_coord, y_coord);
}



void Bullet::createSprite(std::string path)
{
	sf::IntRect box(0, 0, 60, 15);
	if (!bulletTexture.loadFromFile(path))
	{
		std::cout << "Error could not load bullet image" << std::endl;
	}
	shape.setTexture(bulletTexture);
	shape.setTextureRect(box);

	shape.setOrigin(45,7);
}


sf::Vector2f Bullet::getAccel(planet_node * head)
{
	sf::Vector2f force(0.0, 0.0);
	planet_node* inc = head;
	while (inc != NULL) //Go through every planet in the list
	{
		force = force + inc->value->getGravity(x_coord, y_coord); // Increase the total force by the force from the planet
		inc = inc->next;

	}
	force.x /= mass;// It's not actually force at this point
	force.y /= mass;// it's acceleration
	return force;
}



void Bullet::veloChange(sf::Vector2f acceleration)
{ //Function makes changes to velocity using the recieved acceleration
	velocity.x += acceleration.x*float(TIME_COEFFICIENT);
	velocity.y += acceleration.y*float(TIME_COEFFICIENT);
}

void Bullet::inc_bullet(planet_node* list_head)
{
	sf::Vector2f acceleration = getAccel(list_head); //Get the total acceleration on this iteration
	veloChange(acceleration); // Modify the velocity using the recieved acceleration
	sf::Vector2f displacement; //The amount of movement in one iteration
	displacement.x = velocity.x*float(TIME_COEFFICIENT);
	displacement.y = velocity.y*float(TIME_COEFFICIENT);
	shape.move(displacement); // Make the move happen
	float angle = atan2(velocity.y , velocity.x); //Get the angle of the velocity vector (from the horizontal)
	angle = angle * 180 / float(PI); //Convert from radians to degrees
	shape.setRotation(angle); //Set the angle of the object to the angle of the velocity vector
	sf::Vector2f position = shape.getPosition();
	x_coord = int(position.x);
	y_coord = int(position.y);
}
