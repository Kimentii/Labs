#include "Queue.h"
#include "Algorithm.h"
#include <random>
template <class it>
void Sort(it first, it last)
{												//��������� �������� �� first �� last(�� ������� last)
	it temp;
	for (it i = first; i != last; i++)			//���� �� ������ �� �����
	{
		temp = i;								//���������� ������� �������
		for (it j = i; j != last; j++)			//���� ������� �������
		{
			if (*temp > *j)
			{
				temp = j;
			}
		}
		if (i != temp)							//������ ���������� ������� � �������
		{
			auto c = *i;
			*i = *temp;
			*temp = c;
		}
	}
}
template <class it>
void Random_Shuffle(it first, it last)
{												//������������ �������� �� first �� last(�� ������� last)
	int i = 0, j = 1;
	it curr;
	for (it temp = first; temp != last; temp++, j++)
	{											//���� �� ������ �� �����
		i = rand() % j;							//����� ��������� ����� ��������
		curr = first;
		while (i-- > 0) curr++;					//���� ���� ��������� �������
		if (curr != temp)						//�������� ������� ������� � ������� � ��������� �������
		{
			auto c = *curr;
			*curr = *temp;
			*temp = c;
		}
	}
}
template <class it>
it min_element(it first, it last)
{												//���������� �������� �� ����������� �������
	it temp = first;
	while (first != last)						//���� �� ������ �� �����
	{
		if (*temp > *first)						//���������� ������� �������
		{
			temp = first;
		}
		first++;
	}
	return temp;								//���������� ���������� �������
}
template <class it>
it max_element(it first, it last)
{												//���������� �������� �� ������������ �������
	it temp = first;
	while (first != last)						//���� �� ������ �� �����
	{
		if (*temp < *first)						//���������� ������� �������
		{
			temp = first;
		}
		first++;
	}
	return temp;								//���������� ���������� �������
}
template <class it, class T>
void Fill(it first, it last, T val)
{												//�������� ��� �������� ��������� �� val
	while (first != last)						//���� �� ������ �� �����
	{
		*first = val;							//������ ��������
		first++;
	}
}
template <class it, class T>
it Find(it first, it last, const T& val)
{												//���������� �������� �� ������� � ��������� val
	while ((first != last) && (*first != val)) first++;
	return first;
}
template <class it, class T>
size_t Count(it first, it last, T val)
{												//������������ ���������� ��������� � ��������� val
	size_t i = 0;
	while (first != last)						//���� �� ������ �� �����
	{
		if (*first == val) i++;					//����������� ������� ���� ������ ������� � ��������� val
		first++;
	}
	return i;
}