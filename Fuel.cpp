#include "Fuel.h"
#include "Game.h"
Fuel::Fuel(Game* r_pGame, point r_point, int r_width, int r_height, color fc, color bc)
    : GameObject(r_pGame, r_point, r_width, r_height, fc, bc, GameObjectType::FUEL)
{
}


void Fuel::draw() const {
    // Draw the base rectangle
    int x = RefPoint.x;
    int y = RefPoint.y;
    window* w = pGame->getWind();
    w->SetBrush(NAVYBLUE);
    w->DrawRectangle(x, y, x + width, y + height);

    // Add fuel symbol
    w->SetPen(YELLOW, 1);
    w->SetBrush(YELLOW);
    w->DrawCircle(x + width / 2, y + 10, 8);

    // Label
    w->SetPen(WHITE, 2);
    w->SetFont(16, BOLD, BY_NAME, "Arial");
    w->DrawString(x + 5, y + height / 2, "FUEL");
}
void Fuel::move()
{

}
GameObjectType Fuel::getType() const
{
    return GameObjectType::FUEL;
}

void Fuel::collisionAction()
{
    int x = RefPoint.x;
    int y = RefPoint.y;
    window* w = pGame->getWind();
    w->SetBrush(LIGHTBLUE);
    w->DrawRectangle(x, y, x + width, y + height);

    // Add fuel symbol
    w->SetPen(LIGHTBLUE, 1);
    w->SetBrush(LIGHTBLUE);
    w->DrawCircle(x + width / 2, y + 10, 8);

    // Label
    w->SetPen(LIGHTBLUE, 2);
    w->SetFont(16, BOLD, BY_NAME, "Arial");
    w->DrawString(x + 5, y + height / 2, "FUEL");

    pGame->removeFuel(this);
    markDestroyed();
}
