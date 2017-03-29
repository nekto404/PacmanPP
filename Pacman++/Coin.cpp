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
		SetColor(6, 0);
		PlaceCursor(cord_y * 3, cord_x * 2);
		cout << " . ";
		PlaceCursor(cord_y * 3, cord_x * 2 + 1);
		cout << "   ";
	}
}