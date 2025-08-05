#pragma once
#include "Enemy.h"
class Jets :public Enemy{
public:
    Jets(Game* pgame, point ref, int width, int height, color fc, color fb) ;
    void draw() const ;
    void move();
    void erase(window* pWind);
    void collisionAction() override;
    GameObjectType getType()const override;
};

