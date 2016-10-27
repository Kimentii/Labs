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
	os << dynamic_cast<const Human&>(aB);									//Приведение к базовому классу и вывод
	os << "License number: " << aB.m_LicenseNum << endl;
	os << "His payments: " << endl;
	for (int i = 0; i < NUM; i++)
	{
		os << "Date: " << aB.m_Payments[i].PayDate << endl;
		os << "Amount of money: " << aB.m_Payments[i].Sum << endl;
	}
	return os;
}
istream& operator >> (istream& is, Businessman& aBis)						//Перегрузка ввода
{
	is >> dynamic_cast<Human&>(aBis);										//Приведение к базовому классу и ввод
	is >> aBis.m_LicenseNum;
	for (int i = 0; i < NUM; i++)
	{
		is >> aBis.m_Payments[i].PayDate;
		is >> aBis.m_Payments[i].Sum;
	}
	return is;
}