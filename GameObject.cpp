#include "GameObject.h"
#include <iostream>
using namespace std;

GameObject::GameObject(Game* r_pGame, point ref, int r_width, int r_height, color fc, color bc, GameObjectType objType) : Drawable (r_pGame, ref, r_width, r_height), type(objType)
{
	fillColor = fc;
	borderColor = bc;
}

void GameObject::setRefPoint(point p)
{
	RefPoint = p;
}
point GameObject::getRefPoint() const {
	return RefPoint;
}

int GameObject::getWidth() const
{
	return width;
}

int GameObject::getHeight() const
{
	return height;
}


// you should implement this function knowing that each game object has refPoint, width and height 
// for simplicity, you can consider all game objects are rectangles
bool GameObject::CollisionDetection(const GameObject& gObj)
{
	point thisPos = this->getRefPoint();
	point otherpos = gObj.getRefPoint();
	int thisWidth = this->getWidth();
	int thisHeight = this->getHeight();
	int otherWidth = gObj.getWidth();
	int otherHeight = gObj.getHeight();
	bool isColliding (thisPos.x < otherpos.x + otherWidth &&
		thisPos.x + thisWidth > otherpos.x &&
		thisPos.y < otherpos.y + otherHeight &&
		thisPos.y + thisHeight > otherpos.y);

	if (isColliding) {
		std::cout << "Collision between " << static_cast<int>(this->getType())
			<< " and " << static_cast<int>(gObj.getType()) << std::endl;
	}

	return isColliding;


}
