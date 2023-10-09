#include "Tank2.h"


Tank2::Tank2(float x, float y) : Tank(x, y)
{
    this->initTexture();
    this->initSprite();
}

Tank2::~Tank2()
{

}

void Tank2::initTexture()
{
    this->texture.loadFromFile("Textures\\tank2.png");
}

