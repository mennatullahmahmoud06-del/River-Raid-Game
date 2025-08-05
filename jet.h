#pragma once
#include "GameObject.h"

class Jet : public GameObject
{
public:
    Jet(Game* pGame, point ref);  // Constructor
    void draw() const override;   // Draw function
};
