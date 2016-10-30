//Первый вошел первый вышел, шаблонная реализация очереди
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
		cQueueUnit() { next = nullptr; prev = nullptr; }
		cQueueUnit(T u, cQueueUnit* nt = nullptr, cQueueUnit* pr = nullptr) : next(nt), prev(pr), data(u) {}
		cQueueUnit* next;
		cQueueUnit* prev;
	} *head, *tail;
public:
	class Iterator;
	friend class Iterator;
	class Iterator
	{
	public:
		cQueueUnit* ptr;
		Iterator(cQueueUnit* tmp = nullptr) : ptr(tmp) { }
		Iterator operator ++ (int)
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
		Iterator operator -- (int)
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
		Iterator operator ++ () { return (*this)++; };
		Iterator operator -- () { return (*this)--; };
		T& operator * ()
		{
			if (ptr) return ptr->data;
		}
		T& operator -> ()
		{
			if (ptr) return ptr->data;
		}
		bool operator == (const Iterator& i)
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
		bool operator != (const Iterator& i)
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
	cQueue(int size);
	cQueue(int size, const T d);
	~cQueue();
	Iterator begin() { return Iterator(head); }
	Iterator end() { return Iterator(nullptr); }
	Iterator find(const T& inf)
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
	void show();
	void clear();
	void PushBack(T u);
	void PushFront(T u);
	bool empty();
	int size();
	T PopFront();
	T PopBack();
	T& operator [] (int i)
	{
		if (i < size() && i >= 0)
		{
			cQueue::Iterator it = begin();
			while (--i >= 0)
			{
				it++;
			}
			return *it;
		}
	}
	friend ostream& operator << (ostream& os, cQueue& q)
	{
		cQueue::Iterator it = q.begin();
		for (; it != q.end(); it++)
		{
			os << *it << endl;
		}
		return os;
	}
	friend istream& operator >> (istream& is, cQueue& q)
	{
		cQueue::Iterator it = q.begin();
		for (; it != q.end(); it++)
		{
			is >> *it;
		}
		return is;
	}
};