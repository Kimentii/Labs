#include "Human.h"
#include "Businessman.h"
#include "Tourist.h"
#include "TourBisn.h"
#include "Queue.cpp"
#include "Exception.h"
#include "Algorithm.cpp"
template <class T>
void StructMenu(T& el)
{
	cout << "You can't work with this element." << endl;
}
void StructMenu(Human& el);
//void StructMenu(TourBisn& el)
//{
//	char s[SIZE];
//	int x;
//	cout.setf(ios::left);
//	system("cls");
//	do
//	{
//		cout << "What do you want to do?" << endl;
//		cout << "1 - Show struct" << endl;
//		cout << "2 - Change name" << endl;
//		cout << "3 - Change surname" << endl;
//		cout << "4 - Change middle name" << endl;
//		if (!strcmp(typeid(el).name(), "Businessman"))
//		{
//			cout << "5 - Change license number" << endl;
//		}
//		if (!strcmp(typeid(el).name(), "Tourist"))
//		{
//			cout << "5 - Change passport ID" << endl;
//		}
//		if (!strcmp(typeid(el).name(), "TourBisn"))
//		{
//			cout << "5 - Change license number" << endl;
//			cout << "6 - Change passport ID" << endl;
//			cout << "7 - Add address" << endl;
//			cout << "8 - Delete address" << endl;
//		}
//		cout << "0 - exit" << endl;
//		cout << "Your choice: ";
//		x = InputInt(cin, 0, 8);
//		switch (x)
//		{
//		case 1:
//			system("cls");
//			cout << el << endl;
//			break;
//		case 2:
//			system("cls");
//			cout << "Enter new name: ";
//			InputString(cin, s, SIZE);
//			el.SetName(s);
//			break;
//		case 3:
//			system("cls");
//			break;
//		case 4:
//			break;
//		case 5:
//			break;
//		case 6:
//			break;
//		}
//	} while (x);
//}
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
		cout << "3 - Show iterator's element" << endl;
		cout << "4 - iterator++" << endl;
		cout << "5 - iterator--" << endl;
		cout << "6 - Show queue from front to end" << endl;
		cout << "7 - Show queue from end to front" << endl;
		cout << "8 - Sort queue" << endl;
		cout << "9 - Shuffle queue" << endl;
		cout << "10 - Fill queue's elements by element" << endl;
		cout << "11 - Set iterator to the min element" << endl;
		cout << "12 - Set iterator to the max element" << endl;
		cout << "13 - Set iterator to the item found" << endl;
		cout << "14 - Count number of elements with value" << endl;
		cout << "15 - Work with element" << endl;
		cout << "0 - exit" << endl;
		cout << "Your choice: ";
		x = InputInt(cin, 0, 15);							//Ввод выбора
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
		case 4:
			it++;
			system("cls");
			break;
		case 5:
			it--;
			system("cls");
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
		case 8:
			Sort(cQ.begin(), cQ.end());
			system("cls");
			break;
		case 9:
			Random_Shuffle(cQ.begin(), cQ.end());
			system("cls");
			break;
		case 10:
			system("cls");
			Fill(cQ.begin(), cQ.end(), SafeInput<T>());
			break;
		case 11:
			system("cls");
			it = min_element(cQ.begin(), cQ.end());
			break;
		case 12:
			system("cls");
			it = max_element(cQ.begin(), cQ.end());
			break;
		case 13:
			system("cls");
			it = Find(cQ.begin(), cQ.end(), SafeInput<T>());
			break;
		case 14:
			system("cls");
			cout << "There are " << Count(cQ.begin(), cQ.end(), SafeInput<T>()) << " elements" << endl;
			break;
		case 15:
			StructMenu(*it);
			system("cls");
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
		cout << "8 - Work with iterator + algorithms" << endl;
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