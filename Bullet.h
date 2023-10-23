#pragma once
#include "GameObject.h"
#include "Wall.h"

class Bullet : public GameObject
{
public:

	Bullet(float x, float y,sf::Texture textureM ,float angleM);
	virtual ~Bullet();

	void move();

	bool checkOutScreen();

	int movementSpeed = 10.f;

	float angle;


	//bool checkWallColide(std::vector<Wall*> walls);

};

