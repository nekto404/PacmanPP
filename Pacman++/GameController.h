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
	bool gameState();
	void checkCollisionWithCoins(Coin coins[], int coins_count, PacMan player);
	void checkCollisionWithExit(Exit levelExit, PacMan player);
	void checkCollisionWithEnemis(Enemy enemies[], int enemies_count, PacMan player);
	void printScore();
private:
	bool game;
	int score;
};