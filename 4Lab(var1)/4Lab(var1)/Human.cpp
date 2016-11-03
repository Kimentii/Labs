#include "Human.h"
#include "Exception.h"
Human::Human(const char* n, const char* sn, const char* mn, int y) : m_YearOfBirth(y)
{																	//Конструктор
	strcpy(m_Name, n);
	strcpy(m_SurName, sn);
	strcpy(m_MiddleName, mn);
	cout << "Human constructor" << endl;
}
const char* const Human::GetName()									//Возвращение имени
{
	return m_Name;
}
const char* const Human::GetSurName()								//Возвращение фамилии
{
	return m_SurName;
}
const char* const Human::GetMiddleName()							//Возвращение отчества
{
	return m_MiddleName;
}
int Human::GetYear()												//Возвращение года рождения
{
	return m_YearOfBirth;
}
void Human::SetName(const char* n)									//Изменение имени
{
	strcpy(m_Name, n);
}
void Human::SetSurName(const char* sn)								//Изменение фамилии
{
	strcpy(m_SurName, sn);
}
void Human::SetMiddleName(const char* mn)							//Изменение отчества
{
	strcpy(m_MiddleName, mn);
}
void Human::SetYearOfBirth(int y)									//Изменение года рождения
{
	m_YearOfBirth = y;
}
ostream& operator << (ostream& os,const Human& aHum)				//Перегрузка вывода
{
	os << setw(20) << "Name" << setw(20) <<"Surname" << setw(20) << "Middle name" << setw(20) << "Year of birth" << endl;
	os << setw(20) << aHum.m_Name;
	os << setw(20) << aHum.m_SurName;
	os << setw(20) << aHum.m_MiddleName;
	os << setw(20) << aHum.m_YearOfBirth;
	os << endl;
	return os;
}
istream& operator >> (istream& is, Human& aHum)						//Перегрузка ввода
{
	int i;
	while (1)
	{
		cout << "Enter name: ";
		is >> aHum.m_Name;
		for (i = 0; aHum.m_Name[i]; i++)
		{
			try
			{
				if ((aHum.m_Name[i] < 'A') || (aHum.m_Name[i] > 'z') || ((aHum.m_Name[i] > 'Z') && (aHum.m_Name[i] < 'a')))
				{
					throw not_eng();
				}
			}
			catch (not_eng ne)
			{
				cout << "Number of error is " << ne.error() << endl;
				cout << ne.what() << endl;
				break;
			}
		}
		if (i == strlen(aHum.m_Name)) break;
	}
	while (1)
	{
		cout << "Enter surname: ";
		is >> aHum.m_SurName;
		for (i = 0; aHum.m_SurName[i]; i++)
		{
			try
			{
				if ((aHum.m_SurName[i] < 'A') || (aHum.m_SurName[i] > 'z') || ((aHum.m_SurName[i] > 'Z') && (aHum.m_SurName[i] < 'a')))
				{
					throw not_eng();
				}
			}
			catch (not_eng ne)
			{
				cout << "Number of error is " << ne.error() << endl;
				cout << ne.what() << endl;
				break;
			}
		}
		if (i == strlen(aHum.m_SurName)) break;
	}
	while (1)
	{
		cout << "Enter middle name: ";
		is >> aHum.m_MiddleName;
		for (i = 0; aHum.m_MiddleName[i]; i++)
		{
			try
			{
				if ((aHum.m_MiddleName[i] < 'A') || (aHum.m_MiddleName[i] > 'z') || ((aHum.m_MiddleName[i] > 'Z') && (aHum.m_MiddleName[i] < 'a')))
				{
					throw not_eng();
				}
			}
			catch (not_eng ne)
			{
				cout << "Number of error is " << ne.error() << endl;
				cout << ne.what() << endl;
				break;
			}
		}
		if (i == strlen(aHum.m_MiddleName)) break;
	}
	while (1)
	{
		cout << "Enter year of birth: ";
		is >> aHum.m_YearOfBirth;
		try
		{
			if (is.fail())
			{
				throw new not_int();
			}
			if (aHum.m_YearOfBirth > 2020 || aHum.m_YearOfBirth < 1800)
			{
				throw new out_of_size();
			}
		}
		catch (InputExp* exp)
		{
			is.clear();
			while (cin.get() != '\n');
			cout << "Number of error is " << exp->error() << endl;
			cout << exp->what() << endl;
			delete exp;
			continue;
		}
		break;
	}
	return is;
}