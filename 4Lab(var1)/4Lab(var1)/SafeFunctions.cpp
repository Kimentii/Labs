#pragma once
#include "SafeFunctions.h"
#include "Exception.h"
int InputInt(istream& is, int min, int max)
{
	int num;
	while (1)
	{
		is >> num;										//���������� �����
		try
		{
			if (is.eof() || is.fail() || (is.peek() != '\n'))	//���� � ������ ����� ������ ��� �����
			{
				throw new not_int();					//����� ���������� �� �����
			}
			if (num < min || num > max)					//���� ������� ������� ����� ��� ���������
			{
				throw new out_of_size();				//����� ���������� �������
			}
		}
		catch (InputExp* exp)							//��������� ����������
		{
			bool e = is.eof();
			is.clear();
			if (!e) while (is.get() != '\n');			//�������� ������ ��������
			cout << "Number of error is " << exp->error() << endl;
			cout << exp->what() << endl;
			delete exp;
			continue;
		}
		return num;
	}
}
void StringCheck(const char* s)
{
	int i;
	for (i = 0; s[i]; i++)								//�������� ���� ��������
	{
		if ((s[i] < 'A') || (s[i] > 'z') || ((s[i] > 'Z') && (s[i] < 'a')))
		{												//���� ������ �� ���������� ������
			throw not_eng();							//����� ����������
		}
	}
}
void InputString(istream& is, char* s, int size)
{
	char buf[256];										//�������� �������� ������
	while (1)
	{
		is >> buf;										//���� �������� ������
		try
		{
			if ((strlen(buf) + 1) > size)				//���� ������ �� �����, ��
			{
				throw out_of_size();					//����� ����������
			}
			StringCheck(buf);							//�������� �� ���������� ����
			break;
		}
		catch (InputExp& ne)							//��������� ����������
		{
			cout << "Number of error is " << ne.error() << endl;
			cout << ne.what() << endl;
			continue;									//����������� �����
		}
	}
	strcpy(s, buf);
}