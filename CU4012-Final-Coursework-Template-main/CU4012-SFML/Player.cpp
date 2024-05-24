#include "Player.h"

Player::Player()
{
	speed = 200;
	
	
	MoleSpriteSheet.loadFromFile("gfx/MinermoleSprite.png");
	setSize(sf::Vector2f(15*4 ,21*3));
	setPosition(100, 100);
	setTexture(&MoleSpriteSheet);
	setTag("Player");
		

	walk.addFrame(sf::IntRect(405, 68, 40, 35));
	walk.addFrame(sf::IntRect(5, 120, 40, 35));
	walk.addFrame(sf::IntRect(55, 116, 40, 40));
	walk.addFrame(sf::IntRect(104, 114, 40, 40));
	walk.addFrame(sf::IntRect(155, 116, 40, 40));
	walk.addFrame(sf::IntRect(204, 118, 40, 35));
	walk.addFrame(sf::IntRect(255, 120, 40, 35));
	walk.setFrameSpeed(1.f / 8.f);

	jump.addFrame(sf::IntRect(105, 57, 40, 50));
	jump.addFrame(sf::IntRect(154, 51, 40, 43));
	jump.addFrame(sf::IntRect(205, 51, 40, 43));
	jump.addFrame(sf::IntRect(260, 57, 34, 50));
	jump.addFrame(sf::IntRect(304, 55, 40, 50));
	jump.addFrame(sf::IntRect(355, 69, 40, 34));
	jump.setFrameSpeed(1.f / 10.f);

	Attack.addFrame(sf::IntRect(205, 228, 42, 35));
	Attack.addFrame(sf::IntRect(257, 224, 40, 35));
	Attack.setFrameSpeed(1.f / 2.f);
	
	


	currentAnimation = &walk;

	
		
}

void Player::handleInput(float dt)
{
	velocity.x = 0.f;

	

	setTextureRect(currentAnimation->getCurrentFrame());
	


	if (input->isKeyDown(sf::Keyboard::A))
	{
		velocity.x = -speed;
		currentAnimation = &walk;
		currentAnimation->animate(dt);
		currentAnimation->setFlipped(true);
	}
	else if (input->isKeyDown(sf::Keyboard::D))
	{
		velocity.x = speed;
		currentAnimation = &walk;
		currentAnimation->animate(dt);
		currentAnimation->setFlipped(false);
		
	}
	

	if (input->isKeyDown(sf::Keyboard::Space) && canJump)
	{
		Jump(200.f);

		currentAnimation = &jump;
		currentAnimation->animate(dt);
		
		audio->playSoundbyName("Jump");

	}
	



	if (input->isLeftMouseDown())
	{

		currentAnimation = &Attack;
		currentAnimation->animate(dt);
		isAttacking = true;
		
		
	}
	else
	{
		
		isAttacking = false;
	}
	
		
	
	
}




void Player::update(float dt)
{

	if (damageClock.getElapsedTime() >= damageDelay)
	{
		Canbedamaged = false;
		damageClock.restart();
	}
	else
	{
		Canbedamaged = true;
	}

	
	if (isAttacking = true)
	{
		Canbedamaged = false;
	}

	

	


	





	if (CollisionWithTag("Spider") && isAttacking)
	{
		audio->playSoundbyName("Punch");
		
	}
	
	
	
	
	
	
}


