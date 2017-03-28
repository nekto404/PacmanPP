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

