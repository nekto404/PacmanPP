#include <fstream>
#include <iostream>

#include "map.h";

using namespace std;
 
int gameObject[200][3];
int counter;

int main(int argc, char **argv)
{
	Map levelMap;
	levelMap.readMap("level.txt");
	levelMap.initMap(gameObject, counter);
	system("pause");
	return 0;
}