#pragma once
#include "GameObject.h"
#include "Map.h"
class Enemy : public GameObject
{
public:
	Enemy();
	Enemy(int x, int y);
	void printEnemy();
	void move(Map level);
private:
	char direction=0;
	void choseDirection(Map level);
};