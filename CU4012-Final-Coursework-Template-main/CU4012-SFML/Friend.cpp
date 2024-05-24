#include "Friend.h"

Friend::Friend()
{
	friendTex.loadFromFile("gfx/MinerFriendSpriteSheet.png");
	setTexture(&friendTex);
	setSize(sf::Vector2f(100, 100));
	setPosition(4193, 528);
	setCollisionBox(getPosition(), getSize());
	setTag("pal");
	setMass(1000.f);


	idle.addFrame(sf::IntRect(484, 164, 230, 220));
	idle.addFrame(sf::IntRect(718, 160, 224, 222));
	idle.setFrameSpeed(1.f / 2.f);

	currentAnimation = &idle;
}

void Friend::update(float dt)
{
	velocity.x = 0.f;

	setTextureRect(currentAnimation->getCurrentFrame());
	currentAnimation->animate(dt);
	currentAnimation = &idle;
}
