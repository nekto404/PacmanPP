#pragma once
using namespace std;
class Map {
public:
	Map();
	void readMap(string lavelName);
	void initMap();
	int objectCount = 0;
	int initObject[600];

private:
	int size;
	int levelMap[20][20];
};