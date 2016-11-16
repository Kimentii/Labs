#include "Queue.cpp"
#include "Exception.h"
#include "SafeFunctions.h"
template <class T>
void IteratorMenu(cQueue<T>& cQ)
{
	cQueue<T>::Iterator it;
	int x;
	cout.setf(ios::left);
	system("cls");
	do
	{
		cout << "What do you want to do?" << endl;			//Вывод меню работы с итератором
		cout << "1 - Set iterator to the front" << endl;
		cout << "2 - Set iterator to the end" << endl;
		cout << "3 - iterator++" << endl;
		cout << "4 - iterator--" << endl;
		cout << "5 - Show iterator's element" << endl;
		cout << "6 - Show queue from front to end" << endl;
		cout << "7 - Show queue from end to front" << endl;
		cout << "0 - exit" << endl;
		cout << "Your choice: ";
		x = InputInt(cin, 0, 7);							//Ввод выбора
		switch (x)											//Вызов выбранной функции
		{
		case 1:
			system("cls");
			it = cQ.begin();
			break;
		case 2:
			system("cls");
			it = cQ.rbegin();
			break;
		case 3:
			it++;
			system("cls");
			break;
		case 4:
			it--;
			system("cls");
			break;
		case 5:
			system("cls");
			try
			{
				cout << *it << endl;
			}
			catch (wrong_element& we)
			{
				cout << "Error number is " << we.error() << endl;
				cout << we.what() << endl;
			}
			break;
		case 6:
			system("cls");
			cout << "Queue:" << endl;
			for (cQueue<T>::Iterator it2 = cQ.begin(); it2 != cQ.end(); it2++)
			{
				cout << *it2 << endl;
			}
			break;
		case 7:
			system("cls");
			cout << "Queue:" << endl;
			for (cQueue<T>::Iterator it2 = cQ.rbegin(); it2 != cQ.rend(); it2--)
			{
				cout << *it2 << endl;
			}
			break;
		}
	} while (x);
}
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
		cout << "8 - Work with iterator" << endl;
		cout << "9 - Show element with number n" << endl;
		cout << "0 - exit" << endl;
		cout << "Your choice: ";
		x = InputInt(cin, 0, 9);							//Ввод выбора
		switch (x)											//Вызов соответствующей функции
		{
		case 1:
			system("cls");
			cQ.PushFront(SafeInput<T>());
			break;
		case 2:
			system("cls");
			cQ.PushBack(SafeInput<T>());
			break;
		case 3:
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
			IteratorMenu(cQ);
			break;
		case 9:
			system("cls");
			int z;
			cout << "Enter number of element: ";
			z = InputInt(cin, 0);
			try
			{
				cout << cQ[z] << endl;
			}
			catch (wrong_element& we)
			{
				cout << "Erroe number is " << we.error() << endl;
				cout << we.what() << endl;
			}
		}
	} while (x);
}