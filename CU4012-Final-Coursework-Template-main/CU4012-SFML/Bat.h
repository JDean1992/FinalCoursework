#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class Bat :
    public GameObject
{

    int speed;
    int backwardsSpeed;
    int health;
    sf::Texture BatSpriteSheet;
   
    Animation* currentAnimation;
    Animation walk;

public:
    Bat();

    void update(float dt) override;
};

