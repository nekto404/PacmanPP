#include <iostream>

#include "GameObject.h"
#include "Coin.h"
#include "PrintHelper.h"
using namespace std;

Coin::Coin() : GameObject::GameObject() {}
Coin::Coin(int x, int y) : GameObject::GameObject(x, y) {}
void Coin::printCoin()
{
	if (exist)
	{
		setColor(6, 0);
		placeCursor(cord_y * 3, cord_x * 2);
		cout << " . ";
		placeCursor(cord_y * 3, cord_x * 2 + 1);
		cout << "   ";
	}
}