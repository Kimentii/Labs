#ifndef _SHAPE_H_													//Если данное имя еще не определено
#define _SHAPE_H_													//То определить его
#include <iostream>
#include <math.h>
#pragma warning(disable : 4996)
using namespace std;
class Shape															//Абстрактный класс
{
protected:															//protected потому что будут наследоваться
	char Name[80];
public:
	Shape(char* s = "No name")										//Конструктор с параметром по умолчанию
	{
		cout << "Shape constructor." << endl;
		strcpy_s(Name, s);
	}
	virtual ~Shape() { cout << "Shape destructor." << endl; }		//Виртуальный деструктор
	virtual void Print() = 0;										//Чистая виртуальная функция
	virtual double CountVolume() = 0;								//Чистая виртуальная функция
	virtual double CountArea() = 0;									//Чистая виртуальная функция
};
#endif																//Иначе не компилировать код до #endif