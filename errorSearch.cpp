#define _CRT_SECURE_NO_WARNINGS

#include "string.h"
#include <iostream>
#include "Header.h"


using namespace std;

int errorSearch(char * str)
{
	//Определить является ли содержимый в строке операнд ошибочным\
	//Разбить строку аргумент на подстроки
	//char buffer[50];
	unsigned short int check = 0;
	unsigned short int needToverify = 0;
	//strcpy(buffer, str.c_str());
	for (unsigned short int i = 0; i < strlen(str); ++i)
	{
		//Если один из аргументов является числом
		if (isdigit(str[i]))
		{
			//допустить к проверке
			needToverify = 1;
		}
		else
		{
			needToverify = 0;
			i = strlen(str);
		}
	}
	//Если длина числа больше допустимой
	if (strlen(str) > 14 && needToverify == 1) {
		//Вернуть код ошибки
		check = 1;
		throw("too big value");
		return 1;
	}
	//Вернуть нулевое значение
	return check;
}