/* \file
*/
#define _CRT_SECURE_NO_WARNINGS

#include "string.h"
#include <iostream>
#include "Header.h"


using namespace std;

int findOperation(char (&strMas)[10][10], int strCount) {
	//!���������� ��� ������������� ���������.
	char buf[10];
	char bigbuf[10];
	//!����������� ���������� ���������� �������� ������� � �����
	strcpy(buf, strMas[strCount - 1]);
	short int znak = 0;
	//!��������� ������������ ����������� ������
	//!���� ���������� ���������
	if (strcmp(buf, ">") == 0)
	{
		//!�������� ��� ��������
		znak = 1;
	}
	else if (strcmp(buf, "<") == 0)
	{
		//!�������� ��� ��������
		znak = 2;
	}
	else if (strcmp(buf, ">=") == 0)
	{
		//!�������� ��� ��������
		znak = 3;
	}
	else if (strcmp(buf, "<=") == 0)
	{
		//!�������� ��� ��������
		znak = 4;
	}
	else
	{
		//!�������� ��� ��������� ��������
		znak = -1;
	}
	//!������� ��� ����������
	return znak;
}