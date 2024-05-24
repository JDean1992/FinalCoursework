#include "Spearman.h"

Spearman::Spearman()
{

	SpearmanSpriteSheet.loadFromFile("gfx/Spearman.png");
	setTexture(&SpearmanSpriteSheet);
	setSize(sf::Vector2f(15 * 5, 21 * 3));
	setPosition(3398, 443);
	setTag("Spearman");
	setMass(1000.f);


	Attack.addFrame(sf::IntRect(1, 175, 177, 99));
	Attack.addFrame(sf::IntRect(179, 174, 177, 98));
	Attack.addFrame(sf::IntRect(1, 86, 224, 85));
	Attack.addFrame(sf::IntRect(0, 0, 236, 85));
	Attack.addFrame(sf::IntRect(234, 0, 225, 85));
	Attack.setFrameSpeed(1.f / 3.f);


	currentAnimation = &Attack;
}

void Spearman::update(float dt)
{
	velocity.x = 0.f;
	setTextureRect(currentAnimation->getCurrentFrame());

	currentAnimation->animate(dt);
	currentAnimation = &Attack;
	currentAnimation->setFlipped(true);

}
