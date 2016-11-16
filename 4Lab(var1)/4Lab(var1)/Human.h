#pragma once
#include <iostream>
#include <cstring>
#include <iomanip>
#include "SafeFunctions.h"
#pragma warning (disable:4996)
const int NUM = 1;
const int SIZE = 80;
using namespace std;
class Human
{
protected:
	char m_Name[SIZE];														//Имя
	char m_SurName[SIZE];													//Фамилия
	char m_MiddleName[SIZE];												//Отчество
	int m_YearOfBirth;														//Год рождения
public:
	Human(const char* n = "", const char* sn = "", const char* mn = "", int y = 0);
	const char* const GetName();											//Возвращение имени(только для просмотрма)
	const char* const GetSurName();											//Возвращение фамилии(только для просмотрма)
	const char* const GetMiddleName();										//Возвращение отчества(только для просмотрма)
	int GetYear();															//Возвращение года рождения
	void SetName(const char* n);											//Изменение имени
	void SetSurName(const char* sn);										//Изменение фамилии
	void SetMiddleName(const char* mn);										//Изменение отчества
	void SetYearOfBirth(int y);												//Изменения года рождения
	friend ostream& operator << (ostream& os, const Human& aHum);			//Перегрузка вывода
	friend istream& operator >> (istream& is, Human& aHum);					//Перегрузка ввода
	bool operator == (const Human& aHum);
	bool operator != (const Human& aHum);
	bool operator > (const Human& aHum);
	bool operator < (const Human& aHum);
};