#pragma once
//
// Created by Young on 3/26/16.
//

#include <SFML/Graphics.hpp>
#include <string>
#include "Planet_object.h"
#include "Tank_object.h"
#include "Barrel_object.h"
#include "bullet_object.h"

// collision is implemented within bullet. When the bullet is generated (shot's fired) collision is working behind the scene.
// collision occurs when the bullet texture is intersects with the other object (texture) 
// when collision is detected, then remove the bullet object, then generate the explosion.
class Collision {

private:
	Bullet* bullet;

	
	
public:

	Collision(Bullet*, Planet*, Tank*);
	void Collision::collide(Bullet, Planet, Tank);

	
};