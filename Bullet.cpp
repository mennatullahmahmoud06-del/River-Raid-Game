#include "Bullet.h"
#include "Game.h"
#include "GameConfig.h"
#include "CMUgraphicsLib/auxil.h"
#include "CMUgraphicsLib\CMUgraphics.h"


Bullet::Bullet(Game* pGame, point pos): GameObject (pGame, pos, 5, 10, YELLOW, YELLOW, GameObjectType::BULLET)
{}


Bullet::~Bullet()
{}

void Bullet::moveUp(int distance)
{RefPoint.y -= distance;}


point Bullet::getRefPoint() const
{
    return RefPoint;
}

int Bullet::getWidth() const
{
    return width;
}

int Bullet::getHeight() const
{
    return height;
}

GameObjectType Bullet::getType() const
{
    return GameObjectType::BULLET;
}

void Bullet::collisionAction()
{
    markDestroyed();
}




void Bullet::draw() const {
    // Draw the base rectangle
    window* w = pGame->getWind();
    w->SetPen(YELLOW, 1);
    w->SetBrush(YELLOW);
    w->DrawTriangle(RefPoint.x, RefPoint.y, ((RefPoint.x) + 20), RefPoint.y, ((RefPoint.x) + 10), (RefPoint.y) + 30);
}




void Bullet::setPosition(int newX, int newY) {
    x = newX;
    y = newY;
}

void Bullet::move()
{

}

