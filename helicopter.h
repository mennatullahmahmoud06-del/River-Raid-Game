#pragma once
#include "Enemy.h"
class helicopter :public Enemy {
public:
    bool movingRight;
    helicopter(Game* pgame, point ref, int width, int height, color fc, color fb) :Enemy(pgame, ref, 120, 30, fc, fb, GameObjectType::HELICOPTER_ENEMY) {};
    void draw() const;
    GameObjectType getType()const override;
    void collisionAction()override;
    void move();
    void erase(window* pWind);
};