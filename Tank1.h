#pragma once

#include "Tank.h"


class Tank1 : public Tank
{
public:
	Tank1(float x, float y);
	Tank1();
	virtual ~Tank1();

	void initTexture() override;


};

