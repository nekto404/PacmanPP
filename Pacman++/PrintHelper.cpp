// Набір методів для виводу данних

#include <windows.h>
#include <iostream>

#include "PrintHelper.h"

//Метод для переміщення курсора в точку з координатами x,y.
void placeCursor(const int x, const int y) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD placeCursorHere;
	placeCursorHere.X = x;
	placeCursorHere.Y = y;
	SetConsoleCursorPosition(hConsole, placeCursorHere);
	return;
}
//Метод для мибору кольору. На вхід приймає значення кольору символу і його фону.
void setColor(const int foreground, const int background) {
	int Color = foreground + (background * 16);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, Color);
	return;
}
//Метод що заповнює робочу область чорним кольором
//!!!Додати можливість вибирати область для очищення!!!
void cleanScreen() {
	setColor(0, 0);
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 30; j++)
		{
			placeCursor(i, j);
			std::cout << ' ';
		}
}

//Метод що виводить повідомлення про кінець гри
void printGameOver(int score) {
	setColor(4, 0);
	placeCursor(40, 15);
	{
		std::cout << "Game over your score: "<<score<<"00";
	}
	placeCursor(0, 0);
}
