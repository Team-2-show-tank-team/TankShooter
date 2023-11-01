#pragma once
#include "GameObject.h"
class Explosion : public GameObject
{
public:
	Explosion(float x, float y, sf::Texture textureM);
	virtual ~Explosion();
	sf::Clock clock;

	bool checkDone();
};

