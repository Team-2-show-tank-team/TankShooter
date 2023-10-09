#pragma once
#include "Bullet.h"
class Bullet1 : public Bullet
{
public:
	Bullet1(float x, float y);
	virtual ~Bullet1();

	void initTexture() override;

};

