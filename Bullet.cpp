#include "Bullet.h"




Bullet::Bullet(float x, float y, sf::Texture textureM, float angleM) : GameObject(x, y, textureM)
{
	this->angle = angleM;
	this->sprite.setRotation(angle);
}

Bullet::~Bullet()
{
	delete &this->sprite;
}

void Bullet::move()
{
    float radianAngle = this->angle * (3.14159f / 180.0f);
    float moveX = std::cos(radianAngle) * this->movementSpeed;
    float moveY = std::sin(radianAngle) * this->movementSpeed;

    this->sprite.move(moveX, moveY);
}

bool Bullet::checkOutScreen()
{
	sf::Vector2f spritePosition = this->sprite.getPosition();
	sf::FloatRect spriteBounds = this->sprite.getGlobalBounds();

	if (spritePosition.x < 0) {
		return true;
	}
	if (spritePosition.x + spriteBounds.width / 2 > 2160) {
		return true;
	}
	if (spritePosition.y < 0) {
		return true;
	}
	if (spritePosition.y + spriteBounds.height / 2 > 1280) {
		return true;
	}


	return false;
}



