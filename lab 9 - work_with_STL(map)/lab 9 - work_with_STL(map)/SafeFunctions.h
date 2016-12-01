#pragma once
#include "Exception.h"
int InputInt(istream& is = cin, int min = 0, int max = 2147483647);	//������� ����� int
void StringCheck(const char* s);									//�������� �� ���������� ����
void InputString(istream& is, char* s, int size);					//���� ������
template <class T>
T SafeInput()														//���� int, double, char
{
	T el;															//������� �������
	while (true)
	{
		try
		{
			//cout << "Enter your " << typeid(T).name() << ": ";		//����� ������� ������ �������
			cin >> el;
			if (cin.eof())
			{
				throw InputExp(1, "End of file");
			}
			if (cin.fail() || (cin.peek() != '\n'))					//���� ������ ������ �����
			{
				throw InputExp(1, "Please, enter number.");			//����� ���������� �����
			}
			return el;
		}
		catch (InputExp exp)										//��������� ����������
		{
			bool e = cin.eof();
			cin.clear();											//������� ������ ������ �����
			if (!e) while (cin.get() != '\n');						//������� ������ ��������
			cout << "Error number is " << exp.error() << endl;		//����� ������
			cout << exp.what() << endl;								//����� �������� ������
		}
	}
}																	//���������� ���� int, double, char