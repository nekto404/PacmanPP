#pragma once
#include "Enemy.h"
#include "PacMan.h"
#include "Exit.h"
#include "Coin.h"

class GameController
{
public:
	GameController();
	void startGame();
	int getScore();
	void checkCollisionWithCoins(Coin coins[], int coins_counter, PacMan player);
	void checkCollisionWithExit(Exit levelExit, PacMan player);
	void checkCollisionWithEnemis(Enemy enemies[], int enemies_counte, PacMan player);
private:
	bool game;
	int score;
};