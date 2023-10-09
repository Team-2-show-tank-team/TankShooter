#pragma once
#include "Wall.h"
class Wall1 : public Wall
{
public:
	Wall1(float x, float y);
	virtual ~Wall1();

	void initTexture() override;
};

