//���� ������ ��� ������ ���������� �� �����
#include <windows.h>
#include <iostream>
#include "PrintHelper.h"

//����� ���������� �������
void placeCursor(const int x, const int y) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD placeCursorHere;
	placeCursorHere.X = x;
	placeCursorHere.Y = y;
	SetConsoleCursorPosition(hConsole, placeCursorHere);
	return;
}

//����� ������ ������� ������
//������ �������� ������ ������� � ������� ����
void setColor(const int foreground, const int background) {
	int Color = foreground + (background * 16);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, Color);
	return;
}


//����� �������� ������
//TODO:������ ���������� ������ ������ ��������
void cleanScreen() {
	setColor(0, 0);
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 30; j++)
		{
			placeCursor(i, j);
			std::cout << ' ';
		}
}

// ����� ������ ����������� ��� ����� ���
void printGameOver(int score) {
	setColor(4, 0);
	placeCursor(40, 15);
	{
		std::cout << "Game over your score:"<<score;
	}
	placeCursor(0, 0);
}
