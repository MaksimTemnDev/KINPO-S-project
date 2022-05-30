#pragma once
#include "string.h"

using namespace std;
struct Accoplishment
{
	unsigned short int firstOperandStringsCount; //количество строк в первом операнде
	unsigned short int secondOperandStringsCount;//количество строк в втором операнде
	unsigned short int stringsCount;//общее количество строк в записи дерева  
	char operandOne[10][10];//массив строк, содержащий первый операнд
	char operandTwo[10][10];//массив строк, содержащий второй операнд
	char operation[2];//строка содержащая операцию сравнения для выражений
	char mod; //символ, для знака отрицания в операции
};

/*Определить является ли содержимый в строке операнд ошибочным*/
int errorSearch(char* str);

/*Определить тип измененяемого выражения.*/
int findOperation(char (&strMas)[10][10], int strCount);

/*Записать исходные операторы.*/
void operandsCopy(struct Accoplishment * accomplishment, char (&strMas)[10][10], int strCount);

/*Изменить исходное дерево разбора выражения.*/
void treeChange(struct Accoplishment* accomplishment);

/*Записать измененные данные в выходной файл.*/
void saveTreeChanges(struct Accoplishment* accomplishment, char* fileName);

/*ПОменять строки местами, а также сопутсвующие им данные*/
void changeOperandsStrs(struct Accoplishment* accomplishment);