
#include <iostream>

#include "GameObject.h"
#include "Exit.h"
#include "PrintHelper.h"

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
	setColor(1, 10);
	if (closed)
	{
		placeCursor(cord_y * 3, cord_x * 2);
		std::cout << "###";
		placeCursor(cord_y * 3, cord_x * 2 + 1);
		std::cout << "###";
	}
	else
	{
		placeCursor(cord_y * 3, cord_x * 2);
		std::cout << "   ";
		placeCursor(cord_y * 3, cord_x * 2 + 1);
		std::cout << "   ";
	}
}

// Перевіряє чи число монет дорівнює рахунку якщо це так то відкриває вихід
// TODO: Змінити механізм перевірки
void Exit::checkCoins(int coints_counter, int score)
{
	if (coints_counter == score)
	{
		closed = false;
	}
}

