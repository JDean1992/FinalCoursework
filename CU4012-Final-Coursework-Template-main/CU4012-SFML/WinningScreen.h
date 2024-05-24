#pragma once
#include "Level.h"
#include "Framework/Utilities.h"
#include "Framework/UI.h"
#include "Framework/Collision.h"
#include "MinerMoleFriend.h"
#include "KingMole.h"
#include "PlayerDanceMole.h"
#include "CoolMole.h"

class WinningScreen :
    public BaseLevel
{
public:
	WinningScreen(sf::RenderWindow* hwnd, Input* in, GameState* game);
	~WinningScreen();
	


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
	UI UIText[2];


	bool isSpriteVisible;
	sf::Clock flashTimer;


	sf::Sprite menu_sprite;
	sf::Texture menu_texture;

	sf::Vector2i MousePos;
	MinerMoleFriend minerfriend;
	KingMole kingmole;
	PlayerDanceMole dancingplayer;
	CoolMole coolmole;
	bool mouseOverAnyItem;
};

