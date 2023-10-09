#include "Tank.h"



Tank::Tank(float x, float y) : GameObject(x, y)
{

}

Tank::~Tank()
{
}

void Tank::move(const float dirX, const float dirY)
{
	this->sprite.move(movementSpeed * dirX, movementSpeed * dirY);
}

