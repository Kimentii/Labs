#include "Queue.h"
template <class T>
cQueue<T>::cQueue()
{
	cout << "cQueue constructor: " << typeid(T).name() << endl;
	head = nullptr;
	tail = nullptr;
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
//template <class T>
//cQueue<T>::cQueue(int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		push(0);
//	}
//}
template <class T>
cQueue<T>::cQueue(int size, T d)
{
	for (int i = 0; i < size; i++)
	{
		push(d);
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
		pull();
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
void cQueue<T>::push(T u)
{
	cQueueUnit* temp = head;
	if (tail)
	{
		tail->next = new cQueueUnit(u);
		tail = tail->next;
	}
	else
	{
		head = new cQueueUnit(u);
		tail = head;
	}
}
template <class T>
T cQueue<T>::pull()
{
	if (head)
	{
		T buf;
		buf = head->data;
		cQueueUnit* temp = head;
		head = head->next;
		if (!head) tail = nullptr;
		delete temp;
		return buf;
	}
	else
	{	

	}
}