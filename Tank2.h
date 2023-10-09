#pragma once

#include "Tank.h"

class Tank2 : public Tank
{
public:
	Tank2();
	Tank2(float x, float y);
	virtual ~Tank2();

	void initTexture() override;

};

