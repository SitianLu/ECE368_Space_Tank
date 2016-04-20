#include "Planet_object.h"
#include "Tank_object.h"
#include "Barrel_object.h"
#include "map_object.h"


class Bullet {
private:
	float x_coord;
	float y_coord;
	float mass;
	sf::Vector2f velocity;

public:
	//Initialization
	sf::Sprite bullet_shape;
	sf::Sprite explosion_shape;
	bool explosion_detected;
	int bulletSpriteCounter;
	int explosionSpriteCounter;

	//Constructor
	Bullet(sf::Vector2f position, float mass, sf::Vector2f velocity, sf::Texture* Texture_bullet, sf::Texture* Texture_explosion);

	//Position & Origin set
	void setBulletPosition(float x, float y);
	void setExplosionPosition(float x, float y);
	sf::Vector2f getPosition();
	void createBulletSprite(sf::Texture*);
	void createExplosionSprite(sf::Texture*);

	//Update position & angle & acceleration
	sf::Vector2f getAccel(planet_node* head);
	void veloChange(sf::Vector2f acceleration);
	void inc_bullet(planet_node* list_head);
	double getAngle();

	//Detect collision
	void collision_detect(Tank tank, planet_node* head, map* screen);

	//Get the explosion position
	//sf::Vector2f getExplosionPosition()


};
