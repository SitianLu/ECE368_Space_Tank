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
	void createShape();
	void createSprite(std::string);
	sf::Vector2f getAccel(planet_node* head);
	void veloChange(sf::Vector2f acceleration);
	void inc_bullet(planet_node* list_head);

};