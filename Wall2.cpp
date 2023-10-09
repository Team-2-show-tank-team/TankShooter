#include "Wall2.h"

Wall2::Wall2(float x, float y)
{
	this->initTexture();
	this->initSprite();
}

Wall2::~Wall2()
{
}

void Wall2::initTexture()
{
	this->texture.loadFromFile("Textures\\Wall2.png");
}
