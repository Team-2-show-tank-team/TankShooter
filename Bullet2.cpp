#include "Bullet2.h"

Bullet2::Bullet2(float x, float y, float angle) : Bullet(x, y, angle)
{
	this->initPos = sf::Vector2f(x, y);
	this->initTexture();
	this->initSprite();
	this->sprite.rotate(angle);
}

Bullet2::~Bullet2()
{
}

void Bullet2::initTexture()
{
	this->texture.loadFromFile("Textures\\bullet2.png");
}

