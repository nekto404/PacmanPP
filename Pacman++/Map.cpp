//Опис об'єкту карти гри
#include <fstream>
#include <iostream>
#include <Windows.h>

#include "map.h"
#include "dataConvector.h"
#include "PrintHelper.h"

int const STRING_WITH_NUMBER_LENGHT = 20;

Map::Map(){}

//Метод зчитування карти.
//Отримує назву файла карти і зчитує інформацію про карту з нього.
//В файлі в першому рядку повино міститись ціле десяткове число,
//яке відповідає за розмір карти, потім набір чисел який відповідаєть ігровим об'єктам:
//1-перешкода, 2-гравець, 3-монета, 4-ворог, 9-вихід.
void Map::readMap(char* levelName)
	{
		char buff[STRING_WITH_NUMBER_LENGHT];
		int i = 0;
		std::ifstream fin(levelName);
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

//Запис інформації про ігрові об'єкти
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
	setColor(15, 4);
	for (int i=0; i<size; i++)
		for (int j = 0; j < size; j++)
		{
			if (levelMap[i][j] == 1)
			{
				placeCursor(j*3, i*2);
				std::cout << "   ";
				placeCursor(j*3, i*2+1);
				std::cout << "   ";
			}
		}
}
//Метод що заповнює робочу область чорним кольором (Тільки місця де немає перешкод).
void Map::cleanMap()
{
	setColor(0, 0);
	for (int i = 0; i<size; i++)
		for (int j = 0; j < size; j++)
			if (levelMap[i][j] == 0)
			{
				placeCursor(j * 3, i * 2);
				std::cout << "   ";
				placeCursor(j * 3, i * 2 + 1);
				std::cout << "   ";
			}
}
//Метод що перевіряє чи немає перешкоди в блоці з координатами x,y
bool Map::isEmptyBlock(int x, int y)
{
	bool result = false;
	if (levelMap[x][y] == 0)
		result = true;
	return result;
}