#include "CoolMole.h"

CoolMole::CoolMole()
{
	coolmole.loadFromFile("gfx/CoolMole.png");
	setTexture(&coolmole);
	setSize(sf::Vector2f(100, 100));
	setPosition(1550, 400);


	dance.addFrame(sf::IntRect(282, 387, 210, 231));
	dance.addFrame(sf::IntRect(516, 396, 195, 213));
	dance.setFrameSpeed(1.f / 2.f);

	currentAnimation = &dance;
}

void CoolMole::update(float dt)
{
	velocity.x = 0.f;
	setTextureRect(currentAnimation->getCurrentFrame());
	currentAnimation->animate(dt);
	currentAnimation = &dance;
}
