#include "Queue.cpp"
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
		cin >> x;											//Ввод выбора
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
			cout << *it << endl;
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
			break;
		}
	} while (x);
}
template <class T>
void menu()
{
	cQueue<T> cQ;												//Создание очереди
	T element;
	int x;
	cout.setf(ios::left);
	do
	{
		cout << "What do you want to do?" << endl;				//Вывод меню
		cout << "1 - Add element in front" << endl;
		cout << "2 - Add element in end" << endl;
		cout << "3 - Show queue" << endl;
		cout << "4 - Delete from end" << endl;
		cout << "5 - Delete from front" << endl;
		cout << "6 - Clear all" << endl;
		cout << "7 - Show size" << endl;
		cout << "8 - Work with iterator" << endl;
		cout << "0 - exit" << endl;
		cout << "Your choice: ";
		cin >> x;												//Ввод выбора
		switch (x)												//Вызов соответствующей функции
		{
		case 1:
			system("cls");
			cout << "Enter your " << typeid(T).name() << ": ";	//Вывод просьбы ввести элемент
			cin >> element;
			cQ.PushFront(element);
			break;
		case 2:
			system("cls");
			cout << "Enter your " << typeid(T).name() << ": ";	//Вывод просьбы ввести элемент
			cin >> element;
			cQ.PushBack(element);
			break;
		case 3:
			system("cls");
			cout << cQ;
			break;
		case 4:
			cQ.PopBack();
			system("cls");
			break;
		case 5:
			cQ.PopFront();
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
		}
	} while (x);
}