#pragma once
#include "Enemy.h"
class Tanker :public Enemy {
public:
    Tanker(Game* pGame, point ref, int width, int height, color fc, color fb);
    void draw() const;
    void move();
    void erase(window* pWind);
    void collisionAction() override;
    GameObjectType getType() const override;
};