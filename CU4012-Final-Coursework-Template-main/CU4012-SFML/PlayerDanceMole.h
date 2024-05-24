#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class PlayerDanceMole :
    public GameObject
{
    Animation dance;
    Animation* currentAnimation;
    sf::Texture PlayerDancing;

public: 

    PlayerDanceMole();

    void update(float dt) override;
};

