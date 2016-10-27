#include "Queue.cpp"
int main()
{
	{
		cQueue<char> c;
		//c.clear();
		//cout << c.empty() << endl;
		//cout << c.size() << endl;
		c.push('1');
		c.push('2');
		c.push('3');
		cQueue<char>::iterator it = c.begin();
		it--;
		cout << *it << endl;
		//cQueue<char>::iterator it, it2;
		//it = c.begin();
		//cout << *it << endl;
		//it2 = it = it++;
		//cout << *it2 << endl;
		//c.clear();
		//cout << c.empty() << endl;
		//cout << c.size() << endl;
		//cout << c.Pull() << endl;
		//cout << c.Pull() << endl;
		//cout << c.Pull() << endl;
		//cout << c.Pull() << endl;
		//c.Push('1');
		//c.Push('2');
		//c.Push('3');
		//cout << c.Pull() << endl;
		//cout << c.pull();
		//cout << c.pull() << c.pull() << endl;
	}
	system("pause");
	return 0;
}