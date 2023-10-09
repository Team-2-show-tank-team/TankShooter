#include "Bullet2.h"

Bullet2::Bullet2(float x, float y) : Bullet(x, y)
{
	this->initPos = sf::Vector2f(x, y);
	this->initTexture();
	this->initSprite();
}

Bullet2::~Bullet2()
{
}

void Bullet2::initTexture()
{
	this->texture.loadFromFile("Textures\\bullet2.png");
}

