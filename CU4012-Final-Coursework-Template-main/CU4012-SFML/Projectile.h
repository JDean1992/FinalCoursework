#pragma once
#include "Framework/GameObject.h"
#include <vector>

class Projectile :
    public GameObject
{
    float speed;
    sf::Texture DynamiteTex;
    sf::Vector2f velocity;
   
    

public:

    Projectile();

    void update();

    
};

