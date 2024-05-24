#include "GameOver.h"


GameOver::GameOver(sf::RenderWindow* hwnd, Input* in, GameState* game)
{
	window = hwnd;
	input = in;
	gameState = game;
	audioManager = new AudioManager();


	UIfont.loadFromFile("font/BloodyFont.ttf");
	titleFont.loadFromFile("font/BloodyFont.ttf");

	audioManager->addMusic("sfx/YouAreDead.wav", "GameOverBGM");


	menu_texture.loadFromFile("gfx/MinermoleKO.png");
	menu_sprite.setTexture(menu_texture);
	menu_sprite.setScale(1, 1);
	menu_sprite.setPosition(550, 600);

	

	


	Title.setFont(titleFont);
	Title.setFillColor(sf::Color::Red);
	Title.setString("Game Over");
	Title.setOutlineColor(sf::Color::Black);
	Title.setCharacterSize(150);
	Title.setPosition(500, 50);


	UIText[0].text.setFont(UIfont);
	UIText[0].text.setFillColor(sf::Color::Red);
	UIText[0].text.setString("Restart");
	UIText[0].text.setPosition(sf::Vector2f(900, 450));



	UIText[1].text.setFont(UIfont);
	UIText[1].text.setFillColor(sf::Color::White);
	UIText[1].text.setString("Main Menu");
	UIText[1].text.setPosition(sf::Vector2f(900, 500));

	UIText[2].text.setFont(UIfont);
	UIText[2].text.setFillColor(sf::Color::White);
	UIText[2].text.setString("Exit");
	UIText[2].text.setPosition(sf::Vector2f(900, 550));



	selectedItem = 0;

	
}

GameOver::~GameOver()
{
}

void GameOver::handleInput(float dt)
{
	// Keyboard handling for menu navigation
	if (input->isKeyDown(sf::Keyboard::Up)) {
		MoveUp();
		input->setKeyUp(sf::Keyboard::Up);
		
	}

	if (input->isKeyDown(sf::Keyboard::Down)) {
		MoveDown();
		input->setKeyUp(sf::Keyboard::Down);
		;
	}

	// Execute action for the current selected item
	if (input->isKeyDown(sf::Keyboard::Enter) || (input->isLeftMouseDown() && mouseOverAnyItem)) {
		switch (selectedItem) {
		case 0:
			std::cout << "Restart Button has been pressed" << std::endl;
			input->setKeyUp(sf::Keyboard::Enter);
			gameState->setCurrentState(State::LEVEL);
			audioManager->stopAllMusic();
			
			break;
		case 1:
			std::cout << "Main Menu has been pressed" << std::endl;
			input->setKeyUp(sf::Keyboard::Enter);
			gameState->setCurrentState(State::MENU);
			audioManager->stopAllMusic();
			
			break;
		case 2:
			exit(0);
		}

		// Reset input states
		if (input->isKeyDown(sf::Keyboard::Enter)) {
			input->setKeyUp(sf::Keyboard::Enter);

		}
		if (input->isLeftMouseDown()) {
			input->setLeftMouse(Input::MouseState::UP); // Assuming you have a method to reset the mouse state
		}
	}
	if (input->isKeyDown(sf::Keyboard::F))
	{
		audioManager->playMusicbyName("GameOverBGM");
	}
}

void GameOver::update(float dt)
{
	

	updateVisualFeedback(); // Update visual feedback at the end to reflect any changes
}

void GameOver::render()
{
	window->clear(sf::Color(0, 0, 0));
	window->draw(menu_sprite);
	window->draw(Title);
	for (int i = 0; i < 3; i++)
	{
		window->draw(UIText[i].text);
	}
}

void GameOver::MoveUp()
{
	if (selectedItem - 1 >= 0)
	{
		UIText[selectedItem].text.setFillColor(sf::Color::White);
		selectedItem--;
		UIText[selectedItem].text.setFillColor(sf::Color::Red);
	}
}

void GameOver::MoveDown()
{
	if (selectedItem + 1 < 3)
	{
		UIText[selectedItem].text.setFillColor(sf::Color::White);
		selectedItem++;
		UIText[selectedItem].text.setFillColor(sf::Color::Red);
	}
}

void GameOver::updateVisualFeedback()
{
	for (int i = 0; i <3; i++) {
		if (i == selectedItem) {
			UIText[i].text.setFillColor(sf::Color::Red); // Highlight selected item
		}
		else {
			UIText[i].text.setFillColor(sf::Color::White); // Default color for non-selected items
		}
	}
}
