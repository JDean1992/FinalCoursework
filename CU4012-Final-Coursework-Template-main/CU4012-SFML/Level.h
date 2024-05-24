#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include "Framework/GameState.h"
#include "Framework/World.h"
#include "Framework/TileManager.h"
#include "Framework/AudioManager.h"
#include "Framework/Animation.h"
#include <string>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Spider.h"
#include "Wall.h"
#include "Wall2.h"
#include "Bat.h"
#include "Spearman.h"
#include "Friend.h"
#include "sstream"


class Level : public BaseLevel{
public:
	Level(sf::RenderWindow* hwnd, Input* in, GameState* gs,sf::View* view ,World* w, TileManager* tm);
	~Level();

	void handleInput(float dt) override;
	void update(float dt) override;
	void render();
	void adjustViewToWindowSize(unsigned int width, unsigned int height);
private:
	// Default variables for level class.

	Animation Hurt;
	Animation* currentAnimation;



	Player player;
	Spider spider;
	Wall Rock;
	Wall2 Rock1;
	bool isAttacking;
	Bat bat;
	Spearman spearman;
	Friend pal;
	
	sf::Font CollectableFont;
	sf::Text CollectableText;
	int CollectableCount = 0;

	bool CanBedamaged = false;

	sf::Clock damageClock;
	const sf::Time damageDelay = sf::seconds(2.0f);

	int playerHealth;

	
};