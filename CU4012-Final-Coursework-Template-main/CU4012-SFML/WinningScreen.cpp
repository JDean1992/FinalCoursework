#include "WinningScreen.h"

WinningScreen::WinningScreen(sf::RenderWindow* hwnd, Input* in, GameState* game)
{
	window = hwnd;
	input = in;
	gameState = game;
	audioManager = new AudioManager();


	UIfont.loadFromFile("font/SamuraiBlast.ttf");
	titleFont.loadFromFile("font/SuperPixel.ttf");

	audioManager->addMusic("sfx/DancingTrack.wav", "WinningScreenBGM");


	menu_texture.loadFromFile("gfx/Disco.jpg");
	menu_sprite.setTexture(menu_texture);
	menu_sprite.setScale(4.1f, 3.f);
	

	




	Title.setFont(titleFont);
	Title.setFillColor(sf::Color::Yellow);
	Title.setString("You Win");
	Title.setOutlineColor(sf::Color::Black);
	Title.setCharacterSize(150);
	Title.setPosition(500, 50);


	UIText[0].text.setFont(UIfont);
	UIText[0].text.setFillColor(sf::Color::Blue);
	UIText[0].text.setString("Restart");
	UIText[0].text.setPosition(sf::Vector2f(900, 450));



	UIText[1].text.setFont(UIfont);
	UIText[1].text.setFillColor(sf::Color::White);
	UIText[1].text.setString("Main Menu");
	UIText[1].text.setPosition(sf::Vector2f(900, 500));

	
}

WinningScreen::~WinningScreen()
{
}

void WinningScreen::handleInput(float dt)
{
	// Keyboard handling for menu navigation
	if (input->isKeyDown(sf::Keyboard::Up)) {
		MoveUp();
		input->setKeyUp(sf::Keyboard::Up);
		
	}

	if (input->isKeyDown(sf::Keyboard::Down)) {
		MoveDown();
		input->setKeyUp(sf::Keyboard::Down);
		
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
		audioManager->playMusicbyName("WinningScreenBGM");
	}
}

void WinningScreen::update(float dt)
{
	//makes the screen flash every 0.3 seconds
	sf::Time elaspsed = flashTimer.getElapsedTime();
	if (elaspsed.asMilliseconds() >= 300)
	{
		isSpriteVisible = !isSpriteVisible;
		flashTimer.restart();
	}

	minerfriend.update(dt);
	kingmole.update(dt);
	dancingplayer.update(dt);
	coolmole.update(dt);
}

void WinningScreen::render()
{
	
	if (isSpriteVisible)
	{
		//draws the background if it isn't invisible
		window->draw(menu_sprite);
	}
	window->draw(Title);
	for (int i = 0; i < 2; i++)
	{
		window->draw(UIText[i].text);
	}
	window->draw(minerfriend);
	window->draw(kingmole);
	window->draw(dancingplayer);
	window->draw(coolmole);
}

void WinningScreen::MoveUp()
{
	if (selectedItem - 1 >= 0)
	{
		UIText[selectedItem].text.setFillColor(sf::Color::White);
		selectedItem--;
		UIText[selectedItem].text.setFillColor(sf::Color::Blue);
	}
}

void WinningScreen::MoveDown()
{
	if (selectedItem + 1 < 2)
	{
		UIText[selectedItem].text.setFillColor(sf::Color::White);
		selectedItem++;
		UIText[selectedItem].text.setFillColor(sf::Color::Blue);
	}
}

void WinningScreen::updateVisualFeedback()
{
	for (int i = 0; i < 2; i++) {
		if (i == selectedItem) {
			UIText[i].text.setFillColor(sf::Color::Blue); // Highlight selected item
		}
		else {
			UIText[i].text.setFillColor(sf::Color::White); // Default color for non-selected items
		}
	}
}
