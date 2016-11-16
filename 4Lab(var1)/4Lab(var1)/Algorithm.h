#pragma once
#include "Queue.h"
template <class it>
void Sort(it first, it last);					//��������� ���������
template <class it>
void Random_Shuffle(it first, it last);			//������������ ���������
template <class it>
it min_element(it first, it last);				//���������� �������� �� min ������� � ���������
template <class it>
it max_element(it first, it last);				//���������� �������� �� max ������� � ���������
template <class it, class T>
void Fill(it first, it last, const T& val);		//��� �������� ��������� � ��������� �������� �� val
template <class it, class T>
it Find(it first, it last, const T& val);		//���������� �������� �� ������� � ���������� val
template <class it, class T>
size_t Count(it first, it last, const T& val);	//������������ ���������� ��������� � ��������� val