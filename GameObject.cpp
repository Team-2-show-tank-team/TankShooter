#include "GameObject.h"



GameObject::GameObject()
{
}

GameObject::GameObject(float x, float y)
{	
	this->setInitPos(x, y);
}

void GameObject::setInitPos(float x, float y)
{
	this->initPos = sf::Vector2f(x, y);
	this->sprite.setPosition(this->initPos.x, this->initPos.y);
}

void GameObject::initTexture()
{

}

void GameObject::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setOrigin(this->texture.getSize().x / 2.0f, this->texture.getSize().y / 2.0f);
}

bool GameObject::checkCollide(GameObject object)
{
	return object.sprite.getGlobalBounds().intersects(this->sprite.getGlobalBounds());
}

void GameObject::move()
{
}

void GameObject::update()
{
}

void GameObject::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);	
}

GameObject::~GameObject()
{
	
}
