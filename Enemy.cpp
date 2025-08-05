#include "Enemy.h"
#include "GameObject.h"
#include "GameConfig.h"
Enemy::Enemy(Game* pGame, point ref, int width, int height, color fc, color fb, GameObjectType type) : GameObject(pGame, ref, width, height, fc, fb, type) {

    speed = 5;
    health = 100;
    currentSpeed;
}

void Enemy::setSpeed(int newspeed)
{

    speed = newspeed;
    currentSpeed = newspeed;
}
bool Enemy::isOffScreen() const {
    return RefPoint.y > config.windHeight || RefPoint.x + width < 0 || RefPoint.x > config.windWidth;
}


point Enemy::getRefPoint() const {
    return RefPoint;
}


