#pragma once
#include "Human.h"
struct Travel																//Одно путешествие
{
	char Date[SIZE];														//Дата
	char Country[SIZE];														//Страна
};
class Tourist : virtual public Human
{
protected:
	Travel m_Travels[NUM];													//Массив структур(петешествий)
	int m_PassportID;														//Номер паспорта
public:
	Tourist(const char* n = "", const char* sn = "", const char* mn = "", int y = 0, int p = 0);
	int GetPassportID();													//Возвращение номера паспорта
	const Travel* const GetTravels();										//Возвращение массива путешествий
	void SetPassportID(int p);												//Изменение номера паспорта
	bool AddTravel(const char* c, const char* d);							//Добавление путешествия
	bool DelTravel(const char* c = "", const char* d = "");					//Удаления путешествия
	friend ostream& operator << (ostream& os, const Tourist& aT);			//Перегрузка вывода
	friend istream& operator >> (istream& is, Tourist& aTur);				//Перегрузка ввода
};