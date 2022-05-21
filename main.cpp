#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <string.h>
#include "Header.h"
#include <stdlib.h>
#include <iostream>


using namespace std;
// a>=b, !(a<b)
// a<=b, !(a>b), !(b<a)
// a>b, !(a>b), b<a

/*���������� ���������� �� �����, ����� � ������� ������, ���� ��� ����, ������ ������ � �������� ����, ����� ������� �������, �������� ������.*/

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Ru");
	char strMas[10][10];
	int strCount = 0;
	int operationType = -1;
	struct Accoplishment accomplish;
	char* output; 
	//char s1[] = "C://Users//user//source//repos//KNPO_6//Debug//in.txt";
	//char s2[] = "output";
	//output = s2;
	int i = 0;

	try {
		//������ ������, ���� ������� ���� �� ������ � ���������� ��������� ������
		if (argc < 2)
			throw ("Unnable to open source file");
		else if (argc < 3)
			throw("There is no output file name");
		//������ ������, ���� ������� ���� ���������� �������
		fstream input;
		char* in = argv[1]; //C:\Users\user\source\repos\KNPO_6\Debug\in.txt
		output = argv[2]; //C:\Users\user\source\repos\KNPO_6\Debug\output.txt
		//char* in = s1;
		//char* output  = s2;
		input.open(in, fstream::in);
		if (input.is_open() == 0)
			throw("Can not open source file");
		while(!input.eof() && i<10)
		{
			input >> strMas[i];
			//��������� ������������ ������� ������.
			errorSearch(strMas[i]);
			if (strstr(strMas[i], "<") != NULL || strstr(strMas[i], ">") != NULL || strstr(strMas[i], "=") != NULL)
				i += 10;
			strCount++;
			i++;
		}
		if (strCount < 3)
			throw("error, too few lines");
	//���������� ��� ������������� ���������.
	operationType = findOperation(strMas, strCount);
	//�������� �� ������� ������������ ��������
	if (operationType == -1)
		throw("wrong operation type");
	else
	{
		// ����� �� ��������������� �������� ��� ������ � ������������� ��������
		switch (operationType)
		{
		case 1:
			strcpy(accomplish.operation, ">");
			break;
		case2:
			strcpy(accomplish.operation, "<");
			break;
		case 3:
			strcpy(accomplish.operation, ">=");
			break;
		case 4:
			strcpy(accomplish.operation, "<=");
			break;
		default:
			break;
		}
		//�������� �������� ���������.
		operandsCopy(&accomplish, strMas, strCount);
	}
	}
	//���� ���� ������
	catch (const char* exception)
	{
		//����������� � � ������� ������
		cout << exception;
		//��������� ������ ���������
		return 0;
	}
	//�������� �������� ������
	treeChange(&accomplish);
	//�������� ������ ����� � �������� ����...
	saveTreeChanges(&accomplish, output);
	//getchar();
	return 0;
}