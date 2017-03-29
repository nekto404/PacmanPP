#include <iostream>

#include "GameObject.h"
#include "Enemy.h"
#include "PrintHelper.h"
using namespace std;

Enemy::Enemy() : GameObject::GameObject(){}
Enemy::Enemy(int x, int y) : GameObject::GameObject(x, y) {}
void Enemy::printEnemy()
{
	SetColor(0, 3);
	PlaceCursor(cord_y * 3, cord_x * 2);
	cout << "o o";
	PlaceCursor(cord_y * 3, cord_x * 2 + 1);
	cout << " 0 ";
}

void Enemy::move(Map level)
{
	bool step = false;
	switch (direction)
	{
	case 1:
		if (level.isEmptyBlock(cord_x - 1, cord_y))
			cord_x--;
		else
			choseDirection(level);
		break;
	case 2:
		if (level.isEmptyBlock(cord_x + 1, cord_y))
			cord_x++;
		else
			choseDirection(level);
		break;
	case 3:
		if (level.isEmptyBlock(cord_x, cord_y - 1))
			cord_y--;
		else
			choseDirection(level);
		break;
	case 4:
		if (level.isEmptyBlock(cord_x, cord_y + 1))
			cord_y++;
		else
			choseDirection(level);
		break;
	default:
		choseDirection(level);
		break;
	}
}

void Enemy::choseDirection(Map level)
{
	direction = 1+rand() % (4);
	switch (direction)
	{
	case 1:
		if (level.isEmptyBlock(cord_x - 1, cord_y))
			cord_x--;
		else
			choseDirection(level);
		break;
	case 2:
		if (level.isEmptyBlock(cord_x + 1, cord_y))
			cord_x++;
		else
			choseDirection(level);
		break;
	case 3:
		if (level.isEmptyBlock(cord_x, cord_y - 1))
			cord_y--;
		else
			choseDirection(level);
		break;
	case 4:
		if (level.isEmptyBlock(cord_x, cord_y + 1))
			cord_y++;
		else
			choseDirection(level);
		break;
	default:
		choseDirection(level);
		break;
	}
}