#include "Jet.h"
#include "Game.h" 

Jet::Jet(Game* pGame, point ref)
    : GameObject(pGame, ref, 90, 60, LIGHTBLUE, BLACK) {
}  

void Jet::draw() const
{
    window* w = pGame->getWind();

    int x = RefPoint.x;
    int y = RefPoint.y;

    w->SetPen(BLACK);
    w->SetBrush(LIGHTBLUE);
    w->DrawCircle(x + 15, y + 15, 15);

    w->SetPen(BLACK);
    w->SetBrush(DARKSLATEGRAY);
    w->DrawEllipse(x - 15, y + 13.5, x + 45, y + 30);

    w->SetPen(BLACK);
    w->SetBrush(LIGHTBLUE);
    w->DrawCircle(x, y + 21, 1.5);
    w->DrawCircle(x + 15, y + 21, 1.5);
    w->DrawCircle(x + 30, y + 21, 1.5);
}
