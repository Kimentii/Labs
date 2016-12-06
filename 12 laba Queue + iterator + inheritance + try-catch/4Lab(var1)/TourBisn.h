#pragma once
#include "Businessman.h"
#include "Tourist.h"
class TourBisn : public Businessman, public Tourist
{
private:
	char** m_Address;															//Массив строк(адресов)
	int m_NumAddress;															//Количесвто адресов
public:
	TourBisn(const char* n = "", const char* sn = "", const char* mn = "", int y = 0, int l = 0, int p = 0, int na = 0);
	TourBisn(const TourBisn&);													//Конструктор копирования
	~TourBisn();																//Деструктор
	const char** const GetAddress();											//Возвращение массива строк
	int GetNumAddress();														//Возвращение количества строк
	void AddAddress(const char* a);												//Добавление адреса
	bool DelAddress(const char* a);												//Удаление адреса
	TourBisn operator = (const TourBisn& aTB);
	friend ostream& operator << (ostream& os, const TourBisn& aTB);				//Перегрузка вывода
	friend istream& operator >> (istream& is, TourBisn& aTurBis);				//Перегрузка ввода
};