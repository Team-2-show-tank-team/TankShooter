#pragma once
#include "GameObject.h"

class Bullet : public GameObject
{
public:
	Bullet();
	Bullet(float x, float y);
	virtual ~Bullet();

	int movementSpeed = 20.f;

};

