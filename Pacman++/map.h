#pragma once
class Map {
public:
	Map();
	void readMap();

private:
	int size;
	int levelMap[20][20];
};