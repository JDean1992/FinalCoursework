#include "Spider.h"

Spider::Spider()
{
	health = 100;
	speed = 100;
	
	backwardsSpeed = -100;
	

	SpiderSpriteSheet.loadFromFile("gfx/SpiderSpriteSheet.png");
	setTexture(&SpiderSpriteSheet);
	setSize(sf::Vector2f(15 * 4, 21 * 3));
	setPosition(1557, 637);
	setTag("Spider");

	walk.addFrame(sf::IntRect(135, 379, 90, 47));
	walk.addFrame(sf::IntRect(225, 379, 86, 47));
	walk.addFrame(sf::IntRect(310, 379, 90, 47));
	walk.addFrame(sf::IntRect(396, 379, 86, 47));
	walk.setFrameSpeed(1.f / 4.f);

	currentAnimation = &walk;
}

void Spider::HurtAnimation()
{
	Hurt.addFrame(sf::IntRect(150, 324, 74, 40));
	Hurt.addFrame(sf::IntRect(243, 321, 74, 42));
	Hurt.addFrame(sf::IntRect(335, 323, 74, 40));
	Hurt.addFrame(sf::IntRect(437, 326, 80, 38));
	walk.setFrameSpeed(1.f / 1.f);
	currentAnimation = &Hurt;
	
}



void Spider::update(float dt)
{
	velocity.x = 0.f;
	setTextureRect(currentAnimation->getCurrentFrame());

	
	
	velocity.x = speed;
	currentAnimation->animate(dt);
	//currentAnimation = &walk;

	if (CollisionWithTag("Wall"))
	{
		currentAnimation->setFlipped(true);
		currentAnimation->animate(dt);
		currentAnimation = &walk;
		
	}

	if (CollisionWithTag("Wall1"))
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
