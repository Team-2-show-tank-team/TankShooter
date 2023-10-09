#include "Tank1.h"


Tank1::Tank1(float x, float y) : Tank(x, y)
{
	this->initTexture();
	this->initSprite();
}



Tank1::~Tank1()
{

}

void Tank1::initTexture()
{
    this->texture.loadFromFile("Textures\\tank1.png");
}
