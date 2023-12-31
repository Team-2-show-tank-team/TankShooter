#include "Tank.h"



Tank::Tank(float x, float y, sf::Texture textureM) : GameObject(x, y, textureM)
{
	
}

Tank::~Tank()
{
}

bool Tank::checkWallCollide(std::vector<Wall*> walls)
{
	for (auto i : walls) {
		if (checkCollide(*i)) {
			return true;
		}
	}
	return false;
}

void Tank::checkOutScreen()
{
	sf::Vector2f spritePosition = this->sprite.getPosition();
	sf::FloatRect spriteBounds = this->sprite.getGlobalBounds();

	if (spritePosition.x < spriteBounds.width / 2) {
		spritePosition.x = spriteBounds.width / 2;
	}
	if (spritePosition.x + spriteBounds.width /2 > 2160) {
		spritePosition.x = 2160 - spriteBounds.width / 2;
	}
	if (spritePosition.y < spriteBounds.height / 2) {
		spritePosition.y = spriteBounds.height / 2;
	}
	if (spritePosition.y + spriteBounds.height  / 2 > 1280) {
		spritePosition.y = 1280 - spriteBounds.height/2;
	}

	sprite.setPosition(spritePosition);
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


