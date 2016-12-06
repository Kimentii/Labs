#include <iostream>
using namespace std;
class cArray
{
	int **m_cArr;												//Указатель на двухмерный массив.
	int Rows, Columns;											//Количество строк и столбцов.
public:
	cArray(int r=0, int c=0);									//Конструктор с параметрами по умолчанию
	~cArray();													//Деструктор.
	cArray(cArray& a);											//Конструктор копирования.
	void Show() const;											//Вывод массива.
	void vvod();												//Функция ввода массива.
	cArray Multi(cArray& b);									//Умножение матриц.
	cArray operator = (cArray& a);								//Перегрузка оператора присвоения.
	cArray operator *= (cArray& b);								//Перегрузка оператора *=.
	cArray operator * (cArray& a);								//Перегрузка оператора умножить.
	bool operator == (const cArray& a);							//Перегрузка оператора стравнения.
	cArray operator ++ ();										//Перегрузка префиксного ++
	cArray operator ++ (int);									//Перегрузка постфиксного ++
	friend ostream& operator << (ostream& os,const cArray& a);  //Перегрузка оператора вывода.
	friend istream& operator >> (istream& os,cArray& a);		//Перегрузка оператора ввода.
};