#include "Game.h"

Game::Game()
{
	this->initWindow();
	this->initTank1();
	this->initTank2();
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
		this->tank1->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->tank1->move(1.0f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->tank1->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->tank1->move(0.f, 1.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		this->tank2->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		this->tank2->move(1.0f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		this->tank2->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		this->tank2->move(0.f, 1.f);

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

	this->window->display();
}


void Game::run()
{
	while (this->window->isOpen()) {
		this->update();
		this->render();
	}
}
