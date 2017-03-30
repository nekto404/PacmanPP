#include <fstream>
#include <iostream>
#include <windows.h>

#include "Enemy.h"
#include "PacMan.h"
#include "Exit.h"
#include "Coin.h"
#include "map.h";
#include "GameController.h"
#include "PrintHelper.h"

Map levelMap;
GameController gameController;
PacMan player;
Coin coins[200];
Enemy enemies[4];
Exit exitInGame;
char enemies_count = 0;
char coins_count = 0;

//Ініціалізація ігрових об'єктів
void initGameObject(int * gameObject, int count) {
	for (int i = 0; i < count; i++)
	{
		switch (gameObject[i*3])
		{
		case 2:
			player = PacMan(gameObject[i * 3 + 1], gameObject[i * 3 + 2]);
			break;
		case 3:
			coins[coins_count] = Coin(gameObject[i * 3 + 1], gameObject[i * 3 + 2]);
			coins_count++;
			break;
		case 4:
			enemies[enemies_count] = Enemy(gameObject[i * 3 + 1], gameObject[i * 3 + 2]);
			enemies_count++;
			break;
		case 9:
			exitInGame = Exit(gameObject[i * 3 + 1], gameObject[i * 3 + 2]);
			break;
		}
	}
}

//Опис логіки однонієї іргової миті
void gameTick()
{
	//Зчитування дій гравця і реакція на них
	if (GetAsyncKeyState(VK_UP)) player.goSomewhere(levelMap, 1);
	if (GetAsyncKeyState(VK_DOWN)) player.goSomewhere(levelMap, 2);
	if (GetAsyncKeyState(VK_LEFT)) player.goSomewhere(levelMap, 3);
	if (GetAsyncKeyState(VK_RIGHT)) player.goSomewhere(levelMap, 4);
	if (GetAsyncKeyState(VK_ESCAPE))  exit(0);
	//Очищення області
	levelMap.cleanMap();
	//Вивід елементів
	exitInGame.printExit();
	for (int i = 0; i < coins_count; i++)
	coins[i].printCoin();
	gameController.checkCollisionWithEnemis(enemies, enemies_count, player);
	for (int i = 0; i < enemies_count; i++)
	{
		enemies[i].move(levelMap);
		enemies[i].printEnemy();
	}
	player.printPac();
	//Перевірка колізій
	gameController.checkCollisionWithCoins(coins, coins_count, player);
	gameController.printScore();
	gameController.checkCollisionWithExit(exitInGame, player);
	gameController.checkCollisionWithEnemis(enemies, enemies_count, player);
	exitInGame.checkCoins(coins_count, gameController.getScore());
	if (!(gameController.gameState())) cleanScreen();
	Sleep(250);	//Пауза до наступного кроку
}

int main(int argc, char **argv)
{

	levelMap.readMap("level.txt");
	levelMap.initMap();
	initGameObject(levelMap.initObject, levelMap.objectCount);
	levelMap.printMap();
	while (gameController.gameState()) 
		gameTick();
	printGameOver(gameController.getScore());
	Sleep(2000);
	return 0;
}