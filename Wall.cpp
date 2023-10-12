#include "Wall.h"
#include "Bullet.h"

Wall::Wall()
{
}

Wall::Wall(float x, float y) : GameObject(x, y)
{

}

Wall::~Wall()
{
}

bool checkWallCollide(std::vector<Wall*> walls, Bullet obj)
{
	for (auto i : walls) {
		if (obj.checkCollide(*i))
			return true;
	}
	return false;
}
