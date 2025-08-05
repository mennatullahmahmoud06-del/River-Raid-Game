#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "GameObject.h" 
class Fuel :  public GameObject
{

public:
	Fuel(Game* r_pGame, point r_point, int r_width, int r_height, color fc, color bc);

	void draw() const;
	void move();
	GameObjectType getType()const override;
	void collisionAction() override;

	

};

//	/*class Fuel : public GameObject
//
//	{
//	private:
//		int length = 50;
//		int width = 50;
//		color box = NAVYBLUE;
//	public:
//
//		void draw(int x, int y);
//	};
////*//*int getX() const;
//	int getY() const;*/
