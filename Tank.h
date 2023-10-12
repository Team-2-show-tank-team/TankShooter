#pragma once

#include "GameObject.h"

class Tank : public GameObject
{
public:

	Tank(float x, float y);
	virtual ~Tank();

	int movementSpeed = 5.f;

	int rotateSpeed = 1.f;



	void checkOutScreen();

	void rotateUp();

	void rotateDown();

	void moveOn();

	void moveBack();
	
	void move(const float dirX, const float dirY);
};

