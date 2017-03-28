#include <fstream>
#include <iostream>
#include "Enemy.h"
#include "PacMan.h"
#include "Exit.h"
#include "Coin.h"
#include "map.h";
#include <list>    
#include <iterator>

using namespace std;
 
PacMan player;
Coin coins[200];
Enemy enemies[2];
Exit exitInGame;

int counter;

void initGameObject(int * gameObject, int count) {
	char enemies_count = 0;
	char coint_count = 0;
	for (int i = 0; i < count; i++)
	{
		switch (gameObject[i*3])
		{
		case 2:
			player = PacMan(gameObject[i * 3 + 1], gameObject[i * 3 + 2]);
			break;
		case 3:
			coins[coint_count] = Coin(gameObject[i * 3 + 1], gameObject[i * 3 + 2]);
			coint_count++;
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
	Map levelMap;
	levelMap.readMap("level.txt");
	levelMap.initMap();
	initGameObject(levelMap.initObject, levelMap.objectCount);
	system("pause");
	return 0;
}