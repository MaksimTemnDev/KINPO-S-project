#define _CRT_SECURE_NO_WARNINGS

#include "string.h"
#include <iostream>
#include "Header.h"


using namespace std;

int errorSearch(char * str)
{
	//���������� �������� �� ���������� � ������ ������� ���������\
	//������� ������ �������� �� ���������
	//char buffer[50];
	unsigned short int check = 0;
	unsigned short int needToverify = 0;
	//strcpy(buffer, str.c_str());
	for (unsigned short int i = 0; i < strlen(str); ++i)
	{
		//���� ���� �� ���������� �������� ������
		if (isdigit(str[i]))
		{
			//��������� � ��������
			needToverify = 1;
		}
		else
		{
			needToverify = 0;
			i = strlen(str);
		}
	}
	//���� ����� ����� ������ ����������
	if (strlen(str) > 14 && needToverify == 1) {
		//������� ��� ������
		check = 1;
		throw("too big value");
		return 1;
	}
	//������� ������� ��������
	return check;
}