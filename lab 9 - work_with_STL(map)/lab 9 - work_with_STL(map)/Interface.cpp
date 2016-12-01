#include "Human.h"
#include "Businessman.h"
#include "Tourist.h"
#include "TourBisn.h"
#include "Exception.h"
#include <map>
//template <class T>
//void IteratorMenu()
//{
//	int x;
//	cout.setf(ios::left);
//	system("cls");
//	do
//	{
//		cout << "What do you want to do?" << endl;			//Вывод меню работы с итератором
//		cout << "1 - Set iterator to the front" << endl;
//		cout << "2 - Set iterator to the end" << endl;
//		cout << "3 - Show iterator's element" << endl;
//		cout << "4 - iterator++" << endl;
//		cout << "5 - iterator--" << endl;
//		cout << "6 - Show queue from front to end" << endl;
//		cout << "7 - Show queue from end to front" << endl;
//		cout << "8 - Sort queue" << endl;
//		cout << "9 - Shuffle queue" << endl;
//		cout << "10 - Fill queue's elements by element" << endl;
//		cout << "11 - Set iterator to the min element" << endl;
//		cout << "12 - Set iterator to the max element" << endl;
//		cout << "13 - Set iterator to the item found" << endl;
//		cout << "14 - Count number of elements with value" << endl;
//		cout << "15 - Work with element" << endl;
//		cout << "0 - exit" << endl;
//		cout << "Your choice: ";
//		x = InputInt(cin, 0, 15);							//Ввод выбора
//		switch (x)											//Вызов выбранной функции
//		{
//		case 1:												//Установление итератора в начало
//			system("cls");
//			it = cQ.begin();
//			break;
//		case 2:												//Установление итератора в конец
//			system("cls");
//			it = cQ.rbegin();
//			break;
//		case 3:												//Вывод элемента итератора
//			system("cls");
//			try
//			{
//				cout << *it << endl;
//			}
//			catch (wrong_element& we)
//			{
//				cout << "Error number is " << we.error() << endl;
//				cout << we.what() << endl;
//			}
//			break;
//		case 4:												//Инкримент иетратора
//			it++;
//			system("cls");
//			break;
//		case 5:												//Декремент итератора
//			it--;
//			system("cls");
//			break;
//		case 6:												//Вывод с начала до конца
//			system("cls");
//			cout << "Queue:" << endl;
//			for (cQueue<T>::Iterator it2 = cQ.begin(); it2 != cQ.end(); it2++)
//			{
//				cout << *it2 << endl;
//			}
//			break;
//		case 7:												//Вывод с конца до начала
//			system("cls");
//			cout << "Queue:" << endl;
//			for (cQueue<T>::Iterator it2 = cQ.rbegin(); it2 != cQ.rend(); it2--)
//			{
//				cout << *it2 << endl;
//			}
//			break;
//		case 8:												//Сортировка
//			Sort(cQ.begin(), cQ.end());
//			system("cls");
//			break;
//		case 9:												//Перемешивание
//			Random_Shuffle(cQ.begin(), cQ.end());
//			system("cls");
//			break;
//		case 10:											//Заполнение
//			system("cls");
//			Fill(cQ.begin(), cQ.end(), SafeInput<T>());
//			break;
//		case 11:											//Поиск минимального
//			system("cls");
//			it = min_element(cQ.begin(), cQ.end());
//			break;
//		case 12:											//Поиск максимального
//			system("cls");
//			it = max_element(cQ.begin(), cQ.end());
//			break;
//		case 13:											//Поиск элемента
//			system("cls");
//			it = Find(cQ.begin(), cQ.end(), SafeInput<T>());
//			break;
//		case 14:											//Подсчет элементов
//			system("cls");
//			cout << "There are " << Count(cQ.begin(), cQ.end(), SafeInput<T>()) << " elements" << endl;
//			break;
//		case 15:											//Работа элементом(если можно)
//			system("cls");
//			try
//			{
//				StructMenu(*it);
//			}
//			catch (wrong_element e)
//			{
//				cout << "Error is " << e.error() << endl;
//				cout << e.what() << endl;
//			}
//			break;
//		}
//	} while (x);
//}
template <class key, class T>
void menu()
{
	typedef map<key, T> MAP;
	typedef map<key, T>::iterator it;
	MAP aMap;
	char word_key[SIZE];
	if (typeid(T) == typeid(Tourist) || typeid(T) == typeid(TourBisn))
	{
		strcpy(word_key, " passport ID");
	}
	else
	{
		strcpy(word_key, " key");
	}
	T buf_el;
	key buf_key;
	int x;
	cout.setf(ios::left);
	do
	{
		cout << "What do you want to do?" << endl;			//Вывод меню
		cout << "1 - Add element" << endl;
		cout << "2 - Show element with key" << endl;
		cout << "3 - Show map" << endl;
		cout << "4 - Delete from end" << endl;
		cout << "5 - Delete from front" << endl;
		cout << "6 - Clear all" << endl;
		cout << "7 - Show size" << endl;
		cout << "8 - Work with iterator + algorithms" << endl;
		cout << "9 - Show element with number n" << endl;
		cout << "0 - exit" << endl;
		cout << "Your choice: ";
		x = InputInt(cin, 0, 9);							//Ввод выбора
		switch (x)											//Вызов соответствующей функции
		{
		case 1:
			system("cls");
			cin >> buf_el;
			cout << "Enter" << word_key << ": ";
			buf_key = SafeInput<key>();
			aMap.insert(make_pair(buf_key, buf_el));
			break;
		case 2:
			system("cls");
			cout << "Enter" << word_key << ": ";
			buf_key = SafeInput<key>();
			if (aMap.find(buf_key) != aMap.end())
			{
				cout << "Your " << typeid(T).name() << endl;
				cout << (aMap.find(buf_key))->second << endl;
			}
			else
			{
				cout << "Element wasn't found." << endl;
			}
			break;
		case 3:
			system("cls");
			if (!aMap.empty())
			{
				it temp = aMap.begin();
				for (; temp != aMap.end(); temp++)
				{
					cout << setw(50) << typeid(T).name() << setw(50) << word_key << endl;
					cout << temp->second << setw(50) << temp->first << emdl;
				}
			}
			else
			{
				cout << "Map is empty." << endl;
			}
			break;
		case 4:
			system("cls");
			break;
		case 5:
			system("cls");
			break;
		case 6:
			system("cls");
			break;
		case 7:
			system("cls");
			break;
		case 8:
			system("cls");
			break;
		case 9:
			system("cls");
			break;
		}
	} while (x);
}