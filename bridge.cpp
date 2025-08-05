#include "bridge.h"
#include "Game.h"
Bridge::Bridge(Game* pgame, point ref, int width, int height, color fc, color fb) : Enemy(pgame, ref, 150, 40, fc, fb, GameObjectType::BRIDGE_ENEMY) {}; // width & height are unused here
void Bridge::draw() const {
    // Draw the Bridge at its position (x, y) with the specified color
    // Base position (centerX and centerY)
    // CMU window object
        // Center position

    int centerX = RefPoint.x;
    int centerY = RefPoint.y;

    // Bridge settings
    int bridgeWidth = 400;
    int bridgeHeight = 50;
    int plankCount = 7;
    int plankHeight = bridgeHeight / plankCount;

    window* w = pGame->getWind();

    // Colors
    color brown = color(181, 101, 29);     // Light wood
    color black = color(140, 70, 5);  // Darker wood

    // Draw planks
    for (int i = 0; i < plankCount; ++i) {
        if (i % 2 == 0)
            w->SetBrush(brown);
        else
            w->SetBrush(black);

        w->SetPen(BLACK);
        int topY = centerY - bridgeHeight / 2 + i * plankHeight;
        int bottomY = topY + plankHeight;

        w->DrawRectangle(centerX - bridgeWidth / 2, topY,
            centerX + bridgeWidth / 2, bottomY, FILLED);
    }
}

void Bridge::move()
{
    RefPoint.x += currentSpeed;
}
void Bridge::erase(window* pWind)
{
}
GameObjectType Bridge::getType() const
{
    return GameObjectType::BRIDGE_ENEMY;
}

void Bridge::collisionAction()
{
    int centerX = RefPoint.x;
    int centerY = RefPoint.y;

    // Bridge settings
    int bridgeWidth = 400;
    int bridgeHeight = 50;
    int plankCount = 7;
    int plankHeight = bridgeHeight / plankCount;

    window* w = pGame->getWind();

    // Colors


    // Draw planks
    for (int i = 0; i < plankCount; ++i) {
        if (i % 2 == 0)
            w->SetBrush(LIGHTBLUE);
        else
            w->SetBrush(LIGHTBLUE);

        w->SetPen(LIGHTBLUE);
        int topY = centerY - bridgeHeight / 2 + i * plankHeight;
        int bottomY = topY + plankHeight;

        w->DrawRectangle(centerX - bridgeWidth / 2, topY,
            centerX + bridgeWidth / 2, bottomY, FILLED);
    }

    pGame->UpdateScore(500);
    pGame->removeEnemy(this);
    markDestroyed();
}




