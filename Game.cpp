#include "Game.h"
#include "Wall.h"



Game::Game()
{
	this->initWindow();
	this->initTextures();
	this->initTank1();
	this->initTank2();
	this->initWall();
	this->initString();
	this->initShield();
	this->initSound();

	this->music.play();

}

Game::~Game()
{
	delete this->window;
	delete this->tank1;
	delete this->tank2;
	
	for (auto wall : walls) {
		delete wall;
	}
	delete this->shieldItem;
	
	for (auto butllet : this->bullet1) {
		delete butllet;
	}

	for (auto butllet : this->bullet2) {
		delete butllet;
	}

	

}

//Init
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

void Game::initString()
{

	font.loadFromFile("arial.ttf");

	this->text.setFont(font);
	this->text.setCharacterSize(140);
	this->text.setPosition(220, 450);
	this->text.setFillColor(sf::Color::Red);
	this->text.setStyle(sf::Text::Bold);
}

void Game::initSound()
{
	if (!this->tankShootbuffer.loadFromFile("Sound\\tankShoot.wav")) {
		std::cout << "-1";
	}
	this->tankShootSound.setBuffer(tankShootbuffer);
	this->tankShootSound.setVolume(50.f);

	this->victorybuffer.loadFromFile("Sound\\victory.mp3");
	this->victorySound.setBuffer(victorybuffer);

	if (!this->taoCoKhienbuffer.loadFromFile("Sound\\TaoCoKhien.wav")) {
		std::cout << "-1";
	}
	this->taoCoKhienSound.setBuffer(taoCoKhienbuffer);

	this->HetKhienRoibuffer.loadFromFile("Sound\\HetKhienRoi.wav");
	this->HetKhienRoiSound.setBuffer(HetKhienRoibuffer);

	this->music.openFromFile("Sound\\music.mp3");
	this->music.setLoop(true);
	this->music.setVolume(60.f);

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

	//shield
	sf::Texture texture8;
	texture8.loadFromFile("Textures\\shield.png");

	this->textures["shield"] = texture8;

	//explosion
	sf::Texture texture9;
	texture9.loadFromFile("Textures\\explosion.png");

	this->textures["explosion"] = texture9;

}

//end init



void Game::updateBullet()
{

	for (int i = 0; i < bullet1.size(); i++) {
		bullet1[i]->move();
		
		if (bullet1[i]->checkCollide(*this->tank2)) {
			this->explosions.push_back(new Explosion(bullet1[i]->sprite.getPosition().x, bullet1[i]->sprite.getPosition().y, textures["explosion"]));
			if(!tank2->shieldsCount){
				this->music.pause();
				this->victorySound.play();
				text.setString("Player 1 wins! Hoang nguuu\nBam Backspace to restart");
				this->isEndGame = true;
				return;
			}
			else {
				this->HetKhienRoiSound.play();
				tank2->shieldsCount--;
				bullet1.clear();
				break;
			}
		}

		if (bullet1[i]->checkOutScreen()) {
			this->explosions.push_back(new Explosion(bullet1[i]->sprite.getPosition().x, bullet1[i]->sprite.getPosition().y, textures["explosion"]));

			bullet1.erase(bullet1.begin() + i);
			i--;
			continue;
		}

		for (auto wall : walls) {
			if (bullet1[i]->checkCollide(*wall)) {
				this->explosions.push_back(new Explosion(bullet1[i]->sprite.getPosition().x, bullet1[i]->sprite.getPosition().y, textures["explosion"]));
				bullet1.erase(bullet1.begin() + i);
				i--;
				break;
			}
		}

		
	}

	
	for (int i = 0; i < bullet2.size(); i++) {
		bullet2[i]->move();

		if (bullet2[i]->checkCollide(*this->tank1)) {
			this->explosions.push_back(new Explosion(bullet2[i]->sprite.getPosition().x, bullet2[i]->sprite.getPosition().y, textures["explosion"]));
			if(!tank1->shieldsCount){
				this->music.pause();
				this->victorySound.play();
				text.setString("Player 2 wins! Dat nguuu\nBam Backspace to restart");
				this->isEndGame = true;
				return;
			}
			else {
				this->HetKhienRoiSound.play();
				tank1->shieldsCount--;
				bullet2.clear();
				break;
			}
		}

		if (bullet2[i]->checkOutScreen()) {
			this->explosions.push_back(new Explosion(bullet2[i]->sprite.getPosition().x, bullet2[i]->sprite.getPosition().y, textures["explosion"]));
			bullet2.erase(bullet2.begin() + i);
			continue;
		}
		for (auto wall : walls) {
			if (bullet2[i]->checkCollide(*wall)) {
				this->explosions.push_back(new Explosion(bullet2[i]->sprite.getPosition().x, bullet2[i]->sprite.getPosition().y, textures["explosion"]));
				bullet2.erase(bullet2.begin() + i);
				i--;
				break;
			}
		}		
	}
}

void Game::checkTank(Tank* tank)
{	
	for (int i = 0; i < 6; i++) {
		if (tank->checkCollide(*walls[i])) {
			if (i < 3) {
				tank->sprite.setPosition(1750.f, 1190.f);
			}
			else {
				tank->sprite.setPosition(500.f, 1190.f);
			}
			return;
		}
	}

	if (isShieldAvail)
		if (tank->checkCollide(*this->shieldItem))
		{
			this->taoCoKhienSound.play();
			isShieldAvail = false;
			if (tank->shieldsCount < 3)
				tank->shieldsCount++;
		}
}

void Game::updateExplosion()
{
	for (int i = 0; i < explosions.size(); i++) {
		if (explosions[i]->checkDone()) {
			explosions.erase(explosions.begin() + i);
			i--;
			continue;
		}
	}
}

void Game::initShield()
{
	for (int i = 0; i < 3; i++) {
		this->shield1.push_back(new Shield(100.f + 100.f * i, 80.f, textures["shield"]));
		this->shield2.push_back(new Shield(2000.f - 100.f * i, 80.f, textures["shield"]));
	}
	this->shieldItem = new Shield(1080.f, 200.f, textures["shield"]);
	this->shieldItem->sprite.setPosition(1080.f, rand() % 1000 + 150.f);
	this->shieldItem->sprite.setScale(0.6, 0.6);
}

void Game::updateShield()
{
	sf::Time elapsed1 = clock.getElapsedTime();
	if (isShieldAvail) {
		clock.restart();
	}
	if(!isShieldAvail)
	{
		if (elapsed1 >= this->resetTime) {

			this->isShieldAvail = true;
			this->shieldItem->sprite.setPosition(1080.f, rand() % 1000 + 150.f);
			this->resetTime = sf::seconds(rand() % 5 + 10.f);
			clock.restart();
		}
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
				if (this->bullet1.size() < 1) {
					this->tankShootSound.play();
					this->bullet1.push_back(new Bullet(tank1->sprite.getPosition().x, tank1->sprite.getPosition().y, textures["bullet1"], tank1->sprite.getRotation()));
				}
			}
			if (e.key.code == sf::Keyboard::Enter) {
				if (this->bullet2.size() < 1) {
					this->tankShootSound.play();
					this->bullet2.push_back(new Bullet(tank2->sprite.getPosition().x, tank2->sprite.getPosition().y, textures["bullet2"], tank2->sprite.getRotation() + 180.f));
				}
			}
			if (e.key.code == sf::Keyboard::BackSpace) {
				if(this->isEndGame)
				{
					this->isEndGame = false;
					this->isShieldAvail = false;
					this->clock.restart();
					this->music.play();
					initTank1();
					initTank2();
					this->explosions.clear();
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

	checkTank(tank1);
	checkTank(tank2);


}



void Game::update()
{
	this->updatePollEvents();
	if(!isEndGame)
	this->updateBullet();
	this->updateInput();
	this->updateShield();
	this->updateExplosion();
}

void Game::render()
{
	this->window->clear();

	this->window->draw(background);

	if (isEndGame) {
		bullet1.clear();
		bullet2.clear();
		this->window->draw(text);
	}
	else {
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

		for (int i = 0; i < this->tank1->shieldsCount; i++) {
			this->shield1[i]->render(*this->window);
		}
		
		for (int i = 0; i < this->tank2->shieldsCount; i++) {
			this->shield2[i]->render(*this->window);
		}

		if(isShieldAvail)
			this->shieldItem->render(*this->window);

		for (auto explosion : explosions) {
			explosion->render(*this->window);
		}
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
