#include <fstream>
#include <iostream>
#include <Windows.h>
#include "map.h"
#include "dataConvector.h"
#include "PrintHelper.h"

using namespace std;

int const STRING_WITH_NUMBER_LENGHT = 20;

Map::Map(){}

void Map::readMap(char* levelName)
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
			i++;
		}
		fin.close();
	}


void Map::initMap()
{
	objectCount = 0;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (levelMap[i][j] != 1)
			{
				initObject[objectCount * 3] = levelMap[i][j];
				initObject[objectCount * 3 + 1] = i;
				initObject[objectCount * 3 + 2] = j;
				levelMap[i][j] = 0;
				objectCount++;
			}
}

void Map::printMap()
{
	SetColor(15, 4);
	for (int i=0; i<size; i++)
		for (int j = 0; j < size; j++)
		{
			if (levelMap[i][j] == 1)
			{
				PlaceCursor(j*3, i*2);
					cout << "   ";
				PlaceCursor(j*3, i*2+1);
					cout << "   ";
			}
		}
}

void Map::cleanMap()
{
	SetColor(0, 0);
	for (int i = 0; i<size; i++)
		for (int j = 0; j < size; j++)
			if (levelMap[i][j] == 0)
			{
				PlaceCursor(j * 3, i * 2);
				cout << "   ";
				PlaceCursor(j * 3, i * 2 + 1);
				cout << "   ";
			}
}

bool Map::isEmptyBlock(int x, int y)
{
	bool result = false;
	if (levelMap[x][y] == 0)
		result = true;
	return result;
}