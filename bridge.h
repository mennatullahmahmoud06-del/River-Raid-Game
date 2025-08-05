#pragma once
#include "Enemy.h"

class Bridge :public Enemy{
public:
    Bridge(Game* pgame, point ref, int width, int height, color fc, color fb);
    void draw( ) const;
    void move();
    void erase(window* pWind);
    GameObjectType getType()const override;
    void collisionAction() override;
};

