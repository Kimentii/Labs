#include <iostream>
using namespace std;
class cArray
{
	int **m_cArr;												//��������� �� ���������� ������.
	int Rows, Columns;											//���������� ����� � ��������.
public:
	cArray(int r=0, int c=0);									//����������� � ����������� �� ���������
	~cArray();													//����������.
	cArray(cArray& a);											//����������� �����������.
	void Show() const;											//����� �������.
	void vvod();												//������� ����� �������.
	cArray Multi(cArray& b);									//��������� ������.
	cArray operator = (cArray& a);								//���������� ��������� ����������.
	cArray operator *= (cArray& b);								//���������� ��������� *=.
	cArray operator * (cArray& a);								//���������� ��������� ��������.
	bool operator == (const cArray& a);							//���������� ��������� ����������.
	cArray operator ++ ();										//���������� ����������� ++
	cArray operator ++ (int);									//���������� ������������ ++
	friend ostream& operator << (ostream& os,const cArray& a);  //���������� ��������� ������.
	friend istream& operator >> (istream& os,cArray& a);		//���������� ��������� �����.
};