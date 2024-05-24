#include "MinerMoleFriend.h"

MinerMoleFriend::MinerMoleFriend()
{
	minerFriend.loadFromFile("gfx/MinerFriendSpriteSheet.png");
	setTexture(&minerFriend);
	setSize(sf::Vector2f(100, 100));
	setPosition(150, 400);


	dance.addFrame(sf::IntRect(532, 434, 274, 240));
	dance.addFrame(sf::IntRect(814, 448, 224, 226));
	dance.setFrameSpeed(1.f / 2.f);

	currentAnimation = &dance;
}

void MinerMoleFriend::update(float dt)
{
	velocity.x = 0.f;

	setTextureRect(currentAnimation->getCurrentFrame());
	currentAnimation->animate(dt);
	currentAnimation = &dance;
}


