//Набір допоміжних методів для конвертації даних

#include "DataConvector.h"

int const ASCII_DIFFERENCE = 48;
int const DECIMAL_CONST = 10;


int charBuffToInt(char buff[])
{
	int i = 0;
	int result = 0;
	while (buff[i] != '\0')
	{
		result = result * DECIMAL_CONST + (buff[i] - ASCII_DIFFERENCE);
		i++;
	}
	return result;
}

void charBuffToArray(char buff[],int lenght, int res[])
{
	for (int i = 0; i < lenght; i++)
	{
		res[i] = buff[i] - ASCII_DIFFERENCE;
	}
}