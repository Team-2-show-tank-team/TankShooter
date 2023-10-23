#include "Game.h"
#include "Wall.h"



Game::Game()
{
	this->initWindow();
	this->initTextures();
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
	this->tank1 = new Tank(200.f, 650.f, textures["tank1"]);
}

void Game::initTank2()
{
	this->tank2 = new Tank(1900.f, 640.f, textures["tank2"]);
}

void Game::initWall()
{
	this->walls.push_back(new Wall(330.f, 520.f, textures["wall1"]));
	this->walls.push_back(new Wall(410.f, 650.f, textures["wall1"]));
	this->walls.push_back(new Wall(330.f, 780.f, textures["wall1"]));

	this->walls.push_back(new Wall(1820.f, 520.f, textures["wall2"]));
	this->walls.push_back(new Wall(1720.f, 650.f, textures["wall2"]));
	this->walls.push_back(new Wall(1820.f, 780.f, textures["wall2"]));
}

void Game::initTextures()
{
	//bullet 1
	sf::Texture texture1;
	texture1.loadFromFile("Textures\\bullet1.png");

	this->textures["bullet1"] = texture1;

	//bullet 2
	sf::Texture texture2;
	texture2.loadFromFile("Textures\\bullet2.png");

	this->textures["bullet2"] = texture2;
	
	//tank 1
	sf::Texture texture3;
	texture3.loadFromFile("Textures\\tank1.png");

	this->textures["tank1"] = texture3;

	//tank 2
	sf::Texture texture4;
	texture4.loadFromFile("Textures\\tank2.png");

	this->textures["tank2"] = texture4;

	//wall 1
	sf::Texture texture5;
	texture5.loadFromFile("Textures\\wall1.png");

	this->textures["wall1"] = texture5;

	//wall 2
	sf::Texture texture6;
	texture6.loadFromFile("Textures\\wall2.png");

	this->textures["wall2"] = texture6;

	//x
	sf::Texture texture7;
	texture6.loadFromFile("Textures\\x.png");

	this->textures["x"] = texture7;

}



void Game::updateBullet()
{

	for (int i = 0; i < bullet1.size(); i++) {
		bullet1[i]->move();
		if (bullet1[i]->checkOutScreen()) {
			bullet1.erase(bullet1.begin() + i);
			i--;
			continue;
		}

		for (auto wall : walls) {
			if (bullet1[i]->checkCollide(*wall)) {
				bullet1.erase(bullet1.begin() + i);
				i--;
				break;
			}
		}
	}

	
	for (int i = 0; i < bullet2.size(); i++) {
		bullet2[i]->move();
		if (bullet2[i]->checkOutScreen()) {
			bullet2.erase(bullet2.begin() + i);
			continue;
		}
		for (auto wall : walls) {
			if (bullet2[i]->checkCollide(*wall)) {
				bullet2.erase(bullet2.begin() + i);
				i--;
				break;
			}
		}
	}
	


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

void Game::checkBullet1Wall()
{
	for (int i = 0; i < bullet2.size(); i++) {
		bullet2[i]->move();
		if (bullet2[i]->checkOutScreen()) {
			bullet2.erase(bullet2.begin() + i);
			continue;
		}
		//for (auto wall : walls) {
		//	if (bullet2[i]->checkCollide(*wall)) {
		//		bullet2.erase(bullet2.begin() + i);
		//		i--;
		//		break;
		//	}
		//}
	}
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
			if (e.key.code == sf::Keyboard::J) {
				if (this->bullet1.size() <= 5) {
					this->bullet1.push_back(new Bullet(tank1->sprite.getPosition().x, tank1->sprite.getPosition().y, textures["bullet1"], tank1->sprite.getRotation()));
				}
			}
			if (e.key.code == sf::Keyboard::Enter) {
				if (this->bullet2.size() <= 5) {
					this->bullet2.push_back(new Bullet(tank2->sprite.getPosition().x, tank2->sprite.getPosition().y, textures["bullet2"], tank2->sprite.getRotation() + 180.f));
				}
			}
		}
	}
}

void Game::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->tank1->rotateDown();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->tank1->rotateUp();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->tank1->moveOn();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->tank1->moveBack();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		this->tank2->rotateDown();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		this->tank2->rotateUp();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		this->tank2->moveBack();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		this->tank2->moveOn();



	this->tank1->checkOutScreen();
	this->tank2->checkOutScreen();

}



void Game::update()
{
	this->updatePollEvents();
	this->updateBullet();
	this->updateInput();
}

void Game::render()
{
	this->window->clear();

	this->window->draw(background);

	this->tank1->render(*this->window);

	for (auto i : this->bullet1) {
		i->render(*this->window);
	}

	for (auto i : this->bullet2) {
		i->render(*this->window);
	}

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
