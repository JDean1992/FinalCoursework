#pragma once
#include "Framework/Animation.h"
#include "Framework/GameObject.h"
class Spearman :
    public GameObject
{
    
    Animation Attack;
    Animation* currentAnimation;
    sf::Texture SpearmanSpriteSheet;

public:
    Spearman();

    void update(float dt) override;
};

