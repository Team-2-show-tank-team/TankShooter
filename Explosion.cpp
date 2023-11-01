#include "Explosion.h"

Explosion::Explosion(float x, float y, sf::Texture textureM) : GameObject(x,y,textureM)
{
}

Explosion::~Explosion()
{
}

bool Explosion::checkDone()
{
	return this->clock.getElapsedTime() > sf::seconds(1.f);
}
