#include <windows.h>
#include "PrintHelper.h"

void PlaceCursor(const int x, const int y) {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD PlaceCursorHere;
	PlaceCursorHere.X = x;
	PlaceCursorHere.Y = y;
	SetConsoleCursorPosition(hConsole, PlaceCursorHere);
	return;
}

void SetColor(const int foreground, const int background) {
	int Color = foreground + (background * 16);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, Color);
	return;
}