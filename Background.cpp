#include "Background.h"
#include "Game.h"


Background::Background(Game* r_pGame, point r_point, int r_width, int r_height, color fc, color bc)
    : GameObject(r_pGame, r_point, r_width, r_height, fc, bc, GameObjectType::UNKNOWN) { }


void Background::draw() const
{
   
    int x = RefPoint.x;
    int y = RefPoint.y;
    window* w = pGame->getWind();
    int stoppointx1 = width / 4;
    int stoppointx2 = stoppointx1 + width / 2; 
    w->SetPen(DARKGREEN, 2);
    w->SetBrush(DARKGREEN);
    w->DrawRectangle(x, y, x + stoppointx1, y + height);
    w->SetPen(LIGHTBLUE, 2);
    w->SetBrush(LIGHTBLUE);
    w->DrawRectangle(stoppointx1, y, x + stoppointx2, y + height);
    w->SetPen(DARKGREEN, 2);
    w->SetBrush(DARKGREEN);
    w->DrawRectangle(stoppointx2, y, width, y + height);
}
void Background::scrollDown(int speed)
{
    RefPoint.y += speed;


    const int minY = 50;
    const int maxY = 550;
    const int scrollRange = maxY - minY;

    if (RefPoint.y >= maxY) {
        RefPoint.y = minY + (RefPoint.y - maxY);
    }
}

void Background::move()
{

}
GameObjectType Background::getType() const { return GameObjectType::UNKNOWN; }
    void Background::collisionAction(){}