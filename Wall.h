#pragma once
#include "GameObject.h"

class Wall : public GameObject
{
public:
	Wall();
	Wall(float x, float y);
	virtual ~Wall();

};

