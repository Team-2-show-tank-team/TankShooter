#pragma once

#include "Wall.h"
#include "GameObject.h"

class Tank : public GameObject
{
public:

	Tank(float x, float y, sf::Texture textureM);
	virtual ~Tank();

	float movementSpeed = 5.f;

	float rotateSpeed = 1.f;

	bool checkWallCollide(std::vector<Wall*> walls);

	void checkOutScreen();

	void rotateUp();

	void rotateDown();

	void moveOn();

	void moveBack();
	
	void move(const float dirX, const float dirY);
};

