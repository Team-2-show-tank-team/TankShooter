#include "Wall.h"

Wall::Wall()
{
}

Wall::Wall(float x, float y)
{
	this->initPos = sf::Vector2f(x, y);
	this->initTexture();
	this->initSprite();
}

Wall::~Wall()
{
}

void Wall::initTexture()
{
	if (!texture.loadFromFile("tank1.png")) {

	}
}
