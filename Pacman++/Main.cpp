#include <fstream>
#include <iostream>

#include "map.h";

using namespace std;

int main(int argc, char **argv)
{
	Map levelMap;
	levelMap.readMap();
	system("pause");
	return 0;
}