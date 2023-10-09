#pragma once
#include "GameObject.h"

class Wall : GameObject
{
public:
	Wall();
	Wall(float x, float y);
	virtual ~Wall();

	void initTexture() override;
};

