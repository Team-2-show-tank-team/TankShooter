#pragma once
#include "GameObject.h"
#include "Bullet.h"

class Wall : public GameObject
{
public:
	Wall();
	Wall(float x, float y);
	virtual ~Wall();
	
	friend bool checkWallCollide(std::vector<Wall*> walls, Bullet obj);

};

