#pragma once
#include "Queue.cpp"
#include "BinaryFile.cpp"
#include "TextFile.cpp"
#include "SafeFunctions.h"
#include "Human.h"
template <class T>
void bin_file_work(cQueue<T>& cQ)
{
	BinaryFile<T> bin_file;
	T element;
	int x;
	char buf[SIZE];
	char* way;
	cout.setf(ios::left);
	do
	{
		bin_file.show_status();
		cout << "What do you want to do?" << endl;			//Вывод меню
		cout << "1 - Open file" << endl;
		cout << "2 - Write element in file" << endl;
		cout << "3 - Show queue" << endl;
		cout << "4 - Show file" << endl;
		cout << "5 - Read queue form file" << endl;
		cout << "6 - Write queue in file" << endl;
		cout << "7 - Close file" << endl;
		cout << "0 - exit" << endl;
		cout << "Your choice: ";
		x = InputInt(cin, 0, 20);							//Ввод выбора
		switch (x)											//Вызов соответствующей функции
		{
		case 1:
			system("cls");
			cout << "Enter name of file: " << endl;
			InputString(cin, buf, SIZE);
			way = new char[200];
			strcpy(way, "C:/Users/Семен/Desktop/Files/");
			strcat(way, buf);
			if (bin_file.open(way))
			{
				cout << "File was open." << endl;
			}
			else
			{
				cout << "File isn't open." << endl;
			}
			delete[] way;
			break;
		case 2:
			system("cls");
			if (bin_file.is_open()) bin_file.write(SafeInput<T>());
			break;
		case 3:
			system("cls");
			cout << cQ;
			break;
		case 4:
			system("cls");
			try
			{
				bin_file.show();
			}
			catch (FileExp& a)
			{
				cout << "Error number is " << a.error() << endl;
				cout << a.what() << endl;
			}
			break;
		case 5:
			system("cls");
			try
			{
				bin_file.read_queue(cQ);
			}
			catch (FileExp& a)
			{
				cout << "Error number is " << a.error() << endl;
				cout << a.what() << endl;
			}
			break;
		case 6:
			system("cls");
			if (bin_file.is_open())
			{
				for (cQueue<T>::Iterator it = cQ.begin(); it != cQ.end(); it++)
				{
					bin_file.write(*it);
				}
			}
			break;
		case 7:
			system("cls");
			bin_file.close();
			break;
		}
	} while (x);
}
template <class T>
void text_file_work(cQueue<T>& cQ)
{
	TextFile<T> text_file;
	T element;
	int x;
	char buf[SIZE];
	char* way;
	cout.setf(ios::left);
	do
	{
		text_file.show_status();
		cout << "What do you want to do?" << endl;			//Вывод меню
		cout << "1 - Open file" << endl;
		cout << "2 - Write element in file" << endl;
		cout << "3 - Show queue" << endl;
		cout << "4 - Show file" << endl;
		cout << "5 - Read queue form file" << endl;
		cout << "6 - Write queue in file" << endl;
		cout << "7 - Close file" << endl;
		cout << "0 - exit" << endl;
		cout << "Your choice: ";
		x = InputInt(cin, 0, 20);							//Ввод выбора
		switch (x)											//Вызов соответствующей функции
		{
		case 1:
			system("cls");
			cout << "Enter name of file: " << endl;
			InputString(cin, buf, SIZE);
			way = new char[200];
			strcpy(way, "C:/Users/Семен/Desktop/Files/");
			strcat(way, buf);
			if (text_file.open(way))
			{
				cout << "File was open." << endl;
			}
			else
			{
				cout << "File isn't open." << endl;
			}
			delete[] way;
			break;
		case 2:
			system("cls");
			if (text_file.is_open()) text_file << SafeInput<T>();
			break;
		case 3:
			system("cls");
			cout << cQ;
			break;
		case 4:
			system("cls");
			try
			{
				text_file.show();
			}
			catch (FileExp& a)
			{
				cout << "Error number is " << a.error() << endl;
				cout << a.what() << endl;
			}
			break;
		case 5:
			system("cls");
			cQ.clear();
			try
			{
				text_file >> cQ;
			}
			catch (FileExp& a)
			{
				cout << "Error number is " << a.error() << endl;
				cout << a.what() << endl;
			}
			break;
		case 6:
			system("cls");
			if (text_file.is_open()) text_file << cQ;
			break;
		case 7:
			system("cls");
			text_file.close();
			break;
		}
	} while (x);
}