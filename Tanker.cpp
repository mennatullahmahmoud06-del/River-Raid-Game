#include "Tanker.h"
#include "Game.h"
#include "Tanker.h"
#include "Game.h"

Tanker::Tanker(Game* pgame, point ref, int width, int height, color fc, color fb) : Enemy(pgame, ref, 80, 60, RED, BLACK, GameObjectType::TANKER_ENEMY) {};// width & height are unused here

void Tanker::draw() const {
    // Draw the Tanker at its position (x, y) with the specified color override {
        // Base position (centerX and centerY)

    window* w = pGame->getWind();
    int centerX = RefPoint.x;
    int centerY = RefPoint.y;

    // Dimensions
    int bodyWidth = 150, bodyHeight = 15;
    int deckWidth = 100, deckHeight = 10;
    int towerWidth = 20, towerHeight = 30;
    int towerTopHeight = 10;

    // Colors
    color brown = color(150, 75, 0);



    // Draw lower body (brown)
    w->SetPen(BLACK);
    w->SetBrush(brown);
    w->DrawRectangle(centerX - bodyWidth / 2, centerY, centerX + bodyWidth / 2, centerY + bodyHeight, FILLED);

    // Draw deck (black)
    w->SetBrush(BLACK);
    w->DrawRectangle(centerX - deckWidth / 2, centerY - deckHeight, centerX + deckWidth / 2, centerY, FILLED);

    // Draw tower (brown)
    w->SetBrush(brown);
    w->DrawRectangle(centerX - towerWidth / 2, centerY - towerHeight - deckHeight,
        centerX + towerWidth / 2, centerY - deckHeight, FILLED);

    // Draw top of tower (black)
    w->SetBrush(BLACK);
    w->DrawRectangle(centerX - towerWidth / 4, centerY - towerHeight - towerTopHeight - deckHeight,
        centerX + towerWidth / 4, centerY - towerHeight - deckHeight, FILLED);
}
void Tanker::move()
{
    RefPoint.y += currentSpeed;
}

void Tanker::erase(window* pWind)
{
    window* w = pGame->getWind();
    int centerX = RefPoint.x;
    int centerY = RefPoint.y;

    // Dimensions
    int bodyWidth = 150, bodyHeight = 15;
    int deckWidth = 100, deckHeight = 10;
    int towerWidth = 20, towerHeight = 30;
    int towerTopHeight = 10;

    // Colors


    // Draw lower body (brown)
    w->SetPen(LIGHTBLUE);
    w->SetBrush(LIGHTBLUE);
    w->DrawRectangle(centerX - bodyWidth / 2, centerY, centerX + bodyWidth / 2, centerY + bodyHeight, FILLED);

    // Draw deck (black)
    w->DrawRectangle(centerX - deckWidth / 2, centerY - deckHeight, centerX + deckWidth / 2, centerY, FILLED);

    // Draw tower (brown)

    w->DrawRectangle(centerX - towerWidth / 2, centerY - towerHeight - deckHeight,
        centerX + towerWidth / 2, centerY - deckHeight, FILLED);

    // Draw top of tower (black)

    w->DrawRectangle(centerX - towerWidth / 4, centerY - towerHeight - towerTopHeight - deckHeight,
        centerX + towerWidth / 4, centerY - towerHeight - deckHeight, FILLED);
}
void Tanker::collisionAction()
{


    window* w = pGame->getWind();
    int centerX = RefPoint.x;
    int centerY = RefPoint.y;

    // Dimensions
    int bodyWidth = 150, bodyHeight = 15;
    int deckWidth = 100, deckHeight = 10;
    int towerWidth = 20, towerHeight = 30;
    int towerTopHeight = 10;





    // Draw lower body (brown)
    w->SetPen(LIGHTBLUE);
    w->SetBrush(LIGHTBLUE);
    w->DrawRectangle(centerX - bodyWidth / 2, centerY, centerX + bodyWidth / 2, centerY + bodyHeight, FILLED);

    // Draw deck (black)
    w->SetBrush(LIGHTBLUE);
    w->DrawRectangle(centerX - deckWidth / 2, centerY - deckHeight, centerX + deckWidth / 2, centerY, FILLED);

    // Draw tower (brown)
    w->SetBrush(LIGHTBLUE);
    w->DrawRectangle(centerX - towerWidth / 2, centerY - towerHeight - deckHeight,
        centerX + towerWidth / 2, centerY - deckHeight, FILLED);

    // Draw top of tower (black)
    w->SetBrush(LIGHTBLUE);
    w->DrawRectangle(centerX - towerWidth / 4, centerY - towerHeight - towerTopHeight - deckHeight,
        centerX + towerWidth / 4, centerY - towerHeight - deckHeight, FILLED);
    pGame->UpdateScore(30);
    pGame->removeEnemy(this);
    markDestroyed();
}

GameObjectType Tanker::getType() const
{
    return GameObjectType::TANKER_ENEMY;
}

