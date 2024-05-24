#include "Level.h"
Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs,sf::View* v, World* w, TileManager* tm)
{
	window = hwnd;
	input = in;
	gameState = gs;
	view = v;
	world = w;	
	tileManager = tm;
	audioManager = new AudioManager();
	

	
	audioManager->addSound("sfx/Jumping.wav", "Jump");
	audioManager->addMusic("sfx/MtGulag.wav", "bgm");

	player.setInput(input);
	playerHealth = 100;
	player.setAudio(audioManager);
	spider.setAudio(audioManager);

	//audioManager->playMusicbyName("bgm");

	world->AddGameObject(Rock1);
	world->AddGameObject(Rock);
	world->AddGameObject(player);
	world->AddGameObject(spider);
	world->AddGameObject(bat);
	world->AddGameObject(spearman);
	world->AddGameObject(pal);

	
	CollectableFont.loadFromFile("font/arial.ttf");
	CollectableText.setFont(CollectableFont);
	CollectableText.setCharacterSize(26);
	CollectableText.setFillColor(sf::Color::White);
	CollectableText.setPosition(2500, 10);

	
}

Level::~Level()
{
	//Making pointers null
	window = nullptr;
	input = nullptr;
	gameState = nullptr;
	view = nullptr;
	world = nullptr;
	tileManager = nullptr;
	if (audioManager != nullptr) {
		delete audioManager;
		audioManager = nullptr;
	}
}

void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		exit(0);
	}
	if (input->isKeyDown(sf::Keyboard::Tab))
	{
		input->setKeyUp(sf::Keyboard::Tab);
		gameState->setCurrentState(State::TILEEDITOR);
	}

	

	player.handleInput(dt);
	
	
}

// Update game objects
void Level::update(float dt)
{
	

	if (input->isKeyDown(sf::Keyboard::P))
	{
        
     }

	if (input->isLeftMousePressed())
	{
		isAttacking = true;
		
	}
	else
	{
		isAttacking = false;
	}

	if (spider.CollisionWithTag("Player") && isAttacking)
	{
		
		spider.HurtAnimation();
		
    }
	else
	{
		spider.update(dt);
	}
	
	if (damageClock.getElapsedTime() >= damageDelay)
	{
		CanBedamaged = false;
		damageClock.restart();
	}


	
	if (player.CollisionWithTag("Spider"))
	{
		if (player.getCollisionDirection() == "Down")
		{
			std::cout << "Player hit enemy from above\n";
			spider.setAlive(false);
			world->RemoveGameObject(spider);
		}
	}

	if (player.CollisionWithTag("Bat"))
	{
		if (player.getCollisionDirection() == "Down")
		{
			std::cout << "Player hit enemy from above\n";
			bat.setAlive(false);
			world->RemoveGameObject(bat);
		}
	}
		

		if (player.getCollisionDirection() == "Right")
		{
			gameState->setCurrentState(State::GAMEOVER);
			audioManager->stopAllMusic();
			player.setPosition(100, 100);
		}
		if (player.getCollisionDirection() == "Left")
		{
			gameState->setCurrentState(State::GAMEOVER);
			audioManager->stopAllMusic();
		}

		if(playerHealth <= 0)
		{
			gameState->setCurrentState(State::GAMEOVER);
			audioManager->stopAllMusic();
		}
		if (player.CollisionWithTag("Spearman"))
		{
			gameState->setCurrentState(State::GAMEOVER);
			audioManager->stopAllMusic();
			view->reset(sf::FloatRect());
		}

		if (player.CollisionWithTag("pal") && CollectableCount == 6)
		{
			gameState->setCurrentState(State::WINNINGSCREEN);
		}
		if (pal.CollisionWithTag("Player"))
		{
			std::cout << "maiu";
		}
		

	

	//Move the view to follow the player
	view->setCenter(view->getCenter().x, 360);
	//
	sf::Vector2f playerPosition = player.getPosition();
	float newX = std::max(playerPosition.x, view->getSize().x / 2.0f);
	view->setCenter(newX, view->getCenter().y);
	window->setView(*view);
	

	if (player.CollisionWithTag("pal") && CollectableCount == 6)
	{
		gameState->setCurrentState(State::WINNINGSCREEN);
	}
	if (pal.CollisionWithTag("Player"))
	{
		std::cout << "maiu";
	}

	player.update(dt);
	spider.update(dt);
	bat.update(dt);
	spearman.update(dt);
	pal.update(dt);
	
		
	
	
	if (player.CollisionWithTag("Collectable"))
	{
		CollectableCount += 1;
		std::stringstream ss;
		ss << "Collectables" << CollectableCount;
		CollectableText.setString(ss.str());
		tileManager->RemoveCollectable();
	}
	
	if (input->isKeyDown(sf::Keyboard::Enter))
	{
		audioManager->playMusicbyName("bgm");
	}
}

// Render level
void Level::render()
{
	
	if (gameState->getCurrentState() == State::LEVEL)
	{
		tileManager->render(false);
	}

	window->draw(CollectableText);
	window->draw(Rock);
	window->draw(Rock1);
	window->draw(player);
	if (spider.isAlive())
	{
		window->draw(spider);
	}
	
	if (bat.isAlive())
	{
		window->draw(bat);
	}
	window->draw(spearman);
	window->draw(pal);


	
	
	
	

	
	


	
	
	
}


void Level::adjustViewToWindowSize(unsigned int width, unsigned int height) 
{
	sf::FloatRect visibleArea(0, 0, static_cast<float>(width), static_cast<float>(height));
	view->setSize(static_cast<float>(width), static_cast<float>(height));
	view->setCenter(static_cast<float>(width) / 2, static_cast<float>(height) / 2);
}