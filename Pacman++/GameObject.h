#pragma once
class GameObject
{
public:
	GameObject();
	GameObject(int x, int y);

private:
	int cord_x;
	int cord_y;
	bool exist;
};