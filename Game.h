#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "cstdlib"

#include"Tank.h"
#include "Bullet.h"
#include "Wall.h"
#include "Shield.h"

class Game
{
public:
	Game();
	virtual ~Game();	


	sf::Text text;
	sf::Font font;

	bool isEndGame = false;


	sf::RenderWindow* window;
	sf::Texture backgroundTexture;
	sf::Sprite background;	

	std::map<std::string, sf::Texture> textures;

	std::vector<Bullet*> bullet1;
	std::vector<Bullet*> bullet2;

	std::vector<Wall*> walls;

	float i = rand() % 5 + 5.f;
	sf::Time resetTime = sf::seconds(i);

	Tank* tank1;
	Tank* tank2;

	sf::Clock clock;


	void initTank1();
	void initTank2();

	void initString();

	void initWall();

	void initTextures();


	void updateBullet();

	void checkTank(Tank* tank);

	bool checkWalls(GameObject obj);

	std::vector<Shield*> shield1;
	std::vector<Shield*> shield2;

	Shield* shieldItem;

	bool isShieldAvail = false;

	void initShield();

	void updateShield();


	void updatePollEvents();
	void updateInput();
	void initWindow();
	void run();
	void update();
	void render();
};

