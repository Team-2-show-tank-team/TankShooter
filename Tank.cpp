#include "Tank.h"



Tank::Tank(float x, float y) : GameObject(x, y)
{

}

Tank::~Tank()
{
}

void Tank::rotateUp()
{
    this->sprite.rotate(this->rotateSpeed);
}

void Tank::rotateDown()
{
    this->sprite.rotate(-this->rotateSpeed);
}

void Tank::moveOn()
{
    float radianAngle = this->sprite.getRotation() * (3.14159f / 180.0f);
    float moveX = std::cos(radianAngle) * this->movementSpeed;
    float moveY = std::sin(radianAngle) * this->movementSpeed;

    this->sprite.move(moveX, moveY);
}

void Tank::moveBack()
{
    float radianAngle = this->sprite.getRotation() * (3.14159f / 180.0f);
    float moveX = -std::cos(radianAngle) * this->movementSpeed;
    float moveY = -std::sin(radianAngle) * this->movementSpeed;

    this->sprite.move(moveX, moveY);
}

void Tank::move(const float dirX, const float dirY)
{
	this->sprite.move(movementSpeed * dirX, movementSpeed * dirY);
}


