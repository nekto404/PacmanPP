#include <fstream>
#include <iostream>
#include "map.h"
#include "dataConvector.h"

using namespace std;

int const STRING_WITH_NUMBER_LENGHT = 20;


Map::Map(){}

void Map::readMap()
	{
		char buff[STRING_WITH_NUMBER_LENGHT];
		int i = 0;
		ifstream fin("level.txt");
		fin.getline(buff, STRING_WITH_NUMBER_LENGHT);
		size = charBuffToInt(buff);
		while (i < size)
		{
			fin.getline(buff, STRING_WITH_NUMBER_LENGHT);
			i++;
			charBuffToArray(buff, size, levelMap[i]);
			cout << buff << endl;
		}
		fin.close();
		cout << size << endl;
	}


