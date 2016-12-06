//Первый вошел первый вышел, шаблонная реализация очереди
#pragma once
#include <iostream>
using namespace std;
template <class T>
class cQueueUnit														//Элемент очереди
{
public:
	T data;																//Данные
	cQueueUnit(cQueueUnit* nt = nullptr, cQueueUnit* pr = nullptr) : next(nt), prev(pr) { }	//Конструктор по умолчанию с 2 параметрами
	cQueueUnit(T u, cQueueUnit* nt = nullptr, cQueueUnit* pr = nullptr) : next(nt), prev(pr), data(u) {}	//Конструктор с параметрами
	cQueueUnit* next;													//Указатель на следующий элемент
	cQueueUnit* prev;													//Указатель на предыдущий элемент
};
template <class T>
class cQueue
{
	 cQueueUnit<T> *head, *tail;										//Начало и конечц очереди
public:
	class Iterator;
	friend class Iterator;
	class Iterator														//Класс итератор
	{
	public:
		cQueueUnit<T>* ptr;												//Указатель на элемент очереди
		Iterator(cQueueUnit<T>* tmp = nullptr) : ptr(tmp) { }			//Конструктор с одним параметром
		Iterator operator ++ (int)										//Перемещение на сделующий элемент
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
		Iterator operator -- (int)										//Перемещение на предыдущий элемент
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
		Iterator operator ++ () { return (*this)++; };					//Перемещение на следующий элемент
		Iterator operator -- () { return (*this)--; };					//Перемещение на пердыдущий элемент
		T& operator * ()												//Перегрузка оператора *
		{
			if (ptr) return ptr->data;									//Возвращение ссылки на данные
		}
		T& operator -> ()												//Перегрузка оператора ->
		{
			if (ptr) return ptr->data;									//Возвращение ссылки на данные
		}
		bool operator == (const Iterator& i)							//Перегрузка оператора ==
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
		bool operator != (const Iterator& i)							//Перегрузка оператора !=
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
	cQueue();															//Конструктор по умолчанию
	cQueue(int size);													//Конструктор с параметром размера очереди
	cQueue(int size, const T d);										//Конструктор с двумя параметрами
	~cQueue();															//Деструктор
	Iterator begin() { return Iterator(head); }							//Возвращает итератор на начало очереди
	Iterator end() { return Iterator(nullptr); }						//Возвращает итератор на конец очереди
	Iterator rbegin() { return Iterator(tail); }
	Iterator rend() { return Iterator(nullptr); }
	Iterator find(const T& inf)											//Поиск элемента очереди
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
	void show();														//Функция вывода очереди
	void clear();														//Функция очистки очереди
	void PushBack(T u);													//Добавление элемнета в конец очереди
	void PushFront(T u);												//Добавление элемента в начало очереди
	bool empty();														//Проверка пусткая ли очередь
	int size();															//Возвращение размера очереди
	T PopFront();														//Удаление элемента из начала очереди
	T PopBack();														//Удаление элемента из конца очереди
	T& operator [] (int i)												//Перегрузка оператора []
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
	friend ostream& operator << (ostream& os, cQueue& q)				//Перегрузка вывода
	{
		cQueue::Iterator it = q.begin();
		for (; it != q.end(); it++)
		{
			os << *it << endl;
		}
		return os;
	}
	friend istream& operator >> (istream& is, cQueue& q)				//Перегрузка ввода
	{
		cQueue::Iterator it = q.begin();
		for (; it != q.end(); it++)
		{
			is >> *it;
		}
		return is;
	}
};