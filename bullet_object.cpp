#include <math.h>
#include "bullet_object.h"
#include "Global_constant.h"

Bullet::Bullet(int x, int y, float mass_in, sf::Vector2f velocity_in, std::string bullet_path, std::string explosion_path)
{
	mass = mass_in;
	velocity = velocity_in;
    explosion_detected = false;

	createBulletSprite(bullet_path);
    createExplosionSprite(explosion_path);
    setBulletPosition(x, y);
}


void Bullet::setBulletPosition(int x, int y)
{
	x_coord = x;
	y_coord = y;
	bullet_shape.setPosition(float(x), float(y));
}


sf::Vector2i Bullet::getPosition()
{
	return sf::Vector2i(x_coord, y_coord);
}



void Bullet::createBulletSprite(std::string path)
{
	sf::IntRect box(0, 0, 60, 15);
	if (!bulletTexture.loadFromFile(path))
	{
		std::cout << "Error could not load bullet image" << std::endl;
	}
	bullet_shape.setTexture(bulletTexture);
	bullet_shape.setTextureRect(box);

	bullet_shape.setOrigin(45, 7);
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
	bullet_shape.move(displacement); // Make the move happen
	double angle = getAngle(); //Get the angle of the missile
	bullet_shape.setRotation((float)angle); //Set the angle of the object to the angle of the velocity vector
	sf::Vector2f position = bullet_shape.getPosition();
	x_coord = int(position.x);
	y_coord = int(position.y);
}

double Bullet::getAngle() {

	double angle = atan2(velocity.y , velocity.x); //Get the angle of the velocity vector (from the horizontal)
	angle = angle * 180 / float(PI); //Convert from radians to degrees

	return(angle);
}

void Bullet::collision_detect(Tank tank, Barrel barrel, planet_node *head) {
	bool bul_pln_distance = false;
	bool bullet_tank_detection = false;
	bool bullet_barrel_detection = false;
	bool detected = false;

	bullet_barrel_detection = bullet_shape.getGlobalBounds().intersects(barrel.shape.getGlobalBounds());
	bullet_tank_detection = bullet_shape.getGlobalBounds().intersects(tank.shape.getGlobalBounds());

	if (bullet_barrel_detection || bullet_tank_detection) {
		detected = true;
	}

	for (planet_node* current = head; current != NULL; current = current -> next){
		bul_pln_distance = sqrt(pow(current->value->shape.getPosition().x - bullet_shape.getPosition().x, 2) + pow(current -> value -> shape.getPosition().y - bullet_shape.getPosition().y, 2)) >= (current-> value -> getRadius() + COLLISION_DETECT_OFFSET);

		if (!bul_pln_distance) {
			detected = true;
			break;
		}
	}

    if (detected) {
        explosion_detected = true;
        setExplosionPosition(bullet_shape.getPosition().x, bullet_shape.getPosition().y);
    }
}

void Bullet::createExplosionSprite(std::string explosion_path) {
    sf::IntRect box(0, 0, 65, 65);
    if (!explosionTexture.loadFromFile(explosion_path))
    {
        std::cout << "Error could not load bullet image" << std::endl;
    }
    explosion_shape.setTexture(explosionTexture);
    explosion_shape.setTextureRect(box);

    explosion_shape.setOrigin(EXPLOSION_SPRITE_OFFSET, EXPLOSION_SPRITE_OFFSET);
}

void Bullet::setExplosionPosition(float x, float y) {

    explosion_shape.setPosition(x, y);

}
