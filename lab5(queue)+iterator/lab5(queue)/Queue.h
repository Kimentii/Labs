//Первый вошел первый вышел, шаблонная реализация очереди
//Нужно дописать итератор
#pragma once
#include <iostream>
using namespace std;
template <class T>
class cQueue
{
	class cQueueUnit
	{
	public:
		T data;
		cQueueUnit() { next = nullptr; }
		cQueueUnit(T u) { data = u; next = nullptr; }
		cQueueUnit* next;
	} *head, *tail;
public:
	class iterator;
	friend class iterator;
	class iterator
	{
	public:
		cQueueUnit* ptr;
		iterator(cQueueUnit* tmp = nullptr) : ptr(tmp) { }
		//iterator operator = (cQueueUnit* u)
		//{
		//	ptr = u;
		//	return iterator(u);
		//}
		iterator operator ++ (int)
		{
			if(ptr) return ptr = ptr->next;
		}
		iterator operator -- (int)
		{
			if (*this != begin() && this->ptr)
			{
				iterator temp = begin();
				while (temp.ptr->next != ptr)
				{
					temp = temp.ptr->next;
				}
				return iterator(temp);
			}
			else
			{
				return iterator(nullptr);
			}
		}
		T operator * ()
		{
			if (ptr) return ptr->data;
		}
		T operator -> ()
		{
			if (ptr) return ptr->data;
		}
		bool operator == (const iterator& i)
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
		bool operator != (const iterator& i)
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
	cQueue();
	//cQueue(int size);						спортный момент(надо прописывать конструктор по умолчанию) и преобразование типов
	cQueue(int size, const T d);
	~cQueue();
	iterator begin() { return iterator(head); }
	iterator end() { return iterator(tail); }
	iterator find(const T& inf)
	{
		iterator it = begin();
		while (it.ptr)
		{
			if (*it == inf)
			{
				return it;
			}
			it++;
		}
		return iterator(nullptr);
	}
	void show();
	void clear();
	void push(T u);
	bool empty();
	int size();
	T pull();
};
