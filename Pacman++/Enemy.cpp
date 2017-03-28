#include <iostream>

#include "GameObject.h"
#include "Enemy.h"
#include "PrintHelper.h"
using namespace std;

Enemy::Enemy() : GameObject::GameObject(){}
Enemy::Enemy(int x, int y) : GameObject::GameObject(x, y) {}
void Enemy::printEnemy()
{
	SetColor(3, 13);
	PlaceCursor(cord_y * 3, cord_x * 2);
	cout << "o o";
	PlaceCursor(cord_y * 3, cord_x * 2 + 1);
	cout << " 0 ";
}