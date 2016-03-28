#include "Planet_object.h"


class Bullet {
private:
	int x_coord;
	int y_coord;
	double mass;
	sf::Vector2f velocity;
	sf::Texture bulletTexture;
public:
	sf::CircleShape shape;
	void setPosition(int x, int y);
	sf::Vector2i getPosition();
	sf::Vector2f getAccel(sf::Vector2f position,planet_node* head);
	sf::Vector2f veloChange(sf::Vector2f acceleration);
	void inc_bullet();

};