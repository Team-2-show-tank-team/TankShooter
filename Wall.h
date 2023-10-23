#pragma once
#include "GameObject.h"
#include "Bullet.h"

class Wall : public GameObject
{
public:
	Wall(float x, float y, sf::Texture textureM);
	virtual ~Wall();

};

