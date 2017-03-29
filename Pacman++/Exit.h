#pragma once
#include "GameObject.h"

class Exit : public GameObject
{
public:
	Exit();
	Exit(int x, int y);
	void printExit();
	bool getClosed();
	void checkCoins(int coints_counter, int score);
private:
	bool closed;
};