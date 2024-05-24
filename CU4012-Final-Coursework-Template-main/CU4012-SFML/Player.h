#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
#include "Framework/World.h"
#include "Framework/GameState.h"
#include <chrono>


class Player :
    public GameObject
{
    int speed;
    
    Animation walk;
    Animation jump;
    Animation  Attack;
    Animation* currentAnimation;
    sf::Texture MoleSpriteSheet;
    sf::Clock clock;
    GameState* gamestate;
    bool isdead = false;
    bool Canbedamaged = true;
    sf::Clock damageClock;
    const sf::Time damageDelay = sf::seconds(2.0f);
    

    
    

public:
    
    bool isAttacking;
   
    bool dead;

    Player();
    

    void handleInput(float dt) override;

   

    void update(float dt) override;

        
};

