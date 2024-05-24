#include "Wall2.h"

Wall2::Wall2()
{
	RockTex.loadFromFile("gfx/Stone.jpg");
	setTexture(&RockTex);
	setPosition(2660, 677);
	setCollisionBox(sf::FloatRect(46, 137, 2660, 137));
	setSize(sf::Vector2f(46, 137));
	setTag("Wall2");
	setMass(1000.f);
}
