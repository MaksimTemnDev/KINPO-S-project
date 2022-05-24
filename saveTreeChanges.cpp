#define _CRT_SECURE_NO_WARNINGS

#include "string.h"
#include <iostream>
#include "Header.h"
#include <fstream>


using namespace std;

void saveTreeChanges(Accoplishment* accomplishment, char* fileName)
{
	fstream out;
	out.open(fileName, fstream::out);
	//���� ������� ������� ���� 
	if (out.is_open())
	{
		//���������� ������ ������� �������� � ����
		for (short unsigned int i = 0; i < accomplishment->firstOperandStringsCount; i++)
		{
			out << accomplishment->operandOne[i] << "\n";
		}
		//���������� ������ ������� �������� � ����
		for (short unsigned int i = 0; i < accomplishment->secondOperandStringsCount; i++)
		{
			out << accomplishment->operandTwo[i] << "\n";
		}
		//���������� ������ ��������
		out << accomplishment->operation[0] << "\n";
		//��� ������������� �������� ��������
		if (accomplishment->mod == '!')
		{
			out << accomplishment->mod;
		}
		//������� ����
		out.close();
	}
}