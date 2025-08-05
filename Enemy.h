#pragma once
#include "GameObject.h" 


class Enemy : public GameObject
{
protected:
    int speed;
    int health;
    int currentSpeed;

public:
    Enemy(Game* pGame, point ref, int width, int height, color fc, color fb, GameObjectType type);
    virtual void draw() const override = 0;
    void setSpeed(int newspeed);
    virtual void move() = 0;
    virtual void erase(window* pWind) = 0;
    virtual bool isOffScreen() const;
    virtual point getRefPoint() const;


};


