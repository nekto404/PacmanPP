#pragma once
using namespace std;
class Map {
public:
	Map();
	void readMap(string lavelName);
	void initMap(int gameObjects[][3], int count);

private:
	int size;
	int levelMap[20][20];
};