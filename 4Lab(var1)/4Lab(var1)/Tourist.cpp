#include "Tourist.h"
Tourist::Tourist(const char* n, const char* sn, const char* mn, int y, int p) : Human(n, sn, mn, y), m_PassportID(p)
{																			//�����������
	for (int i = 0; i < NUM; i++)
	{
		strcpy(m_Travels[i].Date, "");
		strcpy(m_Travels[i].Country, "");
	}
	cout << "Tourist constructor" << endl;
}
int Tourist::GetPassportID()												//����������� ������ ��������
{
	return m_PassportID;
}
const Travel* const Tourist::GetTravels()									//����������� ������� ��������
{
	return m_Travels;
}
void Tourist::SetPassportID(int p)											//��������� ������ ���������
{
	m_PassportID = p;
}
bool Tourist::AddTravel(const char* c, const char* d)						//���������� �����������
{
	int i;
	for (i = 0; i < NUM; i++)												//����� ������� ���������
	{
		if (!strlen(m_Travels[i].Date)) break;
	}
	if (i < NUM)															//���� ����� �� ����������
	{
		strcpy(m_Travels[i].Date, d);
		strcpy(m_Travels[i].Country, c);
		return true;
	}
	else return false;														//����� �� ���������� ��������
}
bool Tourist::DelTravel(const char* c, const char* d)						//�������� �����������
{
	bool x = false;
	int i;
	if (strlen(c) && strlen(d))												//���� ������� ��� ������
	{
		for (i = 0; i < NUM; i++)											//�� �������� ������ �����������
		{
			if (!strcmp(m_Travels[i].Country, c) && !strcmp(m_Travels[i].Date, d))
			{
				strcpy(m_Travels[i].Country, "");
				strcpy(m_Travels[i].Date, "");
				x = true;
			}
		}
	}
	else
	{
		if (strlen(c))														//���� ������� ������ ������
		{
			for (i = 0; i < NUM; i++)										//�������� ���� ����������� � ������ �������
			{
				if (!strcmp(m_Travels[i].Country, c))
				{
					strcpy(m_Travels[i].Country, "");
					strcpy(m_Travels[i].Date, "");
					x = true;
				}
			}
		}
		else
		{
			for (i = 0; i < NUM; i++)										//�������� �� ����
			{
				if (!strcmp(m_Travels[i].Date, d))
				{
					strcpy(m_Travels[i].Country, "");
					strcpy(m_Travels[i].Date, "");
					x = true;
				}
			}
		}
	}
	return x;
}
ostream& operator << (ostream& os, const Tourist& aT)						//���������� ������
{
	os << dynamic_cast<const Human&>(aT);
	os << setw(20) << "Country" << setw(20) << "Date" << endl;
	for (int i = 0; i < NUM; i++)
	{
		os << '[' << i << "]: ";
		os << setw(15) << aT.m_Travels[i].Country;
		os << setw(20) << aT.m_Travels[i].Date;
		os << endl;
	}
	os << "Passport ID: ";
	os << aT.m_PassportID << endl;
	return os;
}
istream& operator >> (istream& is, Tourist& aTur)							//���������� �����
{
	is >> dynamic_cast<Human&>(aTur);
	cout << "Enter passport ID: ";
	aTur.m_PassportID = InputInt(is);
	cout << "Enter travels: " << endl;
	for (int i = 0; i < NUM; i++)
	{
		char buf[256];
		while (1)
		{
			cout << "Enter date: ";
			is >> buf;
			try
			{
				if ((strlen(buf) + 1) > SIZE)
				{
					throw out_of_size();
				}
				break;
			}
			catch (InputExp& ne)
			{
				cout << "Number of error is " << ne.error() << endl;
				cout << ne.what() << endl;
				continue;
			}
		}
		strcpy(aTur.m_Travels[i].Date, buf);
		cout << "Enter country: ";
		InputString(is, aTur.m_Travels[i].Country, SIZE);
	}
	return is;
}