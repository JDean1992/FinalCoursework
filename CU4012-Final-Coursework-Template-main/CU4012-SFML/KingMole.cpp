#include "KingMole.h"

KingMole::KingMole()
{
	kingMole.loadFromFile("gfx/KingMole.png");
	setTexture(&kingMole);
	setSize(sf::Vector2f(100, 100));
	setPosition(1250, 400);

	dance.addFrame(sf::IntRect(165, 3005, 730, 795));
	dance.addFrame(sf::IntRect(995, 2755, 860, 980));
	dance.setFrameSpeed(1.f / 2.f);

	currentAnimation = &dance;
}

void KingMole::update(float dt)
{
	velocity.x = 0.f;
	setTextureRect(currentAnimation->getCurrentFrame());
	currentAnimation->animate(dt);
	currentAnimation = &dance;
}
