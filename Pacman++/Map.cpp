#include <fstream>
#include <iostream>
#include "map.h"
#include "dataConvector.h"

using namespace std;

int const STRING_WITH_NUMBER_LENGHT = 20;


Map::Map(){}

void Map::readMap(string levelName)
	{
		char buff[STRING_WITH_NUMBER_LENGHT];
		int i = 0;
		ifstream fin(levelName);
		fin.getline(buff, STRING_WITH_NUMBER_LENGHT);
		size = charBuffToInt(buff);
		while (i < size)
		{
			fin.getline(buff, STRING_WITH_NUMBER_LENGHT);
			charBuffToArray(buff, size, levelMap[i]);
			cout << buff << endl;
			i++;
		}
		fin.close();
		cout << size << endl;
	}

void Map::initMap(int gameObjects[][3],int counter)
{
	counter = 0;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (levelMap[i][j] != 1)
			{
				gameObjects[counter][0] = levelMap[i][j];
				gameObjects[counter][1] = i;
				gameObjects[counter][2] = j;
				levelMap[i][j] = 0;
				counter++;
			}

}

