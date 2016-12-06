#include "Array.h"
#include <iomanip>
using namespace std;
cArray::cArray(int r,int c):Rows(r),Columns(c)					//Конструктор с параметрами по умолчанию.
{
	if ((r>0)&&(c>0))
	{
		m_cArr = new int*[r];									//Выделение памяти под столбцы.
		if (!m_cArr)return;										//Если не удалось выделить, то завершаем фун.
		for (int i = 0; i < r; i++)								//Выделение памяти под строки.
		{
			m_cArr[i] = new int[c];
			if (!m_cArr[i])
			{
				for (--i; i >= 0; i--)
					delete[] m_cArr[i];
				delete[] m_cArr;
				return ;
			}
		}
		//cout << "Array was made." << endl;
	}
}
cArray::~cArray()												//Деструкор.
{
	if (m_cArr && Columns > 0 && Rows > 0)								//Если массив не пуст, то
	{
		for (int j = 0; j < Rows; j++)
			delete[] m_cArr[j];									//Проход по стокам.
		delete[] m_cArr;										//Удаления массива указателей.
		m_cArr = nullptr;										//Зануление указателя.
	}
	//cout << "Destructor" << endl;
}
cArray::cArray(cArray& a)										//Конструктор копирования.
{
	this->m_cArr = new int*[a.Rows];							//Выделения памяти под новый массив.
	for (int i = 0; i < a.Rows; i++)
		this->m_cArr[i] = new int[a.Columns];
	this->Columns = a.Columns;									//Установление разменра массива.
	this->Rows = a.Rows;
	for (int i = 0; i < this->Rows; i++)						//Копирование массива.
		for (int j = 0; j < this->Columns; j++)
			this->m_cArr[i][j] = a.m_cArr[i][j];
	//cout << "Copy constructor." << endl;
}
void cArray::Show() const										//Функция вывода массива.
{
	
	if ((Rows > 0) && (Columns >0))									//Если массива существует.
	{
		for (int i = 0; i < Rows; i++)							//Идем по строкам.
		{
			for (int j = 0; j < Columns; j++)					//Идем по столбцам.
			{
				cout << setw(3) << m_cArr[i][j];				//Вывод элемента.
			}
			cout << endl;
		}
	}
	//else cout << "Array is empty.\n";
}
void cArray::vvod()
{
	if (this->Columns > 0 && this->Rows > 0&&m_cArr)
	{
		for (int i = 0; i < Rows; i++)										//Проход по строкам.
		{
			for (int j = 0; j < Columns; j++)								//Проход по столбцам.
			{
				cin >> m_cArr[i][j];										//Ввод символа.
			}
		}
	}
}
cArray cArray::Multi(cArray& b)									//Перемножение матриц.
{
	return (*this) *= b;
}
cArray cArray::operator = (cArray& a)
{
	if (this != &a)
	{
		this->~cArray();											//Вызов деструктора.
		this->m_cArr = new int*[a.Rows];							//Выделения памяти под новый массив.
		for (int i = 0; i < a.Rows; i++)
			this->m_cArr[i] = new int[a.Columns];
		this->Columns = a.Columns;									//Установление разменра массива.
		this->Rows = a.Rows;
		for (int i = 0; i < this->Rows; i++)						//Копирование массива.
			for (int j = 0; j < this->Columns; j++)
				this->m_cArr[i][j] = a.m_cArr[i][j];
		return *this;
	}
	else return *this;
}
ostream& operator << (ostream& os,const cArray& a)
{
	if ((a.Rows>0)&&(a.Columns>0))								//Если массива существует.
	{
		for (int i = 0; i < a.Rows; i++)						//Идем по строкам.
		{
			for (int j = 0; j < a.Columns; j++)					//Идем по столбцам.
			{
				os << setw(3) << a.m_cArr[i][j];				//Вывод элемента.
			}
			os << endl;
		}
	}
	return os;
}
cArray cArray::operator * (cArray& a)
{
	if ((this->Columns == a.Rows) && this->Columns&&this->Rows&&a.Columns&&a.Rows)//Если матрицы можно перемножить, то
	{
		int x;
		cArray c(this->Rows, a.Columns);							//Создание новой матрицы с пожходящими размерами.
		for (int i = 0; i<this->Rows; i++)							//Проход по строкам первой матрицы.
			for (int j = 0; j < a.Columns; j++)						//Проход по столбцам второй матрицы.
			{
				x = 0;
				for (int k = 0; k < a.Rows; k++)
					x += (this->m_cArr[i][k] * a.m_cArr[k][j]);		//Подсчет нового элемента.
				c.m_cArr[i][j] = x;
			}
		return c;
	}
	else
	{
		return *this;												//матрицы нельзя перемножить, возвращения начальной
	}																//матрицы.
}
bool cArray::operator == (const cArray& a)
{
	if (this->Columns == a.Columns&&this->Rows == a.Rows)					//Если размеры матрицы равны,то
	{
		for(int i=0;i<a.Rows;i++)											//Проверка элементов матрицы.
			for (int j = 0; j < a.Columns; j++)
			{
				if (this->m_cArr[i][j] != a.m_cArr[i][j])return false;		//Если какой то элемент не совподает, то
			}																//возврат false.
		return true;
	}
	else
		return false;														//Возаврат false.
}
cArray cArray::operator *= (cArray& b)
{
	return (*this) = (*this)*b;												//Перемножение матриц.
}
istream& operator >> (istream& os,cArray& a)
{
	if (a.Columns > 0 && a.Rows > 0 && a.m_cArr)							//Если массив существует.
	{
		int n;
		for (int i = 0; i < a.Rows; i++)									//Проход по строкам.
		{
			for (int j = 0; j < a.Columns; j++)								//Проход по столбцам.
			{
				os >> a.m_cArr[i][j];										//Считывание элемента.
			}
		}
	}
	return os;
}
cArray cArray::operator ++ ()
{
	if ((this->Columns > 0) && (this->Rows > 0)&&m_cArr)		//Если массив есть.
	{
		for (int i = 0; i < this->Rows; i++)					//Проходимся по строкам и столбцам и
			for (int j = 0; j < this->Columns; j++)
				this->m_cArr[i][j]++;							//Увеличивем каждый элемент на 1.
	}
	return (*this);
}
cArray cArray::operator ++ (int)
{
	return ++(*this);
}