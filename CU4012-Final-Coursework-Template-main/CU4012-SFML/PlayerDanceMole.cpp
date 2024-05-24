#include "PlayerDanceMole.h"

PlayerDanceMole::PlayerDanceMole()
{
	PlayerDancing.loadFromFile("gfx/MinerMoleSprite.png");
	setTexture(&PlayerDancing);
	setSize(sf::Vector2f(100, 100));
	setPosition(550, 400);

	dance.addFrame(sf::IntRect(55, 278, 40, 33));
	dance.addFrame(sf::IntRect(105, 265, 37, 45));
	dance.setFrameSpeed(1.f / 2.f);

	currentAnimation = &dance;
}

void PlayerDanceMole::update(float dt)
{
	velocity.x = 0.f;
	setTextureRect(currentAnimation->getCurrentFrame());
	currentAnimation->animate(dt);
	currentAnimation = &dance;
}
