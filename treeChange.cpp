#define _CRT_SECURE_NO_WARNINGS

#include "string.h"
#include <iostream>
#include "Header.h"

using namespace std;

void treeChange(Accoplishment* accomplishment)
{
	//»зменить исходное дерево разбора выражени€.
	char buf[10];
	short unsigned int len = 0;
	//≈сли тип операции больше либо равно
	if (strncmp(accomplishment->operation, ">=", 2) == 0)
	{
		//ƒобавить операцию С!Т после операции сравнени€
		strcpy(&accomplishment->mod, "!");
	}
	//если тип операции больше
	else if (strcmp(accomplishment->operation, ">") == 0)
	{
		//ѕомен€ть операнды местами
		changeOperandsStrs(accomplishment);
	}
	//»наче если тип операции меньше либо равно
	else if (strcmp(accomplishment->operation, "<=") == 0)
	{
		//ƒобавить операцию С!Т после операции сравнени€
		strcpy(&accomplishment->mod, "!");
		// операнды местами
		changeOperandsStrs(accomplishment);
	}
	//«аменить тип операции на меньше
	strcpy(accomplishment->operation, "<");
}