#pragma once
#include "Queue.h"
template <class it>
void Sort(it first, it last);					//Сортирует контейнер
template <class it>
void Random_Shuffle(it first, it last);			//Перемешивает контейнер
template <class it>
it min_element(it first, it last);				//Возвращает итератор на min элемент в интервале
template <class it>
it max_element(it first, it last);				//Возвращает итератор на max элемент в интервале
template <class it, class T>
void Fill(it first, it last, const T& val);		//Все значения элементов в интервале заменяет на val
template <class it, class T>
it Find(it first, it last, const T& val);		//Возвращает итератор на элемент с значенеием val
template <class it, class T>
size_t Count(it first, it last, const T& val);	//Подсчитывает количество элементов с значением val