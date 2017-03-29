#pragma once
#include "GameObject.h"
#include "map.h"

class PacMan : public GameObject
{
public:
	PacMan();
	PacMan(int x, int y);
	void printPac();
	void goSomewhere(Map level, char direction);
};