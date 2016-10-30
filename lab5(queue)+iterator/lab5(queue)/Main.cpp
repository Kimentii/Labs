#include "Queue.cpp"
int main()
{
	{
		cQueue<char> c(5);
		cout << c;
		//c.PushBack('1');
		//c.PushBack('2');
		//c.PushBack('3');
		cin >> c;
		cout << c;
		//c.show();
		//cQueue<char>::Iterator it = c.begin();
		//++it;
		//--it;
		//cout << *it << endl;
		//cout << *it << endl;
	}
	system("pause");
	return 0;
}