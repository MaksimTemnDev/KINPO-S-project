#pragma once
#include "string.h"

using namespace std;
struct Accoplishment
{
	unsigned short int firstOperandStringsCount; //���������� ����� � ������ ��������
	unsigned short int secondOperandStringsCount;//���������� ����� � ������ ��������
	unsigned short int stringsCount;//����� ���������� ����� � ������ ������  
	char operandOne[10][10];//������ �����, ���������� ������ �������
	char operandTwo[10][10];//������ �����, ���������� ������ �������
	char operation[2];//������ ���������� �������� ��������� ��� ���������
	char mod; //������, ��� ����� ��������� � ��������
};

/*���������� �������� �� ���������� � ������ ������� ���������*/
int errorSearch(char* str);

/*���������� ��� ������������� ���������.*/
int findOperation(char (&strMas)[10][10], int strCount);

/*�������� �������� ���������.*/
void operandsCopy(struct Accoplishment * accomplishment, char (&strMas)[10][10], int strCount);

/*�������� �������� ������ ������� ���������.*/
void treeChange(struct Accoplishment* accomplishment);

/*�������� ���������� ������ � �������� ����.*/
void saveTreeChanges(struct Accoplishment* accomplishment, char* fileName);

/*�������� ������ �������, � ����� ������������ �� ������*/
void changeOperandsStrs(struct Accoplishment* accomplishment);