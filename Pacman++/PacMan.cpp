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