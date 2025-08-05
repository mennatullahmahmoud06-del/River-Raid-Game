#pragma once
#include "GameObject.h"
using namespace std;

class Plane : public GameObject
{
private:
	int speed;
	//int x;              // X position
	//int y;              // Y position
	//double scale;       // Scale factor for drawing
	//int width;          // Width of the plane
	

public:
	Plane(Game* r_pGame, point r_point, int r_width, int r_height, color fc, color bc, int speed);
	void draw() const;
	void moveup();
	void movedown();
	void moveright();
	void moveleft();
	void updateposition();
	void erasePreviousPosition(window* pWind);
	point getRefPoint() const;
	int getWidth() const;
	int getHeight() const;
	int getSpeed() const;
	void move(); 
	GameObjectType getType()const override;
	void collisionAction()override;
	
	/*Plane(int initialX, int initialY, double initialScale = 0.1);*/

	 //Draw the plane at its current position
	//void draw(window& kimo);

	// Move the plane left with boundary checking
	//void moveLeft(int step, int leftBoundary);

	//// Move the plane right with boundary checking
	//void moveRight(int step, int rightBoundary);

	//// Getter methods
	//int getX() const;
	//int getY() const;
	//double getScale() const;
	//int getWidth() const;
	//int getHeight() const;


};

