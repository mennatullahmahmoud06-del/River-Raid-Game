#include "Jets.h"
#include "Game.h"

Jets::Jets(Game* pgame, point ref, int width, int height, color fc, color fb) : Enemy(pgame, ref, 100, 50, RED, BLACK, GameObjectType::JET_ENEMY) {} // width & height are unused here
void Jets::draw() const {
    // Draw the Jet at its position (x, y) with the specified color
    // Base position (centerX and centerY)
    // CMU window object
    window* w = pGame->getWind();

    // Center position
    int centerX = RefPoint.x;
    int centerY = RefPoint.y;

    // Dimensions
    int bodyLength = 140, bodyHeight = 20;
    int wingWidth = 80, wingHeight = 10;
    int tailWidth = 40, tailHeight = 15;
    int noseLength = 20;

    // Colors
    color gray = color(120, 120, 120);
    color darkGray = color(80, 80, 80);

    // Draw main body
    w->SetPen(BLACK);
    w->SetBrush(gray);
    w->DrawRectangle(centerX - bodyLength / 2, centerY,
        centerX + bodyLength / 2, centerY + bodyHeight, FILLED);

    // Draw nose (front triangle)
    w->SetBrush(darkGray);
    int noseX = centerX + bodyLength / 2;
    w->DrawTriangle(noseX, centerY,
        noseX + noseLength, centerY + bodyHeight / 2,
        noseX, centerY + bodyHeight, FILLED);

    // Draw wings
    w->SetBrush(BLACK);
    w->DrawRectangle(centerX - wingWidth / 2, centerY + bodyHeight,
        centerX + wingWidth / 2, centerY + bodyHeight + wingHeight, FILLED);

    // Draw tail
    w->SetBrush(gray);
    w->DrawRectangle(centerX - tailWidth / 2, centerY - tailHeight,
        centerX + tailWidth / 2, centerY, FILLED);
}


    void Jets::erase(window * pwind)
    {
        window* w = pGame->getWind();

        // Center position
        int centerX = RefPoint.x;
        int centerY = RefPoint.y;

        // Dimensions
        int bodyLength = 140, bodyHeight = 20;
        int wingWidth = 80, wingHeight = 10;
        int tailWidth = 40, tailHeight = 15;
        int noseLength = 20;

        // Colors


        // Draw main body
        w->SetPen(LIGHTBLUE);
        w->SetBrush(LIGHTBLUE);
        w->DrawRectangle(centerX - bodyLength / 2, centerY,
            centerX + bodyLength / 2, centerY + bodyHeight, FILLED);

        // Draw nose (front triangle)
        int noseX = centerX + bodyLength / 2;
        w->DrawTriangle(noseX, centerY,
            noseX + noseLength, centerY + bodyHeight / 2,
            noseX, centerY + bodyHeight, FILLED);

        // Draw wings
        w->DrawRectangle(centerX - wingWidth / 2, centerY + bodyHeight,
            centerX + wingWidth / 2, centerY + bodyHeight + wingHeight, FILLED);

        // Draw tail
        w->DrawRectangle(centerX - tailWidth / 2, centerY - tailHeight,
            centerX + tailWidth / 2, centerY, FILLED);
    }

void Jets::collisionAction()
{
    window* w = pGame->getWind();

    // Center position
    int centerX = RefPoint.x;
    int centerY = RefPoint.y;

    // Dimensions
    int bodyLength = 140, bodyHeight = 20;
    int wingWidth = 80, wingHeight = 10;
    int tailWidth = 40, tailHeight = 15;
    int noseLength = 20;

    // Colors


    // Draw main body
    w->SetPen(LIGHTBLUE);
    w->SetBrush(LIGHTBLUE);
    w->DrawRectangle(centerX - bodyLength / 2, centerY,
        centerX + bodyLength / 2, centerY + bodyHeight, FILLED);

    // Draw nose (front triangle)
    w->SetBrush(LIGHTBLUE);
    int noseX = centerX + bodyLength / 2;
    w->DrawTriangle(noseX, centerY,
        noseX + noseLength, centerY + bodyHeight / 2,
        noseX, centerY + bodyHeight, FILLED);

    // Draw wings
    w->SetBrush(LIGHTBLUE);
    w->DrawRectangle(centerX - wingWidth / 2, centerY + bodyHeight,
        centerX + wingWidth / 2, centerY + bodyHeight + wingHeight, FILLED);

    // Draw tail
    w->SetBrush(LIGHTBLUE);
    w->DrawRectangle(centerX - tailWidth / 2, centerY - tailHeight,
        centerX + tailWidth / 2, centerY, FILLED);

    pGame->printMessage("Hit detected!");
    pGame->UpdateScore(100);
    pGame->removeEnemy(this);
    markDestroyed();
}

GameObjectType Jets::getType() const
{
    return GameObjectType::JET_ENEMY;
}

void Jets::move()
{
    RefPoint.x += currentSpeed;

}