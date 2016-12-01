#include "Businessman.h"
#include "SafeFunctions.h"
Businessman::Businessman(const char* n, const char* sn, const char* mn, int y, int l) : Human(n, sn, mn, y), m_LicenseNum(l)
{																			//�����������
	for (int i = 0; i < NUM; i++)											//��������� �����
	{
		strcpy(m_Payments[i].PayDate, "");
		m_Payments[i].Sum = 0;
	}
	cout << "Businessman constuctor" << endl;
}
int Businessman::GetLicenseNum()											//����������� ������ ��������
{
	return m_LicenseNum;
}
const TaxPayment* const Businessman::GetTaxPayments()						//����������� ������� ��������
{
	return m_Payments;
}
void Businessman::SetLicenseNum(int num)									//��������� ������ ��������
{
	m_LicenseNum = num;
}
bool Businessman::AddPayment(const char* d, int s)							//���������� �������
{
	int i;
	for (i = 0; i < NUM; i++)
	{
		if (m_Payments[i].Sum <= 0) break;									//���� ���� ��������� �����
	}
	if (i < NUM)															//�� ��������� ���� ������
	{
		strcpy(m_Payments[i].PayDate, d);
		m_Payments[i].Sum = s;
		return true;
	}
	else return false;
}
bool Businessman::DelPayment(const char* d)									//�������� �������
{
	int i;
	bool x = false;
	for (i = 0; i < NUM; i++)												//����� �� ����
	{
		if (!strcmp(m_Payments[i].PayDate, d))
		{
			strcpy(m_Payments[i].PayDate, "");								//��������� �������� ������
			m_Payments[i].Sum = 0;
			x = true;
		}
	}
	return x;
}
ostream& operator << (ostream& os, const Businessman& aB)					//���������� ������
{
	os << dynamic_cast<const Human&>(aB);
	os << setw(20) << "Date" << setw(20) << "Sum" << endl;
	for (int i = 0; i < NUM; i++)											//����� ��������
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
istream& operator >> (istream& is, Businessman& aBis)						//���������� �����
{
	is >> dynamic_cast<Human&>(aBis);										//���������� � �������� ������ � ����
	cout << "Enter license number: ";
	aBis.m_LicenseNum = InputInt(is, 0);
	for (int i = 0; i < NUM; i++)											//���� ��������
	{
		char buf[256];
		while (1)
		{
			cout << "Enter date: ";
			is >> buf;														//���� ������
			try
			{
				if ((strlen(buf) + 1) > SIZE)
				{
					throw out_of_size();									//������ ������� ������
				}
				break;
			}
			catch (InputExp& ne)											//��������� ������
			{
				cout << "Number of error is " << ne.error() << endl;		//����� ������ ������
				cout << ne.what() << endl;									//����� ��������
				continue;
			}
		}
		strcpy(aBis.m_Payments[i].PayDate, buf);
		cout << "Enter sum: ";
		aBis.m_Payments[i].Sum = InputInt(is);
	}
	return is;
}