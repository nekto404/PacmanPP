//Опис загаліної логіки всіх ігрових об'єктів

#include "GameObject.h"

GameObject::GameObject()
{
	exist = false;
	cord_x = 0;
	cord_y = 0;
}
GameObject::GameObject(int x , int y)
{
	exist = true;
	cord_x = x;
	cord_y = y;
}
int GameObject::getX()
{
	return cord_x;
}
int GameObject::getY()
{
	return cord_y;
}
bool GameObject::getExist()
{
	return exist;
}
void GameObject::hideGameObject()
{
	exist = false;
}
