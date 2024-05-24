#pragma once
#include "FrameWork/GameObject.h"
#include "Framework/Animation.h"
class KingMole :
    public GameObject
{
    Animation dance;
    Animation* currentAnimation;
    sf::Texture kingMole;

public: 

    KingMole();

    void update(float dt) override;
};

