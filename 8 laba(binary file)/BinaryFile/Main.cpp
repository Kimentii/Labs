//Сделать перегрузку операторов << и >> для текстового и бинарного файла
#include "BinaryFile.cpp"
#include <string>
#include "iomanip"
const char NAME[] = "C:/Users/Семен/Desktop/a.txt";
class obj
{
	char s[80];
public:
	obj(char sb[]="qwer")
	{
		strcpy(s, sb);
	}
	void show()
	{
		cout << s << endl;
	}
	friend fstream& operator << (fstream& fs, const obj& o)
	{
		fs << setw(20) << o.s << ' ';
		return fs;
	}
};
int main()
{
	system("pause");
	return 0;
}