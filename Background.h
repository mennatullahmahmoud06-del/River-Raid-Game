#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "GameObject.h"

class Background : public GameObject
{
private:
	
public:
	Background(Game* r_pGame, point r_point, int r_width, int r_height, color fc, color bc);
	void draw () const;
	void scrollDown(int speed);
	void move();
	GameObjectType getType()const override;
	void collisionAction()override;

	
	

};

