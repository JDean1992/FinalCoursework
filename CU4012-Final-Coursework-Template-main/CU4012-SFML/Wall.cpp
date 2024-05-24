#include "Wall.h"

Wall::Wall()
{
	RockTex.loadFromFile("gfx/Stone.jpg");
	setTexture(&RockTex);
	setPosition(1425, 654);
	setCollisionBox(sf::FloatRect(40, 40, 1406, 654));
	setSize(sf::Vector2f(50, 50));
	setTag("Wall1");
	setMass(1000.f);

}