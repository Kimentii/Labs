//������ ����� ������ �����, ��������� ���������� �������
#pragma once
#include "Exception.h"
#include <iostream>
using namespace std;
template <class T>
class cQueueUnit														//������� �������
{
public:
	T data;																//������
	cQueueUnit(cQueueUnit* nt = nullptr, cQueueUnit* pr = nullptr) : next(nt), prev(pr) { }	//����������� �� ��������� � 2 �����������
	cQueueUnit(T u, cQueueUnit* nt = nullptr, cQueueUnit* pr = nullptr) : next(nt), prev(pr), data(u) {}	//����������� � �����������
	cQueueUnit<T>* next;												//��������� �� ��������� �������
	cQueueUnit<T>* prev;												//��������� �� ���������� �������
};
template <class T>
class cQueue
{
	cQueueUnit<T> *head, *tail;											//������ � ������ �������
public:
	class Iterator;
	friend class Iterator;
	class Iterator														//����� ��������
	{
		cQueueUnit<T>* ptr;
	public:
		//��������� �� ������� �������
		Iterator(cQueueUnit<T>* tmp = nullptr) : ptr(tmp) { }			//����������� � ����� ����������
		Iterator operator ++ (int)										//����������� �� ��������� �������
		{
			if (ptr)
			{
				ptr = ptr->next;
				return Iterator(ptr);
			}
			else
			{
				return Iterator(ptr);
			}
		}
		Iterator operator -- (int)										//����������� �� ���������� �������
		{
			if (ptr)
			{
				ptr = ptr->prev;
				return Iterator(ptr);
			}
			else
			{
				return Iterator(ptr);
			}
		}
		Iterator operator ++ () { return (*this)++; };					//����������� �� ��������� �������
		Iterator operator -- () { return (*this)--; };					//����������� �� ���������� �������
		T& operator * ()												//���������� ��������� *
		{
			if (ptr) return ptr->data;									//����������� ������ �� ������
			else throw wrong_element();
		}
		T& operator -> ()												//���������� ��������� ->
		{
			if (ptr) return ptr->data;									//����������� ������ �� ������
			else throw wrong_element();
		}
		bool operator == (const Iterator& i)							//���������� ��������� ==
		{
			if (ptr == i.ptr)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		bool operator != (const Iterator& i)							//���������� ��������� !=
		{
			if (ptr == i.ptr)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	};
	cQueue();															//����������� �� ���������
	cQueue(int size);													//����������� � ���������� ������� �������
	cQueue(int size, const T d);										//����������� � ����� �����������
	~cQueue();															//����������
	Iterator begin() { return Iterator(head); }							//���������� �������� �� ������ �������
	Iterator end() { return Iterator(nullptr); }						//���������� �������� �� ����� �������
	Iterator rbegin() { return Iterator(tail); }
	Iterator rend() { return Iterator(nullptr); }
	Iterator find(const T& inf)											//����� �������� �������
	{
		Iterator it = begin();
		while (it.ptr)
		{
			if (*it == inf)
			{
				return it;
			}
			it++;
		}
		return Iterator(nullptr);
	}
	void show();														//������� ������ �������
	void clear();														//������� ������� �������
	void del_element(Iterator& it)
	{
		if (it == Iterator(nullptr)) throw wrong_element();
		if (it == begin())
		{
			it++;
			PopFront();
		}
		else if (it == rbegin())
		{
			it++;
			PopBack();
		}
		else
		{
			cQueueUnit<T>* temp = it.ptr;
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			it++;
			delete temp;

		}
	}
	void PushBack(const T& u);											//���������� �������� � ����� �������
	void PushFront(const T& u);											//���������� �������� � ������ �������
	bool empty();														//�������� ������� �� �������
	int size();															//����������� ������� �������
	T PopFront();														//�������� �������� �� ������ �������
	T PopBack();														//�������� �������� �� ����� �������
	T& operator [] (int i)												//���������� ��������� []
	{
		if (i <= size() && i > 0)
		{
			cQueue::Iterator it = begin();								//�������� ��������� �� ������
			while (--i > 0)												//����� ������� ��������
			{
				it++;
			}
			return *it;
		}
		else
		{
			throw wrong_element();
		}
	}
	friend ostream& operator << (ostream& os, cQueue& q)				//���������� ������
	{
		cQueueUnit<T>* temp = q.head;
		while (temp)
		{
			os << temp->data << endl;									//��������� ����� ���������
			temp = temp->next;
		}
		if (q.empty())
		{
			os << "Queue is empty" << endl;
		}
		return os;
	}
	friend istream& operator >> (istream& is, cQueue& q)				//���������� �����
	{
		cQueue::Iterator it = q.begin();
		for (; it != q.end();)
		{
			try
			{
				is >> *it;
				if (is.fail() || is.eof())								//���� � ������ ����� ������
				{
					throw InputExp();									//�� ����� ����������
				}
				it++;
			}
			catch (InputExp& exp)										//��������� ����������
			{
				bool e = is.eof();
				is.clear();
				if (!e) while (is.get() != '\n');						//�������� ������ ��������
				while (is.get() != '\n');
				cout << "Error:" << exp.error() << endl;
				cout << exp.what() << endl;
			}
		}
		return is;
	}
	friend fstream& operator << (fstream& os, const cQueue& q)			//���������� ������
	{
		cQueueUnit<T>* temp = q.head;
		while (temp)
		{
			os << temp->data << ' ';									//��������� ����� ���������
			temp = temp->next;
		}
		return os;
	}
	friend fstream& operator >> (fstream& is, cQueue& q)				//���������� �����
	{
		T buf;
		while (1)
		{
			is >> buf;
			if (is.eof() || is.fail())
			{
				break;
			}
			q.PushBack(buf);
		}
		return is;
	}
};