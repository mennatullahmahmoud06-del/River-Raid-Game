#include "helicopter.h"
#include "Game.h"

void helicopter::draw() const {


    // Center position
    int centerX = RefPoint.x;
    int centerY = RefPoint.y;

    // Dimensions
    int bodyWidth = 120, bodyHeight = 30;
    int cockpitRadius = 15;
    int tailLength = 80, tailHeight = 10;
    int topRotorLength = 140, rotorWidth = 6;
    int tailRotorLength = 20;
    int skidLength = 100, skidHeight = 5;

    // Colors
    color green = color(34, 139, 34);
    color gray = color(100, 100, 100);
    color black = BLACK;

    // Draw main body
    window* w = pGame->getWind();

    w->SetPen(black);
    w->SetBrush(green);
    w->DrawRectangle(centerX - bodyWidth / 2, centerY,
        centerX + bodyWidth / 2, centerY + bodyHeight, FILLED);

    // Draw cockpit (front circle)
    w->SetBrush(gray);
    w->DrawCircle(centerX - bodyWidth / 2, centerY + bodyHeight / 2, cockpitRadius, FILLED);

    // Draw tail
    w->SetBrush(green);
    w->DrawRectangle(centerX + bodyWidth / 2, centerY + bodyHeight / 2 - tailHeight / 2,
        centerX + bodyWidth / 2 + tailLength, centerY + bodyHeight / 2 + tailHeight / 2, FILLED);

    // Draw top rotor
    w->SetBrush(BLACK);
    w->DrawRectangle(centerX - topRotorLength / 2, centerY - 20,
        centerX + topRotorLength / 2, centerY - 20 + rotorWidth, FILLED);

    // Draw tail rotor (vertical small blade)
    int tailX = centerX + bodyWidth / 2 + tailLength;
    int tailY = centerY + bodyHeight / 2;
    w->DrawRectangle(tailX - rotorWidth / 2, tailY - tailRotorLength / 2,
        tailX + rotorWidth / 2, tailY + tailRotorLength / 2, FILLED);

    // Draw skids (landing gear)
    w->SetBrush(BLACK);
    int skidY = centerY + bodyHeight + 10;
    w->DrawRectangle(centerX - skidLength / 2, skidY,
        centerX + skidLength / 2, skidY + skidHeight, FILLED);
}
void helicopter::move()
{
    if (movingRight)
        RefPoint.x += currentSpeed;
    else
        RefPoint.x -= currentSpeed;

    if (RefPoint.x <= 300) movingRight = true;
    else if (RefPoint.x + width >= 900) movingRight = false;
}

void helicopter::erase(window* pWind)
{

    // Center position
    int centerX = RefPoint.x;
    int centerY = RefPoint.y;

    // Dimensions
    int bodyWidth = 120, bodyHeight = 30;
    int cockpitRadius = 15;
    int tailLength = 80, tailHeight = 10;
    int topRotorLength = 140, rotorWidth = 6;
    int tailRotorLength = 20;
    int skidLength = 100, skidHeight = 5;

    // Colors
    color green = color(34, 139, 34);
    color gray = color(100, 100, 100);
    color black = BLACK;

    // Draw main body
    window* w = pGame->getWind();

    w->SetPen(LIGHTBLUE);
    w->SetBrush(LIGHTBLUE);
    w->DrawRectangle(centerX - bodyWidth / 2, centerY,
        centerX + bodyWidth / 2, centerY + bodyHeight, FILLED);

    // Draw cockpit (front circle)

    w->DrawCircle(centerX - bodyWidth / 2, centerY + bodyHeight / 2, cockpitRadius, FILLED);

    // Draw tail
    w->DrawRectangle(centerX + bodyWidth / 2, centerY + bodyHeight / 2 - tailHeight / 2,
        centerX + bodyWidth / 2 + tailLength, centerY + bodyHeight / 2 + tailHeight / 2, FILLED);

    // Draw top rotor

    w->DrawRectangle(centerX - topRotorLength / 2, centerY - 20,
        centerX + topRotorLength / 2, centerY - 20 + rotorWidth, FILLED);

    // Draw tail rotor (vertical small blade)
    int tailX = centerX + bodyWidth / 2 + tailLength;
    int tailY = centerY + bodyHeight / 2;
    w->DrawRectangle(tailX - rotorWidth / 2, tailY - tailRotorLength / 2,
        tailX + rotorWidth / 2, tailY + tailRotorLength / 2, FILLED);

    // Draw skids (landing gear)

    int skidY = centerY + bodyHeight + 10;
    w->DrawRectangle(centerX - skidLength / 2, skidY,
        centerX + skidLength / 2, skidY + skidHeight, FILLED);
}

GameObjectType helicopter::getType()const
{
    return GameObjectType::HELICOPTER_ENEMY;
}

void helicopter::collisionAction()
{
    int centerX = RefPoint.x;
    int centerY = RefPoint.y;

    // Dimensions
    int bodyWidth = 120, bodyHeight = 30;
    int cockpitRadius = 15;
    int tailLength = 80, tailHeight = 10;
    int topRotorLength = 140, rotorWidth = 6;
    int tailRotorLength = 20;
    int skidLength = 100, skidHeight = 5;

    // Colors


    // Draw main body
    window* w = pGame->getWind();

    w->SetPen(LIGHTBLUE);
    w->SetBrush(LIGHTBLUE);
    w->DrawRectangle(centerX - bodyWidth / 2, centerY,
        centerX + bodyWidth / 2, centerY + bodyHeight, FILLED);

    // Draw cockpit (front circle)
    w->SetBrush(LIGHTBLUE);
    w->DrawCircle(centerX - bodyWidth / 2, centerY + bodyHeight / 2, cockpitRadius, FILLED);

    // Draw tail
    w->SetBrush(LIGHTBLUE);
    w->DrawRectangle(centerX + bodyWidth / 2, centerY + bodyHeight / 2 - tailHeight / 2,
        centerX + bodyWidth / 2 + tailLength, centerY + bodyHeight / 2 + tailHeight / 2, FILLED);

    // Draw top rotor
    w->SetBrush(LIGHTBLUE);
    w->DrawRectangle(centerX - topRotorLength / 2, centerY - 20,
        centerX + topRotorLength / 2, centerY - 20 + rotorWidth, FILLED);

    // Draw tail rotor (vertical small blade)
    int tailX = centerX + bodyWidth / 2 + tailLength;
    int tailY = centerY + bodyHeight / 2;
    w->DrawRectangle(tailX - rotorWidth / 2, tailY - tailRotorLength / 2,
        tailX + rotorWidth / 2, tailY + tailRotorLength / 2, FILLED);

    // Draw skids (landing gear)
    w->SetBrush(LIGHTBLUE);
    int skidY = centerY + bodyHeight + 10;
    w->DrawRectangle(centerX - skidLength / 2, skidY,
        centerX + skidLength / 2, skidY + skidHeight, FILLED);

    pGame->printMessage("Hit detected!");
    pGame->UpdateScore(60);
    pGame->removeEnemy(this);
    markDestroyed();
}