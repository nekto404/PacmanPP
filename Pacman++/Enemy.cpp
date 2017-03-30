//Опис логіки ворогів в грі

#include <iostream>

#include "GameObject.h"
#include "Enemy.h"
#include "PrintHelper.h"


Enemy::Enemy() : GameObject::GameObject(){}
Enemy::Enemy(int x, int y) : GameObject::GameObject(x, y) {}
void Enemy::printEnemy()
{
	setColor(0, 3);
	placeCursor(cord_y * 3, cord_x * 2);
	std::cout << "o o";
	placeCursor(cord_y * 3, cord_x * 2 + 1);
	std::cout << " 0 ";
}

//Метод який отримує карту гри і робить наступний крок ворога в напрямку якщо це можливо,
//інакше викликає метод для визначення нового напрямку руху
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
//Метод який отримує карту гри і визначає можливий напрямок для руху
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