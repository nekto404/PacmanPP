#pragma once
class GameObject
{
public:
	GameObject();
	GameObject(int x, int y);

protected:
	int cord_x;
	int cord_y;
	bool exist;
};