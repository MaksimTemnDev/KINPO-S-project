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
	//если удалось открыть файл 
	if (out.is_open())
	{
		//произвести запись первого операнда в файл
		for (short unsigned int i = 0; i < accomplishment->firstOperandStringsCount; i++)
		{
			out << accomplishment->operandOne[i] << "\n";
		}
		//произвести запись второго операнда в файл
		for (short unsigned int i = 0; i < accomplishment->secondOperandStringsCount; i++)
		{
			out << accomplishment->operandTwo[i] << "\n";
		}
		//произвести запись операции
		out << accomplishment->operation[0] << "\n";
		//при необходимости записать инверсию
		if (accomplishment->mod == '!')
		{
			out << accomplishment->mod;
		}
		//закрыть файл
		out.close();
	}
}