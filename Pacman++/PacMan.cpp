#include <iostream>

#include "GameObject.h"
#include "PacMan.h"
#include "PrintHelper.h"
using namespace std;

PacMan::PacMan() : GameObject::GameObject(){}
PacMan::PacMan(int x, int y): GameObject::GameObject(x,y){}
void PacMan::printPac() {
	SetColor(4, 6);
	PlaceCursor(cord_y * 3, cord_x * 2);
	cout << "o o";
	PlaceCursor(cord_y * 3, cord_x * 2 + 1);
	cout << " ~ ";
}

void PacMan::goSomewhere(Map level , char direction) {
	switch (direction)
	{
	case 1 :
		if (level.isEmptyBlock(cord_x - 1,cord_y))
		cord_x--;
		break;
	case 2 :
		if (level.isEmptyBlock(cord_x + 1, cord_y))
		cord_x++;
		break;
	case 3 :
		if (level.isEmptyBlock(cord_x, cord_y - 1))
		cord_y--;
		break;
	case 4:
		if (level.isEmptyBlock(cord_x, cord_y + 1))
		cord_y++;
		break;
	default:
		break;
	}
}
