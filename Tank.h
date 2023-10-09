#pragma once

#include "GameObject.h"

class Tank : public GameObject
{
public:

	Tank(float x, float y);
	virtual ~Tank();

	int movementSpeed = 5.f;
	
	void move(const float dirX, const float dirY);
};

