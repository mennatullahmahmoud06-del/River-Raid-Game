#pragma once

#include "CMUgraphicsLib\CMUgraphics.h"
#include "GameObject.h"

class Bullet :
    public GameObject
{
private:
	int x, y;   // Position
	int width, height;

public:
	//Bullet(int x, int y);
	void setPosition(int newX, int newY);
	
  Bullet( Game* pGame, point pos);
  ~Bullet();
  void moveUp(int distance);
  void draw()const;
  point getRefPoint() const;
  int getWidth() const;
  int getHeight() const;
  void move();
  GameObjectType getType()const override;
  void collisionAction();
};

