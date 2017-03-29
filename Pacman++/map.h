#pragma once
class Map {
public:
	int objectCount = 0;
	int initObject[600];
	Map();
	void readMap(char * lavelName);
	void initMap();
	void printMap();
	void cleanMap();
	bool isEmptyBlock(int x, int y);

private:
	int size;
	int levelMap[20][20];
};