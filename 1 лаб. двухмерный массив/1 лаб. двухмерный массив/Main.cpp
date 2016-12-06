#include "Array.h"
using namespace std;
void *operator new(size_t tip, int n, int r, int c)
{
	void *p = new char[n*tip];					//Выделяем массив элементов
	for (int i = 0; i < n; i++)					//Проходим по нему и вызываем везде конструктор.
		((cArray*)p)[i].cArray::cArray();
	return p;
}
int main()
{
	int r, c;
	cout << "Enter number of rows:";
	cin >> r;
	cout << "Enter number of columns:";
	cin >> c;
	cArray A(r, c);												//Вызов конструктора с параметрами.
	cout << "Enter array A:";
	cin >> A;													//Перегрузка оперратора ввода.
	cArray B = A,C;												//Вызов констр. копирования и констр. с пар. по умолч.
	C = B;														//Перегрузка оператора =.
	cout << "Array A:" << endl << A;							//Перегрузка оператора вывода.
	cout << "Array B:" << endl;
	B.Show();													//Функция вывода массива.
	cout << "Array C" << endl << C;
	C++;														//Вызов перегрузка постфиксного инкремента.
	cout << "Array C after ++(int) and ++:" <<endl<< ++C;		//Перегрузка префиксного инкремента.
	cout << "Now enter array C:" << endl;
	C.vvod();													//Функция вывода.
	cout << "Is C == A? ";
	if (C == A)													//Перегрузка оператора ==
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	cout << "Now C*=A:" << endl;
	C *= A *= A *= A;														//Перегрузка оператора *=
	cout<<C<< endl;
	B = A*A;													//Перегрузка оператора *.
	cout << "Now B = A * A:" << endl<<B << endl;
	B.Multi(A);													//Функция перемножения матриц.
	cout << "Now B.Multi(A):" <<endl<< B << endl;
	system("pause");
	return 0;
}