#pragma once
class GameObject
{
public:
	GameObject();
	GameObject(int x, int y);
	int getX();
	int getY();
	bool getExist();
	void hideGameObject();
protected:
	int cord_x;
	int cord_y;
	bool exist;
};