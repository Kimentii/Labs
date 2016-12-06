#include "Array.h"
#include <iomanip>
using namespace std;
cArray::cArray(int r,int c):Rows(r),Columns(c)					//����������� � ����������� �� ���������.
{
	if ((r>0)&&(c>0))
	{
		m_cArr = new int*[r];									//��������� ������ ��� �������.
		if (!m_cArr)return;										//���� �� ������� ��������, �� ��������� ���.
		for (int i = 0; i < r; i++)								//��������� ������ ��� ������.
		{
			m_cArr[i] = new int[c];
			if (!m_cArr[i])
			{
				for (--i; i >= 0; i--)
					delete[] m_cArr[i];
				delete[] m_cArr;
				return ;
			}
		}
		//cout << "Array was made." << endl;
	}
}
cArray::~cArray()												//���������.
{
	if (m_cArr && Columns > 0 && Rows > 0)								//���� ������ �� ����, ��
	{
		for (int j = 0; j < Rows; j++)
			delete[] m_cArr[j];									//������ �� ������.
		delete[] m_cArr;										//�������� ������� ����������.
		m_cArr = nullptr;										//��������� ���������.
	}
	//cout << "Destructor" << endl;
}
cArray::cArray(cArray& a)										//����������� �����������.
{
	this->m_cArr = new int*[a.Rows];							//��������� ������ ��� ����� ������.
	for (int i = 0; i < a.Rows; i++)
		this->m_cArr[i] = new int[a.Columns];
	this->Columns = a.Columns;									//������������ �������� �������.
	this->Rows = a.Rows;
	for (int i = 0; i < this->Rows; i++)						//����������� �������.
		for (int j = 0; j < this->Columns; j++)
			this->m_cArr[i][j] = a.m_cArr[i][j];
	//cout << "Copy constructor." << endl;
}
void cArray::Show() const										//������� ������ �������.
{
	
	if ((Rows > 0) && (Columns >0))									//���� ������� ����������.
	{
		for (int i = 0; i < Rows; i++)							//���� �� �������.
		{
			for (int j = 0; j < Columns; j++)					//���� �� ��������.
			{
				cout << setw(3) << m_cArr[i][j];				//����� ��������.
			}
			cout << endl;
		}
	}
	//else cout << "Array is empty.\n";
}
void cArray::vvod()
{
	if (this->Columns > 0 && this->Rows > 0&&m_cArr)
	{
		for (int i = 0; i < Rows; i++)										//������ �� �������.
		{
			for (int j = 0; j < Columns; j++)								//������ �� ��������.
			{
				cin >> m_cArr[i][j];										//���� �������.
			}
		}
	}
}
cArray cArray::Multi(cArray& b)									//������������ ������.
{
	return (*this) *= b;
}
cArray cArray::operator = (cArray& a)
{
	if (this != &a)
	{
		this->~cArray();											//����� �����������.
		this->m_cArr = new int*[a.Rows];							//��������� ������ ��� ����� ������.
		for (int i = 0; i < a.Rows; i++)
			this->m_cArr[i] = new int[a.Columns];
		this->Columns = a.Columns;									//������������ �������� �������.
		this->Rows = a.Rows;
		for (int i = 0; i < this->Rows; i++)						//����������� �������.
			for (int j = 0; j < this->Columns; j++)
				this->m_cArr[i][j] = a.m_cArr[i][j];
		return *this;
	}
	else return *this;
}
ostream& operator << (ostream& os,const cArray& a)
{
	if ((a.Rows>0)&&(a.Columns>0))								//���� ������� ����������.
	{
		for (int i = 0; i < a.Rows; i++)						//���� �� �������.
		{
			for (int j = 0; j < a.Columns; j++)					//���� �� ��������.
			{
				os << setw(3) << a.m_cArr[i][j];				//����� ��������.
			}
			os << endl;
		}
	}
	return os;
}
cArray cArray::operator * (cArray& a)
{
	if ((this->Columns == a.Rows) && this->Columns&&this->Rows&&a.Columns&&a.Rows)//���� ������� ����� �����������, ��
	{
		int x;
		cArray c(this->Rows, a.Columns);							//�������� ����� ������� � ����������� ���������.
		for (int i = 0; i<this->Rows; i++)							//������ �� ������� ������ �������.
			for (int j = 0; j < a.Columns; j++)						//������ �� �������� ������ �������.
			{
				x = 0;
				for (int k = 0; k < a.Rows; k++)
					x += (this->m_cArr[i][k] * a.m_cArr[k][j]);		//������� ������ ��������.
				c.m_cArr[i][j] = x;
			}
		return c;
	}
	else
	{
		return *this;												//������� ������ �����������, ����������� ���������
	}																//�������.
}
bool cArray::operator == (const cArray& a)
{
	if (this->Columns == a.Columns&&this->Rows == a.Rows)					//���� ������� ������� �����,��
	{
		for(int i=0;i<a.Rows;i++)											//�������� ��������� �������.
			for (int j = 0; j < a.Columns; j++)
			{
				if (this->m_cArr[i][j] != a.m_cArr[i][j])return false;		//���� ����� �� ������� �� ���������, ��
			}																//������� false.
		return true;
	}
	else
		return false;														//�������� false.
}
cArray cArray::operator *= (cArray& b)
{
	return (*this) = (*this)*b;												//������������ ������.
}
istream& operator >> (istream& os,cArray& a)
{
	if (a.Columns > 0 && a.Rows > 0 && a.m_cArr)							//���� ������ ����������.
	{
		int n;
		for (int i = 0; i < a.Rows; i++)									//������ �� �������.
		{
			for (int j = 0; j < a.Columns; j++)								//������ �� ��������.
			{
				os >> a.m_cArr[i][j];										//���������� ��������.
			}
		}
	}
	return os;
}
cArray cArray::operator ++ ()
{
	if ((this->Columns > 0) && (this->Rows > 0)&&m_cArr)		//���� ������ ����.
	{
		for (int i = 0; i < this->Rows; i++)					//���������� �� ������� � �������� �
			for (int j = 0; j < this->Columns; j++)
				this->m_cArr[i][j]++;							//���������� ������ ������� �� 1.
	}
	return (*this);
}
cArray cArray::operator ++ (int)
{
	return ++(*this);
}