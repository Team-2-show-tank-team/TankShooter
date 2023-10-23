#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include"Tank.h"
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

	std::map<std::string, sf::Texture> textures;

	std::vector<Bullet*> bullet1;
	std::vector<Bullet*> bullet2;

	std::vector<Wall*> walls;

	Tank* tank1;
	Tank* tank2;


	void initTank1();
	void initTank2();

	void initWall();

	void initTextures();


	void updateBullet();

	bool checkWalls(GameObject obj);

	void checkBullet1Wall();


	void updatePollEvents();
	void updateInput();
	void initWindow();
	void run();
	void update();
	void render();
};

