#include "TourBisn.h"
TourBisn::TourBisn(const char* n, const char* sn, const char* mn, int y, int na) : Human(n, sn, mn, y)
{																			//�����������
	m_NumAddress = na;
	if (na > 0)																//���� ������� ���������� ��������
	{																		//���������� �������, ��
		m_Address = new char*[na];											//��������� ������ ��� ���
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
TourBisn::TourBisn(const TourBisn& aTurBis)									//����������� �����������
{
	strcpy(m_Name, aTurBis.m_Name);											//����������� ���������� ������
	strcpy(m_SurName, aTurBis.m_SurName);
	strcpy(m_MiddleName, aTurBis.m_MiddleName);
	m_NumAddress = aTurBis.m_NumAddress;
	m_YearOfBirth = aTurBis.m_YearOfBirth;
	for (int i = 0; i < NUM; i++)											//����������� ����������� � �������
	{
		strcpy(m_Travels[i].Country, aTurBis.m_Travels[i].Country);
		strcpy(m_Travels[i].Date, aTurBis.m_Travels[i].Date);
		strcpy(m_Payments[i].PayDate, aTurBis.m_Payments[i].PayDate);
		m_Payments[i].Sum = aTurBis.m_Payments[i].Sum;
	}
	if (aTurBis.m_NumAddress > 0)											//������������� ������������ ������
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
TourBisn::~TourBisn()														//����������
{
	for (int i = 0; i < m_NumAddress; i++)
	{
		delete[] m_Address[i];
	}
	delete[] m_Address;
	m_NumAddress = 0;
	cout << "TourBisn destuctor" << endl;
}
const char** const TourBisn::GetAddress()									//���������� ������ �������
{
	return const_cast<const char** const>(m_Address);
}
int TourBisn::GetNumAddress()
{
	return 	m_NumAddress;
}
void TourBisn::AddAddress(const char* a)									//���������� ������
{
	if (m_NumAddress > 0)													//���� ���������� ������� �����
	{
		for (int i = 0; i < m_NumAddress; i++)								//����� ������ �������
		{
			if (!strlen(m_Address[i]))
			{
				strcpy(m_Address[i], a);
				return;
			}
		}
		char** buf = new char*[m_NumAddress + 1];							//����� ������������� ������� �����
		buf[m_NumAddress] = new char[SIZE];
		for (int i = 0; i < m_NumAddress; i++)
		{
			buf[i] = m_Address[i];
		}
		strcpy(buf[m_NumAddress], a);										//� ���������� ������ ������
		m_NumAddress++;
		delete[] m_Address;
		m_Address = buf;
	}
	else																	//�������� ������ ������
	{
		m_NumAddress = 1;
		m_Address = new char*[1];
		m_Address[0] = new char[SIZE];
		strcpy(m_Address[0], a);
	}
}
bool TourBisn::DelAddress(const char* a)									//�������� ������
{
	bool x = false;
	if (m_NumAddress > 0)													//���� ������ ����������
	{
		for (int i = 0; i < m_NumAddress; i++)								//����� ������� ������
		{
			if (!strcmp(m_Address[i], a))									//��������� ������� ������
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
	strcpy(m_Name, aTurBis.m_Name);											//����������� ���������� ������
	strcpy(m_SurName, aTurBis.m_SurName);
	strcpy(m_MiddleName, aTurBis.m_MiddleName);
	m_NumAddress = aTurBis.m_NumAddress;
	m_YearOfBirth = aTurBis.m_YearOfBirth;
	for (int i = 0; i < NUM; i++)											//����������� ����������� � �������
	{
		strcpy(m_Travels[i].Country, aTurBis.m_Travels[i].Country);
		strcpy(m_Travels[i].Date, aTurBis.m_Travels[i].Date);
		strcpy(m_Payments[i].PayDate, aTurBis.m_Payments[i].PayDate);
		m_Payments[i].Sum = aTurBis.m_Payments[i].Sum;
	}
	if (aTurBis.m_NumAddress > 0)											//������������� ������������ ������
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
ostream& operator << (ostream& os, const TourBisn& aTB)						//���������� ������
{
	os << dynamic_cast<const Human&>(aTB);									//���������� � ������ Human � �����
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
		os << "[" << i + 1 << "]: " << aTB.m_Address[i] << endl;
	}
	return os;
}
istream& operator >> (istream& is, TourBisn& aTurBis)						//���������� �����
{
	is >> dynamic_cast<Human&>(aTurBis);									//���������� � ������ Human � ����
	cout << "Enter payments: " << endl;
	for (int i = 0; i < NUM; i++)											//���� ��������
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
		strcpy(aTurBis.m_Payments[i].PayDate, buf);
		cout << "Enter sum: ";
		aTurBis.m_Payments[i].Sum = InputInt(is);
	}
	cout << "Enter travels" << endl;
	for (int i = 0; i < NUM; i++)											//���� �����������
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
		strcpy(aTurBis.m_Travels[i].Date, buf);
		cout << "Enter country: ";
		InputString(is, aTurBis.m_Travels[i].Country, SIZE);
	}
	int i = 1;
	char ss[SIZE];
	do																//���� �������
	{
		char buf[256];
		while (1)
		{
			cout << "Address: ";
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
		aTurBis.AddAddress(buf);
		cout << "One more address?(1/0): ";
		i = InputInt(is, 0, 1);
	} while (i);
	return is;
}