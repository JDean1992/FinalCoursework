#pragma once
#include "Level.h"
#include "Framework/Utilities.h"
#include "Framework/UI.h"
#include "Framework/Collision.h"

class GameOver :
	public BaseLevel
{
public:

	GameOver(sf::RenderWindow* hwnd, Input* in, GameState* game);
	~GameOver();


	void handleInput(float dt) override;
	void update(float dt) override;
	void render() override;
	void MoveUp();
	void MoveDown();
	void updateVisualFeedback();
	int GetPressedItem() { return selectedItem; }



	sf::RenderWindow* window;
	Input* input;
	GameState* gameState;

	int selectedItem;
	sf::Font UIfont;
	sf::Font titleFont;

	sf::Text Title;
	UI UIText[3];





	sf::Sprite menu_sprite;
	sf::Texture menu_texture;

	sf::Vector2i MousePos;

	bool mouseOverAnyItem;
};

