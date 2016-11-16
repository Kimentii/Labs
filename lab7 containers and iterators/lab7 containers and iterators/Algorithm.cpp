#include "Queue.h"
#include "Algorithm.h"
#include <random>
template <class it>
void Sort(it first, it last)
{												//Сортирует элементы от first до last(не включая last)
	it temp;
	for (it i = first; i != last; i++)			//Цикд от начала до конца
	{
		temp = i;								//Запоминает текущий элемент
		for (it j = i; j != last; j++)			//Ищет меньший элемент
		{
			if (*temp > *j)
			{
				temp = j;
			}
		}
		if (i != temp)							//Меняет наименьший элемент и текущий
		{
			auto c = *i;
			*i = *temp;
			*temp = c;
		}
	}
}
template <class it>
void Random_Shuffle(it first, it last)
{												//Перемешивает элементы от first до last(не включая last)
	int i = 0, j = 1;
	it curr;
	for (it temp = first; temp != last; temp++, j++)
	{											//Цикл от начала до конца
		i = rand() % j;							//Берет рандомный номер элемента
		curr = first;
		while (i-- > 0) curr++;					//Ищет этот рандомный элемент
		if (curr != temp)						//Заменяет текущий элемент и элемнет с рандомным номером
		{
			auto c = *curr;
			*curr = *temp;
			*temp = c;
		}
	}
}
template <class it>
it min_element(it first, it last)
{												//Возвращает итератор на минимальный элемент
	it temp = first;
	while (first != last)						//Цикл от начала до конца
	{
		if (*temp > *first)						//Запоминает меньший элемент
		{
			temp = first;
		}
		first++;
	}
	return temp;								//Возвращает наименьший элемент
}
template <class it>
it max_element(it first, it last)
{												//Возвращает итератор на максимальный элемент
	it temp = first;
	while (first != last)						//Цикл от начала до конца
	{
		if (*temp < *first)						//Запоминает больший элемент
		{
			temp = first;
		}
		first++;
	}
	return temp;								//Возвращает наибольший элемент
}
template <class it, class T>
void Fill(it first, it last, T val)
{												//Заменяет все значения элементов на val
	while (first != last)						//Цикл от начала до конца
	{
		*first = val;							//Замена значения
		first++;
	}
}
template <class it, class T>
it Find(it first, it last, const T& val)
{												//Возвращает итератор на элемент с значением val
	while ((first != last) && (*first != val)) first++;
	return first;
}
template <class it, class T>
size_t Count(it first, it last, T val)
{												//Подсчитывает количество элементов с значением val
	size_t i = 0;
	while (first != last)						//Цикл от начала до конца
	{
		if (*first == val) i++;					//Увеличивает счетчик если найден элемент с значением val
		first++;
	}
	return i;
}