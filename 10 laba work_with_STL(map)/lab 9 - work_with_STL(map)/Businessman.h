#pragma once
#include "Human.h"
struct TaxPayment																//Структура одного платежа
{
	char PayDate[SIZE];
	int Sum;
};
class Businessman : virtual public Human
{
protected:
	TaxPayment m_Payments[NUM];													//Массив структур(платежи)
public:
	Businessman(const char* n = "", const char* sn = "", const char* mn = "", int y = 0);
	const TaxPayment* const GetTaxPayments();									//Возвращения указателя на массив платежей
	bool AddPayment(const char* d, int s);										//Добавление платежа
	bool DelPayment(const char* d);												//Удаленипе платежа
	friend ostream& operator << (ostream& os, const Businessman& aB);			//Перегрузка ввода
	friend istream& operator >> (istream& is, Businessman& aBis);				//Перегрузка вывода
};