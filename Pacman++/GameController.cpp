//Ігровий контролер

#include <iostream>

#include "GameController.h"
#include "Enemy.h"
#include "PacMan.h"
#include "Exit.h"
#include "Coin.h"
#include "PrintHelper.h"


GameController::GameController()
{
	score = 0;
	game = true;
}

void GameController::startGame()
{
	game = true;
}

int GameController::getScore()
{
	return score;
}

bool GameController::gameState()
{
	return game;
}
//Метод перевірки зіткнення гравця з монетою.
//Приймає масив об'єктів монет в грі, їх кількість, і об'єкт гравця
//!!!Потрібно змінити масив на посилання на масив!!!
void GameController::checkCollisionWithCoins(Coin coins[], int coins_count, PacMan player)
{
	for (int i = 0; i < coins_count; i++)
		if ((coins[i].getX() == (player.getX())) && (coins[i].getY() == player.getY()) && (coins[i].getExist()))
		{
			score++;
			coins[i].hideGameObject();
		}
}

//Метод перевірки зіткнення гравця з ворогом.
//Приймає масив об'єктів ворогів в грі, їх кількість, і об'єкт гравця
//!!!Потрібно змінити масив на посилання на масив!!!
void GameController::checkCollisionWithEnemis(Enemy enemies[], int enemies_count, PacMan player)
{
	for (int i = 0; i < enemies_count; i++)
		if ((enemies[i].getX() == (player.getX())) && (enemies[i].getY() == player.getY()))
		{
			game = false;
		}
}

//Метод перевірки зіткнення гравця з виходом.
void GameController::checkCollisionWithExit(Exit levelExit, PacMan player) 
{
	if ((levelExit.getX() == (player.getX())) && (levelExit.getY() == player.getY()))
	{
		if (!(levelExit.getClosed()))
		{
			score += 10;
			game = false;
		}
	}
}
//Вивід рахунку
//!!!Потрібно зробити залежність від розмірів карти!!!
void GameController::printScore() {
	setColor(4, 6);
	placeCursor(60, 2);
	std::cout << "Score: "<< score <<"00";
}