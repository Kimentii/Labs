#include "Human.h"
#include "Businessman.h"
#include "Tourist.h"
#include "Queue.cpp"
#include "Exception.h"
#include "BinaryFile.cpp"
#include "TextFile.cpp"
#include "WorkWithFiles.cpp"
#include <map>
#include <algorithm>
template <class T>
void menu()
{
	cQueue<T> cQ;											//Создание очереди
	T element;
	int x;
	cout.setf(ios::left);
	do
	{
		cout << "What do you want to do?" << endl;			//Вывод меню
		cout << "1 - Add element in front" << endl;
		cout << "2 - Add element in end" << endl;
		cout << "3 - Show queue" << endl;
		cout << "4 - Delete from end" << endl;
		cout << "5 - Delete from front" << endl;
		cout << "6 - Clear all" << endl;
		cout << "7 - Show size" << endl;
		cout << "8 - Work with binary file" << endl;
		cout << "9 - Work with text file" << endl;
		cout << "10 - Work with map" << endl;
		cout << "0 - exit" << endl;
		cout << "Your choice: ";
		x = InputInt(cin, 0, 10);							//Ввод выбора
		switch (x)											//Вызов соответствующей функции
		{
		case 1:												//Добавление в начало
			system("cls");
			cQ.PushFront(SafeInput<T>());
			break;
		case 2:												//Добавление в конец
			system("cls");
			cQ.PushBack(SafeInput<T>());
			break;
		case 3:												//Вывод на экран
			system("cls");
			cout << cQ;
			break;
		case 4:
			try
			{
				cQ.PopBack();
			}
			catch (QueueExp qe)
			{
				cout << "Error number is " << qe.error() << endl;
				cout << qe.what() << endl;
				system("pause");
			}
			system("cls");
			break;
		case 5:
			try
			{
				cQ.PopFront();
			}
			catch (QueueExp qe)
			{
				cout << "Error number is " << qe.error() << endl;
				cout << qe.what() << endl;
				system("pause");
			}
			system("cls");
			break;
		case 6:
			cQ.clear();
			system("cls");
			break;
		case 7:
			system("cls");
			cout << "Size: " << cQ.size() << endl;
			break;
		case 8:
			system("cls");
			bin_file_work(cQ);
			break;
		case 9:
			system("cls");
			text_file_work(cQ);
			break;
		case 10:
			system("cls");
			map_menu<int, T>();
			break;
		}
	} while (x);
}
template <class key, class T>
void show_map(map<key, T>& aMap)							//Вывод контейнера
{
	typedef map<key, T> MAP;
	typedef map<key, T>::iterator it;
	char word_key[SIZE];									//Название ключа
	bool is_class;
	is_class = (typeid(T) == typeid(Tourist) || typeid(T) == typeid(Businessman));
	if (typeid(T) == typeid(Tourist))
	{
		strcpy(word_key, " passport ID");
	}
	else
	{
		if (typeid(T) == typeid(Businessman))
		{
			strcpy(word_key, " license number");
		}
		else
		{
			strcpy(word_key, " key");
		}
	}
	if (!aMap.empty())										//Если контейнер не пуст, то вывод его
	{
		it temp = aMap.begin();
		if (!is_class)										//Вывод для некласса
		{
			cout << setw(85) << typeid(T).name() << setw(20) << word_key << endl;
		}
		for (; temp != aMap.end(); temp++)
		{
			if (!is_class)
			{
				cout << setw(85) << temp->second << setw(20) << temp->first << endl;
			}
			else
			{
				cout << temp->second;
				cout << word_key <<": " << temp->first << endl;
			}
		}
	}
	else
	{
		cout << "Map is empty." << endl;
	}
}
template <class key, class T>
void IteratorMenu(map<key, T>& aMap)
{
	typedef map<key, T> MAP;
	MAP::iterator it = aMap.begin();
	int x;
	T buf_el;
	key buf_key;
	bool is_class;
	is_class = (typeid(T) == typeid(Tourist) || typeid(T) == typeid(Businessman));
	cout.setf(ios::left);
	system("cls");
	do
	{
		cout << "What do you want to do?" << endl;			//Вывод меню работы с итератором
		cout << "1 - Set iterator to the begin" << endl;
		cout << "2 - Set iterator to the end" << endl;
		cout << "3 - Show iterator's element" << endl;
		cout << "4 - iterator++" << endl;
		cout << "5 - iterator--" << endl;
		cout << "6 - Change iterator's element" << endl;
		cout << "7 - Show map from front to end" << endl;
		cout << "8 - Show map from end to front" << endl;
		cout << "9 - Set iterator to the item with key" << endl;
		cout << "0 - exit" << endl;
		cout << "Your choice: ";
		x = InputInt(cin, 0, 15);							//Ввод выбора
		switch (x)											//Вызов выбранной функции
		{
		case 1:												//Установление итератора в начало
			system("cls");
			it = aMap.begin();
			break;
		case 2:												//Установление итератора в конец
			system("cls");
			for (; it != aMap.end(); it++);
			it--;
			break;
		case 3:												//Вывод элемента итератора
			system("cls");
			try
			{
				if (!is_class)
				{
					cout << setw(85) << typeid(T).name() << setw(20) << "key" << endl;
				}
				if (!is_class)
				{
					cout << setw(85) << it->second << setw(20) << it->first << endl;
				}
				else
				{
					cout << it->second;
					cout << "key: " << it->first << endl;
				}
			}
			catch (...)
			{
				cout << "Wrong element" << endl;
			}
			break;
		case 4:												//Инкримент иетратора
			system("cls");
			it++;
			if (it == aMap.end())
			{
				cout << "You can't move there." << endl;
				it--;
			}
			break;
		case 5:												//Декремент итератора
			system("cls");
			if (it == aMap.begin())
			{ 
				cout << "You can't move there." << endl;
			}
			else
			{
				it--;
			}
			break;
		case 6:												//Изменение элемента итератора
			system("cls");
			cout << "Enter new element:" << endl;
			buf_el = SafeInput<T>();
			it->second = buf_el;
			break;
		case 7:												//Вывод с начала до конца
			system("cls");
			show_map(aMap);
			break;
		case 8:												//Вывод с конца до начала
			system("cls");
			if (!aMap.empty())
			{
				auto temp = aMap.rbegin();
				if (!is_class)
				{
					cout << setw(85) << typeid(T).name() << setw(20) << "key" << endl;
				}
				for (; temp != aMap.rend(); temp++)
				{
					if (!is_class)
					{
						cout << setw(85) << temp->second << setw(20) << temp->first << endl;
					}
					else
					{
						cout << temp->second;
						cout << "key: " << temp->first << endl;
					}
				}
			}
			else
			{
				cout << "Map is empty." << endl;
			}
			break;
		case 9:												//Поиск элемента по ключу
			system("cls");
			cout << "Enter key: ";
			buf_key = SafeInput<key>();
			if (aMap.find(buf_key) != aMap.end())
			{
				it = aMap.find(buf_key);
			}
			else
			{
				cout << "Element wasn't found." << endl;
			}
			break;
		}
	} while (x);
	system("cls");
}
template <class key, class T>
void map_menu()
{
	typedef map<key, T> MAP;
	typedef map<key, T>::iterator it;
	MAP aMap;
	char word_key[SIZE];									//Название ключа
	if (typeid(T) == typeid(Tourist))
	{
		strcpy(word_key, " passport ID");
	}
	else
	{
		if (typeid(T) == typeid(Businessman))
		{
			strcpy(word_key, " license number");
		}
		else
		{
			strcpy(word_key, " key");
		}
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
		cout << "4 - Delete element with key" << endl;
		cout << "5 - Change element with key" << endl;
		cout << "6 - Clear all" << endl;
		cout << "7 - Show size" << endl;
		cout << "8 - Work with iterator + algorithms" << endl;
		cout << "0 - exit" << endl;
		cout << "Your choice: ";
		x = InputInt(cin, 0, 8);							//Ввод выбора
		switch (x)											//Вызов соответствующей функции
		{
		case 1:												//Добавление элемента
			system("cls");
			cout << "Enter your " << typeid(T).name() << ": " << endl;
			buf_el = SafeInput<T>();
			cout << "Enter" << word_key << ": ";
			buf_key = SafeInput<key>();
			aMap.insert(make_pair(buf_key, buf_el));
			break;
		case 2:												//Вывод элемента по ключу
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
		case 3:												//Вывод map
			system("cls");
			show_map(aMap);
			break;
		case 4:												//Удаление по ключу
			system("cls");
			cout << "Enter" << word_key << ": ";
			buf_key = SafeInput<key>();
			if (aMap.find(buf_key) != aMap.end())
			{
				aMap.erase(aMap.find(buf_key));
			}
			else
			{
				cout << "Element wasn't found." << endl;
			}
			break;
		case 5:												//Изменений элемента
			system("cls");
			cout << "Enter" << word_key << ": ";
			buf_key = SafeInput<key>();
			if (aMap.find(buf_key) != aMap.end())
			{
				cout << "Enter new element." << endl;
				buf_el = SafeInput<T>();
				aMap[buf_key] = buf_el;
			}
			else
			{
				cout << "Element wasn't found." << endl;
			}
			break;
		case 6:												//Очистка map
			system("cls");
			aMap.clear();
			break;
		case 7:												//Вывод размера map
			system("cls");
			if (!aMap.empty())
			{
				cout << "Map size is " << aMap.size() << endl;
			}
			else
			{
				cout << "Map is empty" << endl;
			}
			break;
		case 8:												//Вызов функции работы с итератором
			system("cls");
			if (!aMap.empty())
			{
				IteratorMenu(aMap);
			}
			else
			{
				cout << "Map is empty." << endl;
			}
			break;
		}
	} while (x);
	system("cls");
}