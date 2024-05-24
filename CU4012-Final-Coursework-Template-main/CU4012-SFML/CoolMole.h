#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class CoolMole :
    public GameObject
{
    Animation dance;
    Animation* currentAnimation;
    sf::Texture coolmole;
        
public:
    CoolMole();

    void update(float dt) override;
};

