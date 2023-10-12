#pragma once
#include "GameObject.h"

class Bullet : public GameObject
{
public:

	Bullet(float x, float y, float angle);
	virtual ~Bullet();

	void move();

	bool checkOutScreen();

	int movementSpeed = 10.f;
	float angle;

};

