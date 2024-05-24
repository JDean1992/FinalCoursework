#include "Projectile.h"

Projectile::Projectile()
{
	speed = 500;
	DynamiteTex.loadFromFile("gfx/Collectable.png");
	setTexture(&DynamiteTex);
	setSize(sf::Vector2f(10, 10));
	setCollisionBox(getPosition(), getSize());
	setTag("Bullet");
}

void Projectile::update()
{
}
