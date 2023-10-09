#include "Bullet1.h"


Bullet1::Bullet1(float x, float y) : Bullet(x, y)
{
	this->initPos = sf::Vector2f(x, y);
	this->initTexture();
	this->initSprite();
}

Bullet1::~Bullet1()
{
}

void Bullet1::initTexture() 
{
	this->texture.loadFromFile("Textures\\bullet1.png");
}


