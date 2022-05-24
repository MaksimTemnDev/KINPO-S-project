#define _CRT_SECURE_NO_WARNINGS

#include "string.h"
#include <iostream>
#include "Header.h"


using namespace std;

void operandsCopy(struct Accoplishment* accomplishment, char(&strMas)[10][10], int strCount)
{
	//�������� �������� ���������
	short unsigned int arg_count = 0;
	short unsigned int arg_secCu = 0;
	short unsigned int action_secCu = 0;
	short unsigned int action_count = 0;
	short unsigned int delimiter = 0;
	char res[30] = { "\0" };
	char str[30] = { "\0" };
	char* precopy = str;
	char* pointer = res;
	//��� ������� �������� ������� �����
	for (short unsigned int i = 0; i < strCount; ++i)
	{
		//���� ������ �������� ������ ��� ������
		if (isalnum(*strMas[i]))
		{
			//�������� ������� ����������
			arg_count += 1;
		}
		else
		{
			//�������� ������� ��������
			action_count += 1;
		}
		//���� ���� ������� ��� ��������� ������ ��������� �������
		if ((action_count == arg_count - 1 && (strCount == 3 && i == 0)) || (i > 1 && action_count >= arg_count - 1 && strCount > 3))
		{
			//�������� ��������� ���������� ����� ����������
			delimiter = i;
			//�������� �������� �� ������� ������� ��������
			for (short unsigned int j = delimiter; j < strCount - 1; ++j)
			{
				if (isalnum(*strMas[j]))
				{
					//�������� ������� ����������
					arg_secCu += 1;
				}
				else
				{
					//�������� ������� ��������
					action_secCu += 1;
				}
			}
			//���� ������� �������� ����� �� �����
			if (action_secCu >= arg_secCu - 1)
				i = strCount;
		}
	}
	//�������� ������ ������� � �������� ����� ������
	strncpy(pointer, strMas[0], strlen(strMas[0]));
	for (short unsigned int i = 0; i <= delimiter; ++i)
	{
		strcpy(accomplishment->operandOne[i], strMas[i]);
	}
	//�������� ������ ������� � �������� ����� ������
	for (short unsigned int i = delimiter + 1; i < strCount - 1; ++i)
	{
		strcpy(accomplishment->operandTwo[i - delimiter - 1], strMas[i]);
	}
	//�������� ������ � ���������� ����� � ����� � � ������ �������
	accomplishment->firstOperandStringsCount = delimiter + 1;
	accomplishment->secondOperandStringsCount = strCount - 1 - accomplishment->firstOperandStringsCount;
	accomplishment->stringsCount = strCount;
}