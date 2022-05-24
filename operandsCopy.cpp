#define _CRT_SECURE_NO_WARNINGS

#include "string.h"
#include <iostream>
#include "Header.h"


using namespace std;

void operandsCopy(struct Accoplishment* accomplishment, char(&strMas)[10][10], int strCount)
{
	//Записать исходные операторы
	short unsigned int arg_count = 0;
	short unsigned int arg_secCu = 0;
	short unsigned int action_secCu = 0;
	short unsigned int action_count = 0;
	short unsigned int delimiter = 0;
	char res[30] = { "\0" };
	char str[30] = { "\0" };
	char* precopy = str;
	char* pointer = res;
	//Для каждого элемента массива строк
	for (short unsigned int i = 0; i < strCount; ++i)
	{
		//если строка содержит чилсла или литеры
		if (isalnum(*strMas[i]))
		{
			//увеличим счетчик аргументов
			arg_count += 1;
		}
		else
		{
			//увеличим счетчик опреаций
			action_count += 1;
		}
		//если есть признак что пройденые строки форммруют операнд
		if ((action_count == arg_count - 1 && (strCount == 3 && i == 0)) || (i > 1 && action_count >= arg_count - 1 && strCount > 3))
		{
			//запомним положение разделения между операндами
			delimiter = i;
			//проведем проверку на наличие второго операнда
			for (short unsigned int j = delimiter; j < strCount - 1; ++j)
			{
				if (isalnum(*strMas[j]))
				{
					//увеличим счетчик аргументов
					arg_secCu += 1;
				}
				else
				{
					//увеличим счетчик опреаций
					action_secCu += 1;
				}
			}
			//если найдены операнды выйти из цикла
			if (action_secCu >= arg_secCu - 1)
				i = strCount;
		}
	}
	//записать первый операнд в заданную форму данных
	strncpy(pointer, strMas[0], strlen(strMas[0]));
	for (short unsigned int i = 0; i <= delimiter; ++i)
	{
		strcpy(accomplishment->operandOne[i], strMas[i]);
	}
	//записать второй операнд в заданную форму данных
	for (short unsigned int i = delimiter + 1; i < strCount - 1; ++i)
	{
		strcpy(accomplishment->operandTwo[i - delimiter - 1], strMas[i]);
	}
	//записать данные о количестве строк в целом и в каждом опернде
	accomplishment->firstOperandStringsCount = delimiter + 1;
	accomplishment->secondOperandStringsCount = strCount - 1 - accomplishment->firstOperandStringsCount;
	accomplishment->stringsCount = strCount;
}