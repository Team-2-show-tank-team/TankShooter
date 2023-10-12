#pragma once
#include "Bullet.h"
class Bullet2 : public Bullet
{
public:
	Bullet2(float x, float y, float angle);
	virtual ~Bullet2();

	void initTexture() override;

};

