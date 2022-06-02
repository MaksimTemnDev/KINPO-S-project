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
	//!� ������ ����� ������ ������� ������
	if (len1 <= len2)
	{
		for (unsigned short int i = 0; i < len1; ++i)
		{
			//!����������� ������ ������� � ��������� ������
			strcpy(str[i], accomplishment->operandOne[i]);
			j = i;
		}
		for (unsigned short int i = 0; i < len2; ++i)
		{
			//!�������� ������ ������� �� ������
			strcpy(accomplishment->operandOne[i], accomplishment->operandTwo[i]);
			//!�������� ������ ������� �� �������� �� �������
			if (i <= j)
				strcpy(accomplishment->operandTwo[i], str[i]);
		}
	}
	//!� ������ ����� ������ ������� ������
	else
	{
		for (unsigned short int i = 0; i < len2; ++i)
		{
			//!����������� ������ ������� � ��������� ������
			strcpy(str[i], accomplishment->operandTwo[i]);
			j = i;
		}
		for (unsigned short int i = 0; i < len1; ++i)
		{
			//!�������� ������ ������� �� ������
			strcpy(accomplishment->operandTwo[i], accomplishment->operandOne[i]);
			//!�������� ����� ������� �� �������� �� �������
			if (i <= j)
				strcpy(accomplishment->operandOne[i], str[i]);
		}
	}
	//!�������� ������ �� ������ ���������
	accomplishment->firstOperandStringsCount = len2;
	accomplishment->secondOperandStringsCount = len1;
}