#define _CRT_SECURE_NO_WARNINGS

#include "string.h"
#include <iostream>
#include "Header.h"

using namespace std;

void treeChange(Accoplishment* accomplishment)
{
	//�������� �������� ������ ������� ���������.
	char buf[10];
	short unsigned int len = 0;
	//���� ��� �������� ������ ���� �����
	if (strncmp(accomplishment->operation, ">=", 2) == 0)
	{
		//�������� �������� �!� ����� �������� ���������
		strcpy(&accomplishment->mod, "!");
	}
	//���� ��� �������� ������
	else if (strcmp(accomplishment->operation, ">") == 0)
	{
		//�������� �������� �������
		changeOperandsStrs(accomplishment);
	}
	//����� ���� ��� �������� ������ ���� �����
	else if (strcmp(accomplishment->operation, "<=") == 0)
	{
		//�������� �������� �!� ����� �������� ���������
		strcpy(&accomplishment->mod, "!");
		// �������� �������
		changeOperandsStrs(accomplishment);
	}
	//�������� ��� �������� �� ������
	strcpy(accomplishment->operation, "<");
}