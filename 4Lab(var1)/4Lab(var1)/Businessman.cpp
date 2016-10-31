#include "Businessman.h"
Businessman::Businessman(const char* n, const char* sn, const char* mn, int y, int l) : Human(n, sn, mn, y), m_LicenseNum(l)
{																			//Конструктор
	for (int i = 0; i < NUM; i++)											//Зануление строк
	{
		strcpy(m_Payments[i].PayDate, "");
		m_Payments[i].Sum = 0;
	}
	cout << "Businessman constuctor" << endl;
}
int Businessman::GetLicenseNum()											//Возвращение номера лицензии
{
	return m_LicenseNum;
}
const TaxPayment* const Businessman::GetTaxPayments()						//Возвращение массива платежей
{
	return m_Payments;
}
void Businessman::SetLicenseNum(int num)									//Изменение номера лицензии
{
	m_LicenseNum = num;
}
bool Businessman::AddPayment(const char* d, int s)							//Добавление платежа
{
	int i;
	for (i = 0; i < NUM; i++)
	{
		if (m_Payments[i].Sum <= 0) break;									//Если есть свободное место
	}
	if (i < NUM)															//То добовляем туда платеж
	{
		strcpy(m_Payments[i].PayDate, d);
		m_Payments[i].Sum = s;
		return true;
	}
	else return false;
}
bool Businessman::DelPayment(const char* d)									//Удаление платежа
{
	int i;
	bool x = false;
	for (i = 0; i < NUM; i++)												//Поиск по дате
	{
		if (!strcmp(m_Payments[i].PayDate, d))
		{
			strcpy(m_Payments[i].PayDate, "");								//Зануление найденой строки
			m_Payments[i].Sum = 0;
			x = true;
		}
	}
	return x;
}
ostream& operator << (ostream& os, const Businessman& aB)					//Перегрузка вывода
{
	os << dynamic_cast<const Human&>(aB);
	os << setw(20) << "Date" << setw(20) << "Sum" << endl;
	for (int i = 0; i < NUM; i++)
	{
		os << '[' << i << "]: ";
		os << setw(15) << aB.m_Payments[i].PayDate;
		os << setw(20) << aB.m_Payments[i].Sum;
		os << endl;
	}
	os << "License number: ";
	os << aB.m_LicenseNum << endl;
	return os;
}
istream& operator >> (istream& is, Businessman& aBis)						//Перегрузка ввода
{
	is >> dynamic_cast<Human&>(aBis);										//Приведение к базовому классу и ввод
	cout << "Enter license number: ";
	is >> aBis.m_LicenseNum;
	for (int i = 0; i < NUM; i++)
	{
		cout << "Enter date: ";
		is >> aBis.m_Payments[i].PayDate;
		cout << "Enter sum: ";
		is >> aBis.m_Payments[i].Sum;
	}
	return is;
}