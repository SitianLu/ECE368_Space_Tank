#include "Planet_object.h"
#include "Tank_object.h"
#include "Barrel_object.h"


class Bullet {
private:
	int x_coord;
	int y_coord;
	float mass;
	sf::Vector2f velocity;
	sf::Texture bulletTexture;
    sf::Texture explosionTexture;
public:
    //Initialization
	bool destroy = false;
	sf::Sprite bullet_shape;
    sf::Sprite explosion_shape;
    bool explosion_detected;

    //Constructor
    Bullet(int x, int y, float mass, sf::Vector2f velocity, sf::Texture* Texture_bullet, sf::Texture* Texture_explosion);

    //Position & Origin set
	void setBulletPosition(int x, int y);
    void setExplosionPosition(float x, float y);
	sf::Vector2i getPosition();
	void createBulletSprite(sf::Texture*);
    void createExplosionSprite(sf::Texture*);

    //Update position & angle & acceleration
	sf::Vector2f getAccel(planet_node* head);
	void veloChange(sf::Vector2f acceleration);
	void inc_bullet(planet_node* list_head);
	double getAngle();

    //Detect collision
    void collision_detect(Tank tank, Barrel barrel, planet_node* head);

    //Get the explosion position
    //sf::Vector2f getExplosionPosition()


};
