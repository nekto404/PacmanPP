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

bool Exit::getClosed()
{
	return closed;
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

void Exit::checkCoins(int coints_counter, int score)
{
	if (coints_counter == score)
	{
		closed = false;
	}
}

