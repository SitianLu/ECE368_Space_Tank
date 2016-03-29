#include "Planet_object.h"


class Bullet {
private:
	int x_coord;
	int y_coord;
	double mass;
	sf::Vector2f velocity;
	sf::Texture bulletTexture;
public:
	bool destroy = false;
	sf::Sprite shape;
	Bullet(int x, int y, double mass, sf::Vector2f velocity, std::string path);
	void setPosition(int x, int y);
	sf::Vector2i getPosition();

	void createSprite(std::string);
	sf::Vector2f getAccel(planet_node* head);
	void veloChange(sf::Vector2f acceleration);
	void inc_bullet(planet_node* list_head);

};
