#include "TourBisn.h"
TourBisn::TourBisn(const char* n, const char* sn, const char* mn, int y, int l, int p, int na) : Human(n, sn, mn, y)
{																			//Конструктор
	Businessman::m_LicenseNum = l;
	Tourist::m_PassportID = p;
	m_NumAddress = na;
	if (na > 0)																//Если введено конкретное значение
	{																		//количества адресов, то
		m_Address = new char*[na];											//Выделение памяти под них
		for (int i = 0; i < na; i++)
		{
			m_Address[i] = new char[SIZE];
			strcpy(m_Address[i], "");
		}
	}
	else
	{
		m_Address = nullptr;
	}
	cout << "TourBisn constructor" << endl;
}
TourBisn::TourBisn(const TourBisn& aTurBis)									//Конструктор копирования
{
	strcpy(m_Name, aTurBis.m_Name);											//Копирование переменных данных
	strcpy(m_SurName, aTurBis.m_SurName);
	strcpy(m_MiddleName, aTurBis.m_MiddleName);
	m_NumAddress = aTurBis.m_NumAddress;
	m_LicenseNum = aTurBis.m_LicenseNum;
	m_PassportID = aTurBis.m_PassportID;
	m_YearOfBirth = aTurBis.m_YearOfBirth;
	for (int i = 0; i < NUM; i++)											//Копирование путешествий и плтежей
	{
		strcpy(m_Travels[i].Country, aTurBis.m_Travels[i].Country);
		strcpy(m_Travels[i].Date, aTurBis.m_Travels[i].Date);
		strcpy(m_Payments[i].PayDate, aTurBis.m_Payments[i].PayDate);
		m_Payments[i].Sum = aTurBis.m_Payments[i].Sum;
	}
	if (aTurBis.m_NumAddress > 0)											//Переписывание динамическиз данных
	{
		m_Address = new char*[aTurBis.m_NumAddress];
		for (int i = 0; i < aTurBis.m_NumAddress; i++)
		{
			m_Address[i] = new char[SIZE];
			strcpy(m_Address[i], aTurBis.m_Address[i]);
		}
	}
	else
	{
		m_Address = nullptr;
	}
}
TourBisn::~TourBisn()														//Деструктор
{
	for (int i = 0; i < m_NumAddress; i++)
	{
		delete[] m_Address[i];
	}
	delete[] m_Address;
	m_NumAddress = 0;
	cout << "TourBisn destuctor" << endl;
}
const char** const TourBisn::GetAddress()									//Возвращает массив адресов
{
	return const_cast<const char** const>(m_Address);
}
int TourBisn::GetNumAddress()
{
	return 	m_NumAddress;
}
void TourBisn::AddAddress(const char* a)									//Добавление адреса
{
	if (m_NumAddress > 0)													//Если количество адресов верно
	{
		for (int i = 0; i < m_NumAddress; i++)								//Поиск пустых адресов
		{
			if (!strlen(m_Address[i]))
			{
				strcpy(m_Address[i], a);
				return;
			}
		}
		char** buf = new char*[m_NumAddress + 1];							//Иначе перевыделение массива строк
		buf[m_NumAddress] = new char[SIZE];
		for (int i = 0; i < m_NumAddress; i++)
		{
			buf[i] = m_Address[i];
		}
		strcpy(buf[m_NumAddress], a);										//И добавление нового адреса
		m_NumAddress++;
		delete[] m_Address;
		m_Address = buf;
	}
	else																	//Созжание одного адреса
	{
		m_NumAddress = 1;
		m_Address = new char*[1];
		m_Address[0] = new char[SIZE];
		strcpy(m_Address[0], a);
	}
}
bool TourBisn::DelAddress(const char* a)									//Удаление адреса
{
	bool x = false;
	if (m_NumAddress > 0)													//Если адреса существуют
	{
		for (int i = 0; i < m_NumAddress; i++)								//Поиск данного адреса
		{
			if (!strcmp(m_Address[i], a))									//Зануление нужного адреса
			{
				strcpy(m_Address[i], "");
				x = true;
			}
		}
	}
	return false;

}
TourBisn TourBisn::operator = (const TourBisn& aTurBis)
{
	for (int i = 0; i < m_NumAddress; i++)
	{
		delete[] m_Address[i];
	}
	delete[] m_Address;
	strcpy(m_Name, aTurBis.m_Name);											//Копирование переменных данных
	strcpy(m_SurName, aTurBis.m_SurName);
	strcpy(m_MiddleName, aTurBis.m_MiddleName);
	m_NumAddress = aTurBis.m_NumAddress;
	m_LicenseNum = aTurBis.m_LicenseNum;
	m_PassportID = aTurBis.m_PassportID;
	m_YearOfBirth = aTurBis.m_YearOfBirth;
	for (int i = 0; i < NUM; i++)											//Копирование путешествий и плтежей
	{
		strcpy(m_Travels[i].Country, aTurBis.m_Travels[i].Country);
		strcpy(m_Travels[i].Date, aTurBis.m_Travels[i].Date);
		strcpy(m_Payments[i].PayDate, aTurBis.m_Payments[i].PayDate);
		m_Payments[i].Sum = aTurBis.m_Payments[i].Sum;
	}
	if (aTurBis.m_NumAddress > 0)											//Переписывание динамическиз данных
	{
		m_Address = new char*[aTurBis.m_NumAddress];
		for (int i = 0; i < aTurBis.m_NumAddress; i++)
		{
			m_Address[i] = new char[SIZE];
			strcpy(m_Address[i], aTurBis.m_Address[i]);
		}
	}
	else
	{
		m_Address = nullptr;
	}
	return *this;
}
ostream& operator << (ostream& os, const TourBisn& aTB)						//Перегрузка вывода
{
	os << dynamic_cast<const Human&>(aTB);									//Приведение к классу Human и вывод
	os << setw(20) << "Date" << setw(20) << "Sum" << endl;
	for (int i = 0; i < NUM; i++)
	{
		os << '[' << i << "]: ";
		os << setw(15) << aTB.m_Payments[i].PayDate;
		os << setw(20) << aTB.m_Payments[i].Sum;
		os << endl;
	}
	os << setw(20) << "Coutnry" << setw(20) << "Date" << endl;
	for (int i = 0; i < NUM; i++)
	{
		os << '[' << i << "]: ";
		os << setw(15) << aTB.m_Travels[i].Country;
		os << setw(20) << aTB.m_Travels[i].Date;
		os << endl;
	}
	os << "Address: " << endl;
	for (int i = 0; i < aTB.m_NumAddress; i++)
	{
		os << "[" << i+1 << "]: " << aTB.m_Address[i] << endl;
	}
	os << "License number: " << aTB.m_LicenseNum << endl;
	os << "Passport ID: " << aTB.m_PassportID << endl;
	return os;
}
istream& operator >> (istream& is, TourBisn& aTurBis)						//Перегрузка ввода
{
	is >> dynamic_cast<Human&>(aTurBis);									//Приведение к классу Human и ввод
	cout << "Enter license number: ";
	cin >> aTurBis.m_LicenseNum;
	cout << "Enter passport ID: ";
	cin >> aTurBis.m_PassportID;
	cout << "Enter payments: " << endl;
	for (int i = 0; i < NUM; i++)											//Ввод платежей
	{
		char buf[256];
		while (1)
		{
			cout << "Enter date: ";
			is >> buf;
		}
		strcpy(aTurBis.m_Payments[i].PayDate, buf);
		cout << "Enter sum: ";
		cin >> aTurBis.m_Payments[i].Sum;
	}
	cout << "Enter travels" << endl;
	for (int i = 0; i < NUM; i++)											//Ввод путешествий
	{
		char buf[256];
		while (1)
		{
			cout << "Enter date: ";
			is >> buf;
		}
		strcpy(aTurBis.m_Travels[i].Date, buf);
		cout << "Enter country: ";
		cin >> aTurBis.m_Travels[i].Country;
	}
	int i = 1;
	char ss[SIZE];
	do																//Ввод адресов
	{
		char buf[256];
		while (1)
		{
			cout << "Address: ";
			is >> buf;
		}
		aTurBis.AddAddress(buf);
		cout << "One more address?(1/0): ";
		cin >> i;
	} while (i);
	return is;
}