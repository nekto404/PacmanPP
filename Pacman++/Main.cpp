#include <fstream>
#include <iostream>
#include "Enemy.h"
#include "PacMan.h"
#include "Exit.h"
#include "Coin.h"
#include "map.h";
#include <windows.h>

using namespace std;
 
PacMan player;
Coin coins[200];
Enemy enemies[2];
Exit exitInGame;
char enemies_count = 0;
char coins_count = 0;

int counter;

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


int main(int argc, char **argv)
{
	/*DownArrow = GetAsyncKeyState(VK_DOWN);
	LeftArrow = GetAsyncKeyState(VK_LEFT);
	RightArrow = GetAsyncKeyState(VK_RIGHT);*/


	Map levelMap;
	levelMap.readMap("level.txt");
	levelMap.initMap();
	initGameObject(levelMap.initObject, levelMap.objectCount);

	while (true) {
		if (GetAsyncKeyState(VK_UP)) {
			cout << "UP" << endl;
		}
		if (GetAsyncKeyState(VK_DOWN)) {
			cout << "DOWN" << endl;
		}
		if (GetAsyncKeyState(VK_LEFT)) {
			cout << "LEFT" << endl;
		}
		if (GetAsyncKeyState(VK_RIGHT)) {
			cout << "RIGHT" << endl;
		}
		if (GetAsyncKeyState(VK_ESCAPE)) { exit(0); }
		
		
		levelMap.printMap();
		player.printPac();
		exitInGame.printExit();
		for (int i = 0; i < enemies_count; i++)
		{
			enemies[i].printEnemy();
		}
		for (int i = 0; i < coins_count; i++)
		{
			coins[i].printCoin();
		}
		Sleep(250);
	}

	system("pause");

	return 0;
}