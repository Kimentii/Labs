#include "Queue.h"
template <class T>
cQueue<T>::cQueue()
{
	cout << "cQueue constructor: " << typeid(T).name() << endl;
	head = nullptr;
	tail = nullptr;
}
template <class T>
cQueue<T>::cQueue(int size, T d)
{
	for (int i = 0; i < size; i++)
	{
		PushBack(d);
	}
}
template <class T>
cQueue<T>::cQueue(int size)
{
	if (size > 0)
	{
		head = new cQueueUnit;
		tail = head;
		for (int i = 0; i < (size - 1); i++)
		{
			tail->next = new cQueueUnit;
			tail = tail->next;
		}
	}
}
template <class T>
cQueue<T>::~cQueue()
{
	int i = 0;
	while (head)
	{
		cout << "delete element with number: " << ++i << endl;
		cQueueUnit* temp = head;
		head = head->next;
		delete temp;
	}
}
template <class T>
void cQueue<T>::show()
{
	cQueueUnit* temp = head;
	while (temp)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
}
template <class T>
void cQueue<T>::clear()
{
	while (head)
	{
		PopBack();
	}
}
template <class T>
bool cQueue<T>::empty()
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
int cQueue<T>::size()
{
	cQueueUnit* temp = head;
	int i = 0;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return i;
}
template <class T>
void cQueue<T>::PushBack(T u)
{
	if (tail)
	{
		tail->next = new cQueueUnit(u, nullptr, tail);
		tail = tail->next;
	}
	else
	{
		head = new cQueueUnit(u);
		tail = head;
	}
}
template <class T>
void cQueue<T>::PushFront(T u)
{
	if (head)
	{
		head->prev = new cQueueUnit(u, head, nullptr);
		head = head->prev;
	}
	else
	{
		head = new cQueueUnit(u);
		tail = head;
	}
}
template <class T>
T cQueue<T>::PopFront()
{
	if (head)
	{
		T buf;
		buf = head->data;
		cQueueUnit* temp = head;
		head = head->next;
		if (head) head->prev = nullptr;
		else tail = nullptr;
		delete temp;
		return buf;
	}
	else
	{	

	}
}
template <class T>
T cQueue<T>::PopBack()
{
	if (tail)
	{
		T buf;
		buf = tail->data;
		cQueueUnit* temp = tail;
		tail = tail->prev;
		if (tail) tail->next = nullptr;
		else head = nullptr;
		delete temp;
		return buf;
	}
	else
	{

	}
}