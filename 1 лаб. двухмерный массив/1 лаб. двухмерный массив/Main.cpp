#include "Array.h"
using namespace std;
void *operator new(size_t tip, int n, int r, int c)
{
	void *p = new char[n*tip];					//�������� ������ ���������
	for (int i = 0; i < n; i++)					//�������� �� ���� � �������� ����� �����������.
		((cArray*)p)[i].cArray::cArray();
	return p;
}
int main()
{
	int r, c;
	cout << "Enter number of rows:";
	cin >> r;
	cout << "Enter number of columns:";
	cin >> c;
	cArray A(r, c);												//����� ������������ � �����������.
	cout << "Enter array A:";
	cin >> A;													//���������� ���������� �����.
	cArray B = A,C;												//����� ������. ����������� � ������. � ���. �� �����.
	C = B;														//���������� ��������� =.
	cout << "Array A:" << endl << A;							//���������� ��������� ������.
	cout << "Array B:" << endl;
	B.Show();													//������� ������ �������.
	cout << "Array C" << endl << C;
	C++;														//����� ���������� ������������ ����������.
	cout << "Array C after ++(int) and ++:" <<endl<< ++C;		//���������� ����������� ����������.
	cout << "Now enter array C:" << endl;
	C.vvod();													//������� ������.
	cout << "Is C == A? ";
	if (C == A)													//���������� ��������� ==
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	cout << "Now C*=A:" << endl;
	C *= A *= A *= A;														//���������� ��������� *=
	cout<<C<< endl;
	B = A*A;													//���������� ��������� *.
	cout << "Now B = A * A:" << endl<<B << endl;
	B.Multi(A);													//������� ������������ ������.
	cout << "Now B.Multi(A):" <<endl<< B << endl;
	system("pause");
	return 0;
}