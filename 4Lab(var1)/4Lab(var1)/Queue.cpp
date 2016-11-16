#pragma once
#include "Queue.h"
template <class T>
cQueue<T>::cQueue()													//����������� �� ���������
{
	cout << "cQueue constructor: " << typeid(T).name() << endl;		//������� ��� �������� ������ � �������
	head = nullptr;
	tail = nullptr;
}
template <class T>
cQueue<T>::cQueue(int size, T d)									//����������� � ����� �����������
{
	cout << "cQueue constructor: " << typeid(T).name() << endl;		//������� ��� �������� ������ � �������
	for (int i = 0; i < size; i++)									//������� ������ ���������� ���������
	{																//� �������������� ��
		PushBack(d);
	}
}
template <class T>
cQueue<T>::cQueue(int size)											//���������� � ��������� ������� �������
{
	cout << "cQueue constructor: " << typeid(T).name() << endl;		//������� ��� �������� ������ � �������
	if (size > 0)
	{
		head = new cQueueUnit<T>;									//������������� ������ �������
		tail = head;
		for (int i = 0; i < (size - 1); i++)						//���������� ��������� � �����
		{
			tail->next = new cQueueUnit<T>(nullptr, tail);
			tail = tail->next;
		}
	}
}
template <class T>
cQueue<T>::~cQueue()												//����������
{
	int i = 0;
	while (head)
	{
		cout << "delete element with number: " << ++i << endl;		//������� ���������� ��������� ���������
		cQueueUnit<T>* temp = head;
		head = head->next;
		delete temp;
	}
}
template <class T>
void cQueue<T>::show()												//����� �������
{
	cQueueUnit* temp = head;
	while (temp)													//���� �� ����� �������
	{
		cout << temp->data << endl;									//����� ������ �� ���
		temp = temp->next;
	}
}
template <class T>
void cQueue<T>::clear()												//�������� �������
{
	while (head)
	{
		PopBack();													//������� �������� �� ����� ������� ����
	}																//������� �� ��������
}
template <class T>
bool cQueue<T>::empty()												//�������� ������� ���������
{
	if (head)
	{
		return false;
	}
	else
	{
		return true;
	}
}
template <class T>
int cQueue<T>::size()												//���������� ������ �������
{
	cQueueUnit<T>* temp = head;
	int i = 0;
	while (temp)													//�������� �� ����� ������� � ������� ��� ��������
	{
		i++;
		temp = temp->next;
	}
	return i;
}
template <class T>
void cQueue<T>::PushBack(const T& u)								//���������� �������� � ����� �������
{
	if (tail)														//���� ������� ��� �������� ��������
	{
		tail->next = new cQueueUnit<T>(u, nullptr, tail);			//�� ��������� ��� ����
		tail = tail->next;
	}
	else
	{
		head = new cQueueUnit<T>(u);								//����� �������������� �������
		tail = head;
	}
}
template <class T>
void cQueue<T>::PushFront(const T& u)								//���������� �������� � ������ �������
{
	if (head)														//���� ������� ����
	{
		head->prev = new cQueueUnit<T>(u, head, nullptr);			//��������� ������� � ������
		head = head->prev;
	}
	else
	{
		head = new cQueueUnit<T>(u);								//����� ������� ������ ������� �������
		tail = head;
	}
}
template <class T>
T cQueue<T>::PopFront()												//�������� �������� �� ������ �������
{
	if (head)														//���� ������� �������� ��������
	{
		T buf = head->data;											//������������ ������ �� ��������
		cQueueUnit<T>* temp = head;
		head = head->next;											//��������� ������ �������
		if (head) head->prev = nullptr;
		else tail = nullptr;
		delete temp;												//������� �������
		return buf;
	}
	else
	{
		throw QueueExp();
	}
}
template <class T>
T cQueue<T>::PopBack()												//�������� �������� �� ����� �������
{
	if (tail)														//���� ������� �������� ��������
	{
		T buf = tail->data;											//���������� ������ �� ��������
		cQueueUnit<T>* temp = tail;
		tail = tail->prev;											//������� ����� �������
		if (tail) tail->next = nullptr;
		else head = nullptr;
		delete temp;												//�������� ��������
		return buf;
	}
	else
	{
		throw QueueExp();
	}
}