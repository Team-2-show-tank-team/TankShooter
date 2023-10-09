#pragma once
#include "Wall.h"
class Wall2 : public Wall
{
public:
	Wall2(float x, float y);
	virtual ~Wall2();

	void initTexture() override;
};

