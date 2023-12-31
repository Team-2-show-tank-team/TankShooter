#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include <iostream>

class GameObject
{
public:
	GameObject(float x, float y, sf::Texture textureM);
	virtual ~GameObject();



	sf::Texture texture;
	sf::Sprite sprite;

	sf::Vector2f initPos;

	void setInitPos(float x, float y);

	virtual void initTexture();
	void initSprite();

	bool checkCollide(GameObject object);

	void move();
	void update();
	void render(sf::RenderTarget& target);
};

