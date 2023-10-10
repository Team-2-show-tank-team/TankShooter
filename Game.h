#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include"Tank1.h"
#include "Tank2.h"
#include "Bullet.h"
#include "Wall.h"

class Game
{
public:
	Game();
	virtual ~Game();	
	


	sf::RenderWindow* window;
	sf::Texture backgroundTexture;
	sf::Sprite background;

	std::vector<Bullet> bullet1;
	std::vector<Bullet> bullet2;

	std::vector<Wall*> walls;

	Tank1* tank1;
	Tank2* tank2;


	void initTank1();
	void initTank2();

	void initWall();

	void initBullets1();
	void initBullets2();

	bool checkWalls(GameObject obj);

	void updatePollEvents();
	void updateInput();
	void initWindow();
	void run();
	void update();
	void render();
};

