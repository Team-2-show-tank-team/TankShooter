#include "Bullet1.h"




Bullet1::Bullet1(float x, float y, float angle) : Bullet(x, y, angle)
{
	this->initPos = sf::Vector2f(x, y);
	this->initTexture();
	this->initSprite();
	this->sprite.rotate(angle);
}

Bullet1::~Bullet1()
{
}

void Bullet1::initTexture() 
{
	this->texture.loadFromFile("Textures\\bullet1.png");
}


