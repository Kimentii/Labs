#include "Human.h"
#include "Businessman.h"
#include "Tourist.h"
#include "Queue.cpp"
#include "Exception.h"
#include "BinaryFile.cpp"
#include "TextFile.cpp"
#include "WorkWithFiles.cpp"
template <class T>
void menu()
{
	cQueue<T> cQ;											//Создание очереди
	BinaryFile<T> bin_file("binary");
	TextFile<cQueue<T>> text_file("text.txt");
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
			system("cls");
			bin_file_work(cQ);
			break;
		case 9:
			system("cls");
			text_file_work(cQ);
			break;
		case 10:
			system("cls");
			cQ.clear();
			try
			{
				if (text_file.empty())
				{
					throw FileExp(10, "File is empty");
				}
				if (text_file.eof())
				{
					throw end_of_file();
				}
			}
			catch (FileExp& fe)
			{
				cout << "Error number is " << fe.error() << endl;
				cout << fe.what() << endl;
			}
			text_file >> cQ;
			break;
		case 11:
			system("cls");
			cQ.clear();
			if (bin_file.is_open() && !bin_file.eof())
			{
				while (bin_file.read(&element))
				{
					cQ.PushBack(element);
				}
			}
			else
			{
				cout << "Error." << endl;
			}
			break;
		case 12:
			system("cls");
			text_file.refresh();
			break;
		case 13:
			system("cls");
			bin_file.refresh();
			break;
		}
	} while (x);
}