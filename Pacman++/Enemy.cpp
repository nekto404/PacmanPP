#include "GameObject.h"
#include "Enemy.h"

Enemy::Enemy() : GameObject::GameObject(){}
Enemy::Enemy(int x, int y) : GameObject::GameObject(x, y) {}