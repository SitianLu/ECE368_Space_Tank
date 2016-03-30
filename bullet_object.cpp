#include "bullet_object.h"
#define TIME_COEFFICIENT 0.1
#define PI 3.1415926535
Bullet::Bullet(int x, int y, double mass_in, sf::Vector2f velocity_in, std::string path)
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
	shape.setPosition(x, y);
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
		std::cout << "Error could not load tank image" << std::endl;
	}

	shape.setTexture(bulletTexture);
	shape.setTextureRect(box);
}

sf::Vector2f Bullet::getAccel(planet_node * head)
{
	//printf("getAccel is called\n");
	sf::Vector2f force(0.0, 0.0);
	planet_node* inc = head;
	while (inc != NULL)
	{
		force = force + inc->value->getGravity(x_coord, y_coord);
		inc = inc->next;

	}
	force.x /= mass;// It's not actually force at this point
	force.y /= mass;// it's acceleration
					//printf("%f %f \n", force.x, force.y);
	return force;
}



void Bullet::veloChange(sf::Vector2f acceleration)
{
	velocity.x += acceleration.x*TIME_COEFFICIENT;
	velocity.y += acceleration.y*TIME_COEFFICIENT;
}

void Bullet::inc_bullet(planet_node* list_head)
{
	sf::Vector2f acceleration = getAccel(list_head);
	veloChange(acceleration);
	sf::Vector2f displacement;
	displacement.x = velocity.x*TIME_COEFFICIENT;
	displacement.y = velocity.y*TIME_COEFFICIENT;
	sf::Vector2f tanProps(velocity.x, (-1)*velocity.y);
	float angle;
	angle = atan2(tanProps.y , tanProps.x);
	angle = angle * 180 / PI;
	angle *= -1.f;
	shape.setRotation(angle);
	printf("\nRotation is %f angle is %f\n", shape.getRotation(),angle);
	shape.move(displacement);
	sf::Vector2f position;
	position = shape.getPosition();
	x_coord = position.x;
	y_coord = position.y;
}
