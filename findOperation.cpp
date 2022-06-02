/* \file
*/
#define _CRT_SECURE_NO_WARNINGS

#include "string.h"
#include <iostream>
#include "Header.h"


using namespace std;

int findOperation(char (&strMas)[10][10], int strCount) {
	//!Определить тип измененяемого выражения.
	char buf[10];
	char bigbuf[10];
	//!Скопировать содержимое последнего элемента массива в буфер
	strcpy(buf, strMas[strCount - 1]);
	short int znak = 0;
	//!Проверить корректность содержимого буфера
	//!Если содержимое корректно
	if (strcmp(buf, ">") == 0)
	{
		//!Записать код операции
		znak = 1;
	}
	else if (strcmp(buf, "<") == 0)
	{
		//!Записать код операции
		znak = 2;
	}
	else if (strcmp(buf, ">=") == 0)
	{
		//!Записать код операции
		znak = 3;
	}
	else if (strcmp(buf, "<=") == 0)
	{
		//!Записать код операции
		znak = 4;
	}
	else
	{
		//!Записать код ошибочной операции
		znak = -1;
	}
	//!Вернуть код результата
	return znak;
}