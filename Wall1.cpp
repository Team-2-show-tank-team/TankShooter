#include "Wall1.h"

Wall1::Wall1(float x, float y)
{
	this->initTexture();
	this->initSprite();
}

Wall1::~Wall1()
{
}

void Wall1::initTexture()
{
	this->texture.loadFromFile("Textures\\Wall1.png");
}
