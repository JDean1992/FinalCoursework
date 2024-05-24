#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class Friend :
    public GameObject
{
    sf::Texture friendTex;
    Animation idle;
    Animation* currentAnimation;

public:

    Friend();

    void update(float dt) override;
    
};

