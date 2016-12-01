//Первый вошел первый вышел, шаблонная реализация очереди
#pragma once
#include "Exception.h"
#include <iostream>
using namespace std;
template <class T>
class cQueueUnit														//Элемент очереди
{
public:
	T data;																//Данные
	cQueueUnit(cQueueUnit* nt = nullptr, cQueueUnit* pr = nullptr) : next(nt), prev(pr) { }	//Конструктор по умолчанию с 2 параметрами
	cQueueUnit(T u, cQueueUnit* nt = nullptr, cQueueUnit* pr = nullptr) : next(nt), prev(pr), data(u) {}	//Конструктор с параметрами
	cQueueUnit<T>* next;												//Указатель на следующий элемент
	cQueueUnit<T>* prev;												//Указатель на предыдущий элемент
};
template <class T>
class cQueue
{
	cQueueUnit<T> *head, *tail;											//Начало и конечц очереди
public:
	class Iterator;
	friend class Iterator;
	class Iterator														//Класс итератор
	{
		cQueueUnit<T>* ptr;
	public:
		//Указатель на элемент очереди
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
			else throw wrong_element();
		}
		T& operator -> ()												//Перегрузка оператора ->
		{
			if (ptr) return ptr->data;									//Возвращение ссылки на данные
			else throw wrong_element();
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
	void PushBack(const T& u);											//Добавление элемнета в конец очереди
	void PushFront(const T& u);											//Добавление элемента в начало очереди
	bool empty();														//Проверка пусткая ли очередь
	int size();															//Возвращение размера очереди
	T PopFront();														//Удаление элемента из начала очереди
	T PopBack();														//Удаление элемента из конца очереди
	T& operator [] (int i)												//Перегрузка оператора []
	{
		if (i <= size() && i > 0)
		{
			cQueue::Iterator it = begin();								//Создание итератора на начало
			while (--i > 0)												//Поиск нужного элемента
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
	friend ostream& operator << (ostream& os, cQueue& q)				//Перегрузка вывода
	{
		cQueueUnit<T>* temp = q.head;
		while (temp)
		{
			os << temp->data << endl;									//Почленный вывод элементов
			temp = temp->next;
		}
		if (q.empty())
		{
			os << "Queue is empty" << endl;
		}
		return os;
	}
	friend istream& operator >> (istream& is, cQueue& q)				//Перегрузка ввода
	{
		cQueue::Iterator it = q.begin();
		for (; it != q.end();)
		{
			try
			{
				is >> *it;
				if (is.fail() || is.eof())								//Если в потоке ввода ошибка
				{
					throw InputExp();									//то вызов исключения
				}
				it++;
			}
			catch (InputExp& exp)										//Обработка исключения
			{
				bool e = is.eof();
				is.clear();
				if (!e) while (is.get() != '\n');						//Удаление лишних символов
				while (is.get() != '\n');
				cout << "Error:" << exp.error() << endl;
				cout << exp.what() << endl;
			}
		}
		return is;
	}
	friend fstream& operator << (fstream& os, const cQueue& q)			//Перегрузка вывода
	{
		cQueueUnit<T>* temp = q.head;
		while (temp)
		{
			os << temp->data << ' ';									//Почленный вывод элементов
			temp = temp->next;
		}
		return os;
	}
	friend fstream& operator >> (fstream& is, cQueue& q)				//Перегрузка ввода
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