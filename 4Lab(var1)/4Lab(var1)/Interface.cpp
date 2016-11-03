template <class T>
void menu()
{
	cQueue<T> cQ;
	T element;
	int x;
	cout.setf(ios::left);
	do
	{
		cout << "What do you want to do?" << endl;
		cout << "1 - Add element in front" << endl;
		cout << "2 - Add element in end" << endl;
		cout << "3 - Show queue" << endl;
		cout << "4 - Delete from end" << endl;
		cout << "5 - Delete from front" << endl;
		cout << "6 - Clear all" << endl;
		cout << "7 - Show size" << endl;
		cout << "0 - Exit" << endl;
		cout << "Your choice: ";
		x = InputInt(0, 7);
		switch (x)
		{
		case 1:
			cin >> element;
			system("cls");
			cQ.PushFront(element);
			break;
		case 2:
			cin >> element;
			system("cls");
			cQ.PushBack(element);
			break;
		case 3:
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
			cout << "Size: " << cQ.size() << endl;
			break;
		}
	} while (x);

}