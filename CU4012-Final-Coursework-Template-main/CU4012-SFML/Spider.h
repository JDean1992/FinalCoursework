#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"

class Spider :
    public GameObject
{
    int speed;
    int backwardsSpeed;
   
    
    int health;
    Animation walk;
    Animation attack;
    Animation Hurt;
    Animation* currentAnimation;
    sf::Texture SpiderSpriteSheet;
    

public:

     bool isAttacking = false;

    Spider();

    void HurtAnimation();
    

    void update(float dt) override;

   

};

