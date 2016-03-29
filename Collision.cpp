#include "Collision.h"
#include <iostream>

Collision::Collision(Bullet* bullet, Planet* planet, Tank* tank)
{
	collide(*bullet, *planet, *tank);

}
void Collision::collide(Bullet bullet, Planet planet, Tank tank)
{
	if ((bullet.shape.getGlobalBounds().intersects(planet.shape.getGlobalBounds()))
		|| (bullet.shape.getGlobalBounds().intersects(tank.shape.getGlobalBounds())))
	{
		sf::Texture textureExplosion;
		if (!textureExplosion.loadFromFile("sprites/explosions/explosion_1fix.png"))
		{
			std::cout << "Error could not load explosion image" << std::endl;
		}

		sf::Sprite explosion(textureExplosion);
		explosion.setTextureRect(sf::IntRect(0, 0, 76, 76));
	}

}