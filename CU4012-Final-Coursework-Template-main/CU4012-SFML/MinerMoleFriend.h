#pragma once
#include "FrameWork/GameObject.h"
#include "Framework/Animation.h"
class MinerMoleFriend :
    public GameObject
{
    Animation dance;
    Animation* currentAnimation;
    sf::Texture minerFriend;



public:
    MinerMoleFriend();

    void update(float dt) override;
};

