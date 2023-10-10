#include "Game.h"
#include "Wall1.h"

Game::Game()
{
	this->initWindow();
	this->initTank1();
	this->initTank2();
	this->initWall();
}

Game::~Game()
{
}

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(2160, 1280), "Tank Shooter");
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);

	backgroundTexture.loadFromFile("Textures\\background.png");
	background.setTexture(backgroundTexture);
}

void Game::initTank1()
{
	this->tank1 = new Tank1(20.f, 640.f);
}

void Game::initTank2()
{
	this->tank2 = new Tank2(2000.f, 640.f);
}

void Game::initWall()
{
	this->walls.push_back(new Wall1(60.f, 200.f));
	this->walls.push_back(new Wall1(80.f, 200.f));
	this->walls.push_back(new Wall1(1000.f, 200.f));
}

void Game::initBullets1()
{
	
}

void Game::initBullets2()
{
}

bool Game::checkWalls(GameObject obj)
{
	bool check = true;

	for (auto i : walls) {
		if (i->checkCollide(obj)) {
			check = false;
		}
	}

	return check;
}

void Game::updatePollEvents()
{
	sf::Event e;

	while (this->window->pollEvent(e)) {
		if (e.Event::type == sf::Event::Closed)
			this->window->close();
		if (e.Event::KeyPressed) {
			if (e.Event::key.code == sf::Keyboard::Escape)
				this->window->close();
		}
	}
}

void Game::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		if(checkWalls(*this->tank1))
		this->tank1->rotateDown();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		if (checkWalls(*this->tank1))
		this->tank1->rotateUp();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		if (checkWalls(*this->tank1))
		this->tank1->moveOn();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		if (checkWalls(*this->tank1))
		this->tank1->moveBack();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		this->tank2->rotateDown();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		this->tank2->rotateUp();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		this->tank2->moveBack();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		this->tank2->moveOn();

}



void Game::update()
{
	this->updatePollEvents();
	this->updateInput();
}

void Game::render()
{
	this->window->clear();

	this->window->draw(background);

	this->tank1->render(*this->window);

	this->tank2->render(*this->window);

	for (auto i : this->walls) {
		i->render(*this->window);
	}

	this->window->display();
}


void Game::run()
{
	while (this->window->isOpen()) {
		this->update();
		this->render();
	}
}
