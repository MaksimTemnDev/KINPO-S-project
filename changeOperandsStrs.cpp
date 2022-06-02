/* \file
*/
#define _CRT_SECURE_NO_WARNINGS

#include "string.h"
#include <iostream>
#include "Header.h"

using namespace std;

void changeOperandsStrs(struct Accoplishment* accomplishment)
{
	unsigned short int len1 = accomplishment->firstOperandStringsCount;
	unsigned short int len2 = accomplishment->secondOperandStringsCount;
	char str[10][10];
	unsigned short int j = 0;
	//!в случае когда первый операнд меньше
	if (len1 <= len2)
	{
		for (unsigned short int i = 0; i < len1; ++i)
		{
			//!скопировать первый операнд в буфферную строку
			strcpy(str[i], accomplishment->operandOne[i]);
			j = i;
		}
		for (unsigned short int i = 0; i < len2; ++i)
		{
			//!заменить первый операнд на второй
			strcpy(accomplishment->operandOne[i], accomplishment->operandTwo[i]);
			//!заменить второй операнд на значение из буффера
			if (i <= j)
				strcpy(accomplishment->operandTwo[i], str[i]);
		}
	}
	//!в случае когда второй операнд меньше
	else
	{
		for (unsigned short int i = 0; i < len2; ++i)
		{
			//!скопировать второй операнд в буфферную строку
			strcpy(str[i], accomplishment->operandTwo[i]);
			j = i;
		}
		for (unsigned short int i = 0; i < len1; ++i)
		{
			//!заменить второй операнд на первый
			strcpy(accomplishment->operandTwo[i], accomplishment->operandOne[i]);
			//!заменить перый операнд на значение из буффера
			if (i <= j)
				strcpy(accomplishment->operandOne[i], str[i]);
		}
	}
	//!помен€ть данные об длинах операндов
	accomplishment->firstOperandStringsCount = len2;
	accomplishment->secondOperandStringsCount = len1;
}