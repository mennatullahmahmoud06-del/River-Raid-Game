#include "plane.h"
#include "Game.h"
#include "GameConfig.h"

Plane::Plane(Game* r_pGame, point r_point, int r_width, int r_height, color fc, color bc, int speed)
    : GameObject(r_pGame, r_point, r_width, r_height, fc, bc, GameObjectType::PLANE), speed(speed)
{
}

///////////////////////////////////  update positiion function ////////////////////////////
void Plane::moveup() {

    if (RefPoint.y - speed >= 0) { // Prevent moving out of the top boundary
        RefPoint.y -= speed;
        speed++;
    }
}




void Plane::movedown()
{
    window* w = pGame->getWind();
    if (RefPoint.y + height + speed <= w->GetHeight()) {
        RefPoint.y += speed;
        speed++;
    }
}

void Plane::moveright()
{
    window* w = pGame->getWind();
    if (RefPoint.x + speed < w->GetWidth()) {
        RefPoint.x += speed;
        speed++;
    }
    
}

void Plane::moveleft()
{
    window* w = pGame->getWind();
    if (RefPoint.x - speed > 0) {
        RefPoint.x -= speed;
        speed++;
    }
}



void Plane::updateposition()
{
    window* w = pGame->getWind();
    char cKeyData;
    keytype kType = w->GetKeyPress(cKeyData);

    if ((kType == ARROW) && (cKeyData == 2)) {
        movedown();
    }
    else if ((kType == ARROW) && (cKeyData == 8)) {
        moveup();
    }
    else if ((kType == ARROW) && (cKeyData == 4)) {
        moveleft();
        }
    else if ((kType == ARROW) && (cKeyData == 6)) {
        moveright();
    }

    
}

void Plane::erasePreviousPosition(window* pWind)
{
    window* w = pGame->getWind();
    w->SetPen(LIGHTBLUE, 1);
    w->SetBrush(LIGHTBLUE);
    int x1 = RefPoint.x;
    int y1 = RefPoint.y;
    int x2 = x1 + width;
    int y2 = y1 + height;

    // Rectangle demo
    w->DrawRectangle(x1, y1, x2, y2, FILLED);

    // Wings
    int wingWidth = width * 1.25;
    int wingHeight = height / 5;
    int polygony1 = y1 + height / 4;
    int polygony2 = y1 + height / 3;
    int polygony4 = polygony1 + wingHeight;
    int polygony3 = polygony1 + wingHeight;

    int xs[4] = { x2, x2 + wingWidth, x2 + wingWidth , x2 };
    int ys[4] = { polygony1, polygony2, polygony3, polygony4 };

    w->DrawPolygon(xs, ys, 4, FILLED);

    int xs2[4] = { x1,x1 - wingWidth,x1 - wingWidth,x1 };
    w->DrawPolygon(xs2, ys, 4, FILLED);

    // Smaller wings
    int wingWidth2 = width * 0.75;
    int wingheight2 = height * 0.3;
    int YSmall[4];
    for (int i = 0; i < 4; i++) {
        YSmall[i] = (ys[i] + wingheight2);
    }
    YSmall[3] = YSmall[3] - 10;

    int xs3[4] = { x2, x2 + wingWidth2, x2 + wingWidth2 , x2 };
    int xs4[4] = { x1,x1 - wingWidth2,x1 - wingWidth2,x1 };

    w->DrawPolygon(xs3, YSmall, 4, FILLED);
    w->DrawPolygon(xs4, YSmall, 4, FILLED);

    // Draw head
    w->DrawTriangle(x1, y1 + 3, x2, y1 + 3, (x1 + x2) / 2, y1 - 50, FILLED);
    int centre = (x1 + x2) / 2;

    // Draw lower rectangles
    w->DrawRectangle(centre - 10, y2, centre - 5, y2 + 10, FILLED);
    w->DrawRectangle(centre + 10, y2, centre + 5, y2 + 10, FILLED);

    
}

point Plane::getRefPoint() const
{
    return RefPoint;
}

int Plane::getWidth() const
{
    return width;
}

int Plane::getHeight() const
{
    return height;
}

int Plane::getSpeed() const
{
    return speed;
}

GameObjectType Plane::getType() const
{
    return GameObjectType::PLANE;
}

void Plane::collisionAction()
{
}

/////////////////////////////////////// Draw function ///////////////////////////////////////////

void Plane::draw() const {
    window* w = pGame->getWind();
    w->SetPen(borderColor, 1);
    w->SetBrush(fillColor);
    int x1 = RefPoint.x;
    int y1 = RefPoint.y;
    int x2 = x1 + width;
    int y2 = y1 + height;

    // Rectangle demo
    w->DrawRectangle(x1, y1, x2, y2, FILLED);

    // Wings
    int wingWidth = width * 1.25;
    int wingHeight = height / 5;
    int polygony1 = y1 + height / 4;
    int polygony2 = y1 + height / 3;
    int polygony4 = polygony1 + wingHeight;
    int polygony3 = polygony1 + wingHeight;

    int xs[4] = { x2, x2 + wingWidth, x2 + wingWidth , x2 };
    int ys[4] = { polygony1, polygony2, polygony3, polygony4 };
  
    w->DrawPolygon(xs, ys, 4, FILLED);

    int xs2[4] = { x1,x1 - wingWidth,x1 - wingWidth,x1 };
    w->DrawPolygon(xs2, ys, 4, FILLED);

    // Smaller wings
    int wingWidth2 = width * 0.75;
    int wingheight2 = height * 0.3;
    int YSmall[4];
    for (int i = 0; i < 4; i++) {
        YSmall[i] = (ys[i] + wingheight2);
    }
    YSmall[3] = YSmall[3] - 10;

    int xs3[4] = { x2, x2 + wingWidth2, x2 + wingWidth2 , x2 };
    int xs4[4] = { x1,x1 - wingWidth2,x1 - wingWidth2,x1 };

    w->DrawPolygon(xs3, YSmall, 4, FILLED);
    w->DrawPolygon(xs4, YSmall, 4, FILLED);

    // Draw head
    w->DrawTriangle(x1, y1 + 3, x2, y1 + 3, (x1 + x2) / 2, y1 - 50, FILLED);
    int centre = (x1 + x2) / 2;

    // Draw lower rectangles
    w->DrawRectangle(centre - 10, y2, centre - 5, y2 + 10, FILLED);
    w->DrawRectangle(centre + 10, y2, centre + 5, y2 + 10, FILLED);



}

void Plane::move()
{


}
