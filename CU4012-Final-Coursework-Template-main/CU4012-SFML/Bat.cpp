#include "Bat.h"

Bat::Bat()
{
	health = 50;
	speed = 150;
	backwardsSpeed = -150;
	BatSpriteSheet.loadFromFile("gfx/BatSpriteSheet.png");
	setTexture(&BatSpriteSheet);
	setSize(sf::Vector2f(15 * 4, 21 * 3));
	setPosition(2751, 767);
	setTag("Bat");

	walk.addFrame(sf::IntRect(10, 290, 94, 40));
	walk.addFrame(sf::IntRect(135, 290, 94, 40));
	walk.addFrame(sf::IntRect(240, 277, 62, 52));
	walk.addFrame(sf::IntRect(350, 293, 75, 35));
	walk.setFrameSpeed(1.f / 5.f);

	currentAnimation = &walk;

}

void Bat::update(float dt)
{
	velocity.x = 0.f;
	setTextureRect(currentAnimation->getCurrentFrame());



	velocity.x = speed;
	currentAnimation->animate(dt);
	currentAnimation = &walk;

	if (CollisionWithTag("Wall"))
	{
		currentAnimation->setFlipped(true);
		currentAnimation->animate(dt);
		currentAnimation = &walk;

	}

	if (CollisionWithTag("Wall2"))
	{

		currentAnimation->setFlipped(false);
	}





	if (currentAnimation->getFlipped())
	{
		velocity.x = backwardsSpeed;

	}
	else
	{
		velocity.x = speed;
	}
}
