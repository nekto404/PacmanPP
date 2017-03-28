#include <iostream>

#include "GameObject.h"
#include "Exit.h"
#include "PrintHelper.h"
using namespace std;

Exit::Exit() : GameObject::GameObject()
{
	closed = true;
}
Exit::Exit(int x, int y) : GameObject::GameObject(x, y) 
{
	closed = true;
}
void Exit::printExit()
{
	SetColor(1, 10);
	if (closed)
	{
		PlaceCursor(cord_y * 3, cord_x * 2);
		cout << "###";
		PlaceCursor(cord_y * 3, cord_x * 2 + 1);
		cout << "###";
	}
	else
	{
		PlaceCursor(cord_y * 3, cord_x * 2);
		cout << "   ";
		PlaceCursor(cord_y * 3, cord_x * 2 + 1);
		cout << "   ";
	}
}